#include <stdio.h>
#include <stdlib.h>
#include "console.h"

void NotPlaying(){
    (&current)->penyanyi = "-";
    (&current)->album = "-";
    (&current)->lagu = "-";
}

void NotPlayingPlaylist(){
    currentIDplay = -1;
}

boolean isNotPlayingPlaylist(){
    return currentIDplay == -1;
}

boolean isNotPlaying (){
    return current.penyanyi == "-" && 
    current.album == "-" && 
    current.lagu == "-";
}

// Fungsi Start
status current;
int currentIDplay;
void STARTREAD(ListPenyanyi * LP, SetLagu *lagu2,MapAlbum *m2,ListDinamik *daftarplaylist, char NamaFile []){
  startWFile(NamaFile);
  //MapAlbum mapAl;
  Word NamaPenyanyi;
  Word NamaAlbum;
  Word NamaLagu;
  int panjg;
  CreateMapAlbum(&*m2);
  NotPlaying();
  NotPlayingPlaylist();
  ListDinamik DaftarPlaylist = CreateLD();


  CreateEmptySetLagu(&*lagu2);
  *LP = MakeListPenyanyi();
  //CreateMapAlbum(&mapAl);
  


  
  int loop = wordToInt(currentWord);
  int album,lagu;
  int number =1;
  int idalbum=1;
  printf("\n");
  printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan\n");
  for (int i = 0; i < loop; i++){
    ADVSATUKATA();
    album = currentWord.TabWord[0] - 48;   
    ADVKALIMAT();  
    InsertLast(&*LP, currentWord);
    for (int j = 0; j < album; j++){
      ADVSATUKATA();
      lagu = currentWord.TabWord[0] - 48;
      ADVKALIMAT();
      InsertMapAlbum(&*m2,i,currentWord);
      for (int k = 0; k < lagu; k++)
      {
        ADVKALIMAT();
        InsertSetLagu(&*lagu2,currentWord,number);    
      }
      number++;
    }
    idalbum++;
  }
  printf("\n");
}


//IMPLEMENTASI FUNGSI PLAYLIST

void CreatePlayList(ListDinamik *DaftarPlaylist) {
    printf("\n");
    printf("Masukkan nama playlist yang ingin dibuat : ");
    STARTCOMMAND();  
    int i = 0;
    int count = 0;
    while (currentCommand.Length > i) {
        if (currentCommand.TabWord[i] != ' ') {
            count++;
        }
        i++;
    }
    if (count >= 3) {
        // Menambahkan playlist baru ke ListDinamik
        InsertLD(DaftarPlaylist, currentCommand, DaftarPlaylist->Neff);
        CreateSB(&DaftarPlaylist->Content[DaftarPlaylist->Neff-1]);
        // Display output
        printf("\n");
        printf("Playlist ");
        displayWord(currentCommand);
        printf(" berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n");   
    }
    else {
        printf("\n");
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
    }
}   

void PLAYLISTADDSONG(ListPenyanyi lp, MapAlbum m2,SetLagu S ,ListDinamik *daftarplaylist) {
    printf("Daftar Penyanyi:\n");
    DisplayListPenyanyi(lp);
    printf("\n");

    printf("Masukkan Nama Penyanyi: ");
    STARTCOMMAND();
    if(!isMemberListPenyanyi(currentCommand,lp)){
        printf("Nama Penyanyi  ");
        displayWord(currentCommand);
        printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        return;
    }
    Word penyanyitemp ;
    CreateWord2(currentCommand.Length,currentCommand.TabWord,&penyanyitemp);

    char *comm=wordToString(currentCommand);
    int idxpenyanyi=albumtoidpenyanyi(lp,currentCommand);

    printf("\n");
    printf("Daftar Album oleh %s:\n",comm);
    displayMapAlbum(m2,idxpenyanyi);

    printf("\n");
    printf("Masukkan Nama Album yang dipilih: ");
    STARTCOMMAND();
    Word albumtemp;
    CreateWord2(currentCommand.Length,currentCommand.TabWord,&albumtemp);
    if (!IsMemberMapAlbum(m2,currentCommand)){
        printf("Album ");
        displayWord(currentCommand);
        printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        return;
    }
    char *comm1=wordToString(currentCommand);
    int idxalbum=laguAlbumID(currentCommand,m2);
    printf("\n");
    printf("Daftar Lagu Album %s oleh %s : \n",comm1,comm);
    DisplaySetLagu(S,idxalbum);
    int countlagu = CountLaguByAlbumID(&S,idxalbum);
    printf("\n");
    printf("Masukkan ID Lagu yang dipilih: ");
    STARTCOMMAND();
    int idxlagu=wordToInt(currentCommand);
    if((idxlagu<=0) || (idxlagu > countlagu)){
        printf("ID lagu tidak valid\n");
        return;
    }
    Word namalagu=namalagufromalbum(S,idxalbum,idxlagu);
    printf("\n");
    printf("Daftar Playlist Pengguna :\n");
    DisplayLD(*daftarplaylist);
    printf("\n");

    // Meminta input ID Playlist
    printf("Masukkan ID Playlist yang dipilih : ");
    STARTCOMMAND(); // Mulai membaca kata
    printf("\n");
    int id_playlist = wordToInt(currentCommand) - 1;

    if(IsIdxValidLD(*daftarplaylist,id_playlist)){
        Word playlist;
        Detail d;
        PasteWord(Title(daftarplaylist->Content[id_playlist]), &playlist);      
        CreateD(&d, penyanyitemp, albumtemp, namalagu);
        // insert ke linkedlist
        InsertSB(&daftarplaylist->Content[id_playlist], d, LengthSB(daftarplaylist->Content[id_playlist]));;        
        printf("Lagu dengan judul \"");
        displayWord(namalagu);
        printf("\" pada album ");
        displayWord(albumtemp);
        printf(" oleh penyanyi \n");
        displayWord(penyanyitemp);
        printf(" berhasil ditambahkan ke dalam playlist ");
        displayWord(playlist);
        printf(".\n"); 
    }
    else {
        printf("ID Playlist %d tidak ada dalam daftar. Silakan coba lagi.\n", id_playlist + 1);
        return;
    }
}

void PLAYLISTADDALBUM(ListPenyanyi lp, MapAlbum m2,SetLagu S ,ListDinamik *daftarplaylist) {
    printf("Daftar Penyanyi:\n");
    DisplayListPenyanyi(lp);
    printf("\n");

    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTCOMMAND();
    if(!isMemberListPenyanyi(currentCommand,lp)){
        printf("Nama Penyanyi  ");
        displayWord(currentCommand);
        printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        return;
    }
    Word penyanyitemp ;
    CreateWord2(currentCommand.Length,currentCommand.TabWord,&penyanyitemp);

    char *comm=wordToString(currentCommand);
    int idxpenyanyi=albumtoidpenyanyi(lp,currentCommand);

    printf("\n");
    printf("Daftar Album oleh %s:\n",comm);
    displayMapAlbum(m2,idxpenyanyi);

    printf("\n");
    printf("Masukkan Judul Album yang dipilih: ");
    STARTCOMMAND();
    Word albumtemp;
    CreateWord2(currentCommand.Length,currentCommand.TabWord,&albumtemp);
    if (!IsMemberMapAlbum(m2,currentCommand)){
        printf("Album ");
        displayWord(currentCommand);
        printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        return;
    }
    char *comm1=wordToString(currentCommand);
    int idxalbum=laguAlbumID(currentCommand,m2);
    printf("\n");
    printf("Daftar Playlist Pengguna :\n");
    DisplayLD(*daftarplaylist);
    printf("\n");

    // Meminta input ID Playlist
    printf("Masukkan ID Playlist yang dipilih : ");
    STARTCOMMAND(); // Mulai membaca kata
    printf("\n");
    int id_playlist = wordToInt(currentCommand) - 1;
    if (IsIdxValidLD(*daftarplaylist, id_playlist)) {
        Word playlist;
        Detail d;
        PasteWord(Title(daftarplaylist->Content[id_playlist]), &playlist);
        Word lagu;
        for (int i=1;i<=(CountLaguByAlbumID(&S,idxalbum));i++){
            Word check = namalagufromalbum(S,idxalbum,i);
            PasteWord(check, &lagu);
            CreateD(&d, penyanyitemp, albumtemp, lagu);
            InsertSB(&daftarplaylist->Content[id_playlist], d, LengthSB(daftarplaylist->Content[id_playlist]));
        }
        
        printf("Album dengan judul \"");
        displayWord(albumtemp);
        printf("\" berhasil ditambahkan ke dalam playlist pengguna \"");
        displayWord(playlist);
        printf("\".\n");
    }
    else {
        printf("ID Playlist %d tidak ada dalam daftar. Silakan coba lagi.\n", id_playlist + 1);
    }
}

void PLAYLISTSWAP(ListDinamik *DaftarPlaylist){
    // Mengambil idP, id1, id2 dari Current Command
    printf("\n");
    int i = 14;
    int idP,id1,id2;
    while ((currentCommand.TabWord[i]!= BLANK) && (currentCommand.TabWord[i]!= ENTER)){
        idP = currentCommand.TabWord[i] - '0';
        i++;
    }
    i++;
    while ((currentCommand.TabWord[i]!= BLANK) && (currentCommand.TabWord[i]!= ENTER)){
        id1 = currentCommand.TabWord[i] - '0';
        i++;
    }
    i++;
    while ((currentCommand.TabWord[i]!= BLANK)&& (currentCommand.TabWord[i]!= '\0')){
        id2 = currentCommand.TabWord[i] - '0';
        i++;
    }
    idP = idP -1;
    id1 = id1 -1;
    id2 = id2 -1;

    // Memulai fungsi swap playlist
        if (idP < 0 || idP >= DaftarPlaylist->Neff) {
        printf("Tidak ada playlist dengan playlist ID %d\n", idP+1);
        return;
    }
    else {
        LinkedList playlist = DaftarPlaylist->Content[idP];
        
        if (id1 < 0 || id1 >= LengthSB(playlist) || id2 < 0 || id2 >= LengthSB(playlist)) {
            printf("Tidak ada lagu dengan urutan %d atau %d di playlist\n", id1+1, id2+1);
        }
        else {
            // Menukar lagu pada urutan x dan y
            Detail tempx, tempy;
            GetSB(&(DaftarPlaylist->Content[idP]), &tempx, id1);
            GetSB(&(DaftarPlaylist->Content[idP]), &tempy, id2);
            SetSB(&(DaftarPlaylist->Content[idP]), tempy, id1);
            SetSB(&(DaftarPlaylist->Content[idP]), tempx, id2);

            printf("Berhasil menukar lagu dengan nama \"");
            displayWord(tempx.Lagu);
            printf("\" dengan \"");
            displayWord(tempy.Lagu);
            printf("\" di playlist \"");
            displayWord(Title(DaftarPlaylist->Content[idP]));
            printf("\".\n");
        }
    }
}

void PLAYLISTREMOVE(ListDinamik *DaftarPlaylist) {
    displayWordNewLine(currentCommand);
    int index, urutan;
    int i = 16;
    while ((currentCommand.TabWord[i]!= BLANK) && (currentCommand.TabWord[i]!= ENTER)){
        index = currentCommand.TabWord[i] - '0';
        i++;
    }
    i++;
    while ((currentCommand.TabWord[i]!= BLANK) && (currentCommand.TabWord[i]!= '\0')){
        urutan = currentCommand.TabWord[i] - '0';
        i++;
    }
    index = index -1;
    urutan = urutan-1;
    if (index < 0 || index >= DaftarPlaylist->Neff) {
        printf("Tidak ada playlist dengan playlist ID %d\n", index+1);
    }
    else {
        LinkedList playlist = DaftarPlaylist->Content[index];
        if (urutan < 0 || urutan >= LengthSB(playlist)) {
            printf("Tidak ada lagu dengan urutan %d di playlist\n", urutan+1);
        }
        else {
            Detail x;
            DisplaySB(playlist);
            DeleteSB(&DaftarPlaylist->Content[index], &x, urutan);

            printf("Lagu \"");
            displayWord(x.Lagu);
            printf("\" oleh \"");
            displayWord(x.Penyanyi);
            printf("\" telah dihapus dari playlist \"");
            displayWord(Title(playlist));
            printf("\" !\n");
        }
    }
}

void PLAYLISTDELETE(ListDinamik *DaftarPlaylist) {
    printf("Daftar Playlist Pengguna :\n");
    DisplayLD(*DaftarPlaylist);
    printf("\n");
    // Tampilkan daftar playlist
    // ...

    printf("Masukkan ID Playlist yang dipilih : ");
    STARTCOMMAND(); // Mulai membaca kata
    printf("\n");
    int id_playlist = wordToInt(currentCommand) - 1;
    ; // Mengubah Word ke integer

    if (id_playlist < 0 || id_playlist >= DaftarPlaylist->Neff) {
        printf("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.\n", id_playlist+1);
    }
    else {
        // Hapus playlist dengan ID yang diberikan
        ElType playlist;
        playlist = GetLD(*DaftarPlaylist, id_playlist);
        DeleteAtListDin(&*DaftarPlaylist, id_playlist);
        printf("Playlist ID %d dengan judul \"", id_playlist+1);
        displayWord(playlist);
        printf("\" berhasil dihapus.\n");
    }
    
}

// IMPLEMENTASI FUNGSI QUEUE



void QueSong(ListPenyanyi lp, MapAlbum m2,SetLagu S ,QueueLagu *Ql) {
    printf("Daftar Penyanyi:\n");
    DisplayListPenyanyi(lp);

    printf("Masukkan Nama Penyanyi: ");
    STARTCOMMAND();
    char *comm=wordToString(currentCommand);
    int idxpenyanyi=albumtoidpenyanyi(lp,currentCommand);
    if (!isMemberListPenyanyi(currentCommand,lp)){
        printf("Nama Penyanyi tersebut tidak valid\n");
        return;
    }

    printf("Daftar Album oleh %s:\n",comm);
    displayMapAlbum(m2,idxpenyanyi);

    printf("Masukkan Nama Album yang dipilih: ");
    STARTCOMMAND();
    if (!IsMemberMapAlbum(m2,currentCommand)){
        printf("Nama Album tersebut tidak valid\n");
        return;
    }
    char *comm1=wordToString(currentCommand);
    int idxalbum=laguAlbumID(currentCommand,m2);
    
    printf("Daftar Lagu Album %s oleh %s : \n",comm1,comm);
    DisplaySetLagu(S,idxalbum);
    int countlagu = CountLaguByAlbumID(&S,idxalbum);

    printf("Masukkan ID Lagu yang dipilih: ");
    STARTCOMMAND();
    int idxlagu=wordToInt(currentCommand);
    if((idxlagu<=0) || (idxlagu > countlagu)){
        printf("ID lagu tidak valid\n");
        return;
    }
    Word namalagu=namalagufromalbum(S,idxalbum,idxlagu);
    char *comm3=wordToString(namalagu);
    if (CIsFull(*Ql)){
        printf("Queue Lagu Penuh!\n");
    }else{
        printf("Berhasil masuk\n");
        Cenqueue(Ql,comm,comm1,comm3);
        printf("Berhasil menambahkan lagu %s oleh %s ke queue.\n",comm3, comm);
    }CdisplayQueue(*Ql);
}


/*
void QueList(ListD list_dinamis, QueueLagu *Ql) {
    printf("Masukkan ID PlayList : ");
    STARTCOMMAND();
    int x = wordToInt(currentCommand);

    if (x >= list_dinamis.NEff) {
        printf("Queue Playlist gagal. ID Playlist tidak ditemukan!\n");
    } else {
        listBerkait ply = list_dinamis.A[x];
        address P = First(ply);
        while (P != NULL) {
            Cenqueue(Ql,P->infoplaylist.Penyanyi_playlist, P->infoplaylist.album_playlist,P->infoplaylist.lagu_playlist);
            P=Next(P);
        }printf("Berhasil menambahkan playlist %s ke queue.\n", ply.NamaPlaylist);
    }
}*/
    

/*I.S. List Pada Playlist sudah terdefinisi*/
/*F.S. Memasukkan lagu pada playlist yang dipilih ke dalam antrian */

void QueSwap(QueueLagu *q) {
    QueueLagu Qtemp;
    char *penyanyi1, *album1, *lagu1;
    char *penyanyi2, *album2, *lagu2;
    char *Penyanyitemp, *albumtemp, *lagutemp;
    CCreateQueue(&Qtemp);

    STARTCOMMAND();
    int x = wordToInt(currentCommand);
    STARTCOMMAND();
    int y = wordToInt(currentCommand);
    if (x > CLength(*q) || y > CLength(*q)) {
        if (x > CLength(*q)) {
            printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", x);
        } else if( y > CLength(*q)) {
            printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", y);
        }
    } else {
        int i = 1;
        while (!CIsEmpty(*q)) {
            Cdequeue(q, &Penyanyitemp, &albumtemp, &lagutemp);
            if (i == x) {
                penyanyi1 = Penyanyitemp;
                album1 = albumtemp;
                lagu1 = lagutemp;
            }

            if (i == y) {
                penyanyi2 = Penyanyitemp;
                album2 = albumtemp;
                lagu2 = lagutemp;
            }

            Cenqueue(&Qtemp, Penyanyitemp, albumtemp, lagutemp);
            i++;
        }

        int j = 1;
        while (!CIsEmpty(Qtemp)) {
            Cdequeue(&Qtemp, &Penyanyitemp, &albumtemp, &lagutemp);
            if (j == x) {
                Penyanyitemp = penyanyi2;
                albumtemp = album2;
                lagutemp = lagu2;
            }
            if (j == y) {
                Penyanyitemp = penyanyi1;
                albumtemp = album1;
                lagutemp = lagu1;
            }
            Cenqueue(q, Penyanyitemp, albumtemp, lagutemp);
            j++;
        }printf("Lagu %s berhasil ditukar dengan %s \n",lagu1,lagu2);
    }
}

/*I.S. Antrian pada lagu sudah terdefinisi */
/*F.S. Melakukan pertukaran lagu pada queue */
void QueMove(QueueLagu *Q){
    QueueLagu Qtemp;
    CCreateQueue(&Qtemp);
    char *Penyanyitemp, *albumtemp, *lagutemp;
    char *Penyanyitemp1, *albumtemp1, *lagutemp1;
    STARTCOMMAND();
    int x = wordToInt(currentCommand);
    
    if (x > CLength(*Q)) {
        printf("Lagu dengan urutan ke %d tidak ada.\n", x);
    } else {
        int i = 0;
        while (!CIsEmpty(*Q)) {
            Cdequeue(Q, &Penyanyitemp, &albumtemp, &lagutemp);
            if (i + 1 != x) {
                Cenqueue(&Qtemp, Penyanyitemp, albumtemp, lagutemp);
            }else{
                Penyanyitemp1=Penyanyitemp;
                albumtemp1=albumtemp;
                lagutemp1=lagutemp;
            }
            i++;
        }printf("Lagu %s oleh %s telah dihapus dari queue!\n",lagutemp1,Penyanyitemp1);
        *Q = Qtemp;
    }
    
    CdisplayQueue(*Q);
}

/*I.S. Antrian pada lagu sudah terdefinisi */
/*F.S. Menghapus Que pada urutan tertentu*/

void QueClear(QueueLagu *Q) {
    char *Penyanyitemp,*albumtemp,*lagutemp;
    while (!CIsEmpty(*Q)) {
        Cdequeue(Q,&Penyanyitemp,&albumtemp,&lagutemp);
    }printf("Queue berhasil dikosongkan\n");
}

/*I.S. Antrian pada lagu sudah terdefinisi */
/*F.S. Menghapus semua lagu pada queue*/    
void SongNext(HistoriLagu *HS, QueueLagu *Q){
    if(isNotPlaying() && CIsEmpty(*Q)){
        printf("Queue kosong dan tidak ada lagu yang sedang dimainkan\n");
    }else if(CIsEmpty(*Q)) {
        printf("Queue kosong, memutar kembali lagu\n");
        printf("\"%s\" oleh \"%s\"",current.lagu,current.penyanyi);
    }else{
        printf("%s\n",current.penyanyi);
        printf("%s\n",current.album);
        printf("%s\n",current.lagu);
        printf("%d\n",isNotPlaying());
        if(!isNotPlaying()){
            printf("%s\n",current.penyanyi);
            printf("%s\n",current.album);
            printf("%s\n",current.lagu);
            PushLagu(HS,current.lagu,current.album,current.penyanyi);
        }
        Cdequeue(Q,&current.lagu,&current.album,&current.penyanyi);
        printf("Memutar lagu selanjutnya\n");
        printf("\"%s\" oleh \"%s\"\n",current.penyanyi,current.lagu);
    }
}

/*I.S. Antrian pada lagu sudah terdefinisi  */
/*F.S. Jika keadaan belum memutar lagu tetapi sudah ada que maka akan memuta lagu pada que, Jika sedang memutar lagu 
maka lagu akan dimasukkan pada History Lagu dan memutar lagu pada queue*/
void SongPrev(HistoriLagu *HS,QueueLagu *Q){
    QueueLagu Qtemp;
    char *lagutemp,*albumtemp,*penyanyitemp;
    CCreateQueue(&Qtemp);
     if (isNotPlaying() && IsHistEmpty (*HS)){
        printf("\nRiwayat lagu kosong dan tidak ada lagu yang sedang dimainkan\n");
    }else if(IsHistEmpty(*HS)){
        printf("History kosong, memutar kembali lagu\n");
        printf("\"%s\" oleh \"%s\"\n",current.penyanyi,current.lagu);
    }else{
        if(!isNotPlaying()){
            Cenqueue(&Qtemp,current.penyanyi,current.album,current.lagu);
        }
        while(!CIsEmpty(*Q)){
            Cdequeue(Q,&penyanyitemp,&albumtemp,&lagutemp);
            Cenqueue(&Qtemp,penyanyitemp,albumtemp,lagutemp);
        }while(CIsEmpty(Qtemp)){
            Cdequeue(&Qtemp,&penyanyitemp,&albumtemp,&lagutemp);
            Cenqueue(Q,penyanyitemp,albumtemp,lagutemp);
        }PopLagu(HS,&(current).lagu,&(current).album,&(current).penyanyi);
        printf("Memutar lagu sebelumnya\n");
        printf("\"%s\" oleh \"%s\"\n", current.penyanyi, current.lagu);
    }
}
/*I.S. History  pada lagu sudah terdefinisi  */
/*F.S Memutar lagu pada history lagu, jika belum ada dan baru memutar laguu yang diputar maka lagu 
lagu yang sedang diputar*/

void save (ListPenyanyi p,MapAlbum al ,SetLagu lg, QueueLagu QL, HistoriLagu HL, ListDinamik LD){
    FILE* input = fopen("./save/test.txt", "w+");
    fprintf(input, "%d\n", p.NEff);
    int counter=1;
    int counter2=0;
    for (int i = 0; i < p.NEff; i++){
        int jumlahalbumperpenyanyi2 = jumlahalbumperpenyanyi(al,i);
        fprintf(input,"%d ", jumlahalbumperpenyanyi2);
        for (int a=0;a<p.A[i].Length;a++){
            if (a<p.A[i].Length-1){
                fprintf(input,"%c",p.A[i].TabWord[a]);      
            }
            else{
                fprintf(input,"%c\n",p.A[i].TabWord[a]);   
            }
        }
        for (int j = 0;j<jumlahalbumperpenyanyi2;j++){
            int jumlahlagu = CountLaguByAlbumID(&lg,counter);
            fprintf(input, "%d ", jumlahlagu);
            for (int b=0 ; b<al.Elements[counter].nama_album.Length;b++){
                if (b<al.Elements[counter].nama_album.Length-1){
                    fprintf(input,"%c",al.Elements[counter].nama_album.TabWord[b]);      
                }
                else{
                    fprintf(input,"%c\n",al.Elements[counter].nama_album.TabWord[b]);   
                }
            }
            counter++;
            for (int k=0;k<jumlahlagu;k++){
                counter2++;
                for (int c=0 ; c<lg.A[counter2].nama_lagu.Length;c++){
                    if (c<lg.A[counter2].nama_lagu.Length-1){
                        fprintf(input,"%c",lg.A[counter2].nama_lagu.TabWord[c]);      
                    }
                    else{
                        fprintf(input,"%c\n",lg.A[counter2].nama_lagu.TabWord[c]);   
                    }
                }
            }
        }
    }
    char* CekEmpty = "-";
    if (StrComp(current.penyanyi,CekEmpty)) fprintf(input, "-\n");
    else fprintf(input, "%s;%s;%s\n", current.penyanyi, current.album, current.lagu);
    if (!CIsEmpty(QL)){
        fprintf(input,"%d\n",CLength(QL));
        for (int i = 0; i < CLength(QL); i++) fprintf(input,"%s;%s;%s\n", QL.Isi[i].Penyanyi_playlist, QL.Isi[i].album_playlist, QL.Isi[i].lagu_playlist);
    }
    
    if(!IsHistEmpty(HL)){
        fprintf(input,"%d\n",HL.idxTop+1);
        for (int i = HL.idxTop; i>=0; i--){
            fprintf(input,"%s;%s;%s\n", HL.hist_lagu[i].Penyanyi_playlist, HL.hist_lagu[i].album_playlist, HL.hist_lagu[i].lagu_playlist);
        }
    }
    if(LD.Neff != 0){
        fprintf(input,"%d\n",LD.Neff);
        for (int i = 0; i < LD.Neff; i++){
            int JumlahLagu = LengthSB(LD.Content[i]);
            fprintf(input,"%d %s\n", JumlahLagu, wordToString(LD.Content[i].Title));

            Address Lagu = (LD.Content[i]).First;
            for (int j=0; j<JumlahLagu; j++){
                fprintf(input, "%s;%s;%s\n", wordToString(Lagu->Info.Penyanyi), wordToString(Lagu->Info.Album), wordToString(Lagu->Info.Lagu));
                Lagu = Lagu->Next;
            }
        }
    }
    fclose(input);
    printf("Save file berhasil disimpan.\n");
    printf("// File disimpan pada /save/savefile.txt\n");
    
}


void QUIT (ListPenyanyi p,MapAlbum al ,SetLagu lg, QueueLagu QL, HistoriLagu HL, ListDinamik LD){
    printf("Apakah kamu ingin menyimpan data sesi sekarang? ");
    STARTCOMMAND();
    if (currentCommand.TabWord[0] == 'Y') {
        printf("Masukkan nama file untuk penyimpanan: ");
        STARTCOMMAND();

        Word file;
        file.Length = currentCommand.Length;

        for (int i=0; i<currentCommand.Length; i++){
            file.TabWord[i] = currentWord.TabWord[i];
        }

        save(p,al,lg,QL,HL,LD);
        printf ("Data berhasil disimpan.\n");
        printf ("Kamu keluar dari WayangWave.\n");
        printf ("Dadah ^_^/\n");
    } else {
        printf ("Kamu keluar dari WayangWave.\n");
        printf ("Dadah ^_^/\n");
    }
}
void help(boolean start){
    if (start == false) {
        printf ("=====[ Menu Help WayangWave ]=====\n");
        printf ("1. START -> Untuk masuk sesi baru\n");
        printf ("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    }
    else {
        printf ("=====[ Menu Help WayangWave ]=====\n");
        printf ("1. LIST DEFAULT -> Untuk menampilkan daftar penyanyi, album, dan lagu default\n");
        printf ("2. LIST PLAYLIST -> Untuk menampilkan playlist yang ada pada pengguna\n");
        printf ("3. PLAY SONG -> Memutar lagu sesuai yang dipilih dan dimasukkan ke dalam history\n");
        printf ("4. PLAY PLAYLIST -> Memainkan lagu berdasarkan id playlist\n");
        printf ("5. QUEUE SONG -> Memasukkan lagu yang dipilih ke dalam antrian\n");
        printf ("6. QUEUE PLAYLIST -> Menambahkan lagu yang ada dalam playlist ke dalam queue\n");
        printf ("7. QUEUE SWAP -> Melakukan pertukaran lagu pada queue\n");
        printf ("8. QUEUE REMOVE <id> -> Menghapus Que pada urutan tertentu\n");
        printf ("9. QUEUE CLEAR -> Menghapus semua lagu pada queue\n");
        printf ("10. SONG NEXT -> Memutar lagu dari dalam antrian dan menambahkannya ke dalam riwayat pemutaran jika antrian tidak kosong; jika antrian kosong, lagu yang sedang diputar akan terus diputar.\n");
        printf ("11. SONG PREVIOUS -> Memutar lagu pada history lagu, jika belum ada dan baru memutar laguu yang diputar maka lagu lagu yang sedang diputar\n");
        printf ("12. PLAYLIST CREATE -> Tercipta satu playlist\n");
        printf ("13. PLAYLIST ADD SONG -> Menambahkan lagu pada playlist tertentu\n");
        printf ("14. PLAYLIST ADD ALBUM -> Menambahkan semua lagu pada album ke playlist\n");
        printf ("15. PLAYLIST SWAP <id> <x> <y> -> Menukar lagu pada playlist tertentu\n");
        printf ("16. PLAYLIST REMOVE <id> <n> -> Menghapus lagu pada playlist tertentu\n");
        printf ("17. PLAYLIST DELETE -> Menghapus Playlist\n");
        printf ("18. STATUS -> Mengeluarkan output status pemutaran lagu\n");
        printf ("19. HELP -> Mengembalikan output berupa daftar command yang dapat dimasukkan berikut fungsinya\n");
        printf ("20. SAVE -> Menyimpan Array dalam file eksternal\n");
        printf ("21. QUIT -> Keluar dari sesi\n");
    }
}

void invalidCommand(Word* w) {
    while (!EndWord) {
        ADVCOMMAND();
    }
    printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
}


void statuscurrent(QueueLagu Q,ListDinamik LD){
    if(isNotPlayingPlaylist()){
        printf("\n");
    }else{
        printf("Current Playlist : %s \n",LD.Content[currentIDplay-1].Title.TabWord);
    }
    printf("Now Playing:\n");
    if(!isNotPlaying()){
        printf("%s - %s - %s\n",current.penyanyi,current.album,current.lagu);   
    }else{
        printf("No songs have been played yet. Please search for a song to begin playback.\n");
    }
    printf("Queue :\n");
    if(!CIsEmpty(Q)){
        CdisplayQueue(Q);
    }else{
        printf("Your queue is empty.\n");
    }
}



void welcome(){
printf("             /$$      /$$ /$$$$$$$$ /$$        /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$       /$$$$$$$$ /$$$$$$        \n");
    printf("            | $$  /$ | $$| $$_____/| $$       /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/      |__  $$__//$$__  $$       \n");
    printf("            | $$ /$$$| $$| $$      | $$      | $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$               | $$  | $$  \\ $$       \n");
    printf("            | $$/$$ $$ $$| $$$$$   | $$      | $$      | $$  | $$| $$ $$/$$ $$| $$$$$            | $$  | $$  | $$       \n");
    printf("            | $$$$_  $$$$| $$__/   | $$      | $$      | $$  | $$| $$  $$$| $$| $$__/            | $$  | $$  | $$       \n");
    printf("            | $$$/ \\  $$$| $$      | $$      | $$    $$| $$  | $$| $$\\  $ | $$| $$               | $$  | $$  | $$       \n");
    printf("            | $$/   \\  $$| $$$$$$$$| $$$$$$$$|  $$$$$$/|  $$$$$$/| $$ \\/  | $$| $$$$$$$$         | $$  |  $$$$$$/       \n");
    printf("            |__/     \\__/|________/|________/ \\______/  \\______/ |__/     |__/|________/         |__/   \\______/        \n");
    printf("       /$$      /$$  /$$$$$$  /$$     /$$ /$$$$$$  /$$   /$$  /$$$$$$        /$$      /$$  /$$$$$$  /$$    /$$ /$$$$$$$$\n");
    printf("      | $$  /$ | $$ /$$__  $$|  $$   /$$//$$__  $$| $$$ | $$ /$$__  $$      | $$  /$ | $$ /$$__  $$| $$   | $$| $$_____/ \n");
    printf("      | $$ /$$$| $$| $$  \\ $$ \\  $$ /$$/| $$  \\ $$| $$$$| $$| $$  \\__/      | $$ /$$$| $$| $$  \\ $$| $$   | $$| $$      \n");
    printf("      | $$/$$ $$ $$| $$$$$$$$  \\  $$$$/ | $$$$$$$$| $$ $$ $$| $$ /$$$$      | $$/$$ $$ $$| $$$$$$$$|  $$ / $$/| $$$$$   \n");
    printf("      | $$$$_  $$$$| $$__  $$   \\  $$/  | $$__  $$| $$  $$$$| $$|_  $$      | $$$$_  $$$$| $$__  $$ \\  $$ $$/ | $$__/   \n");
    printf("      | $$$/ \\  $$$| $$  | $$    | $$   | $$  | $$| $$\\  $$$| $$  \\ $$      | $$$/ \\  $$$| $$  | $$  \\  $$$/  | $$      \n");
    printf("      | $$/   \\  $$| $$  | $$    | $$   | $$  | $$| $$ \\  $$|  $$$$$$/      | $$/   \\  $$| $$  | $$   \\  $/   | $$$$$$$$\n");
    printf("      |__/     \\__/|__/  |__/    |__/   |__/  |__/|__/  \\__/ \\______/       |__/     \\__/|__/  |__/    \\_/    |________/\n");
    printf("                                                                                                                        \n");
    printf("                                                                                                                        \n");
    printf("------------------------------------------- Choose << START >> or <<LOAD [file.txt]>> ------------------------------------\n");
}