#include <stdio.h>
#include "playlist.h"
#include "../ADT/boolean.h"
#include "../ADT/ADT_List/listdinamis.h"
#include "../ADT/ADT_List/liststatis.h"
#include "../ADT/ADT_Map/map.h"
#include "../ADT/ADT_Mesin-Kata/mesinkata.h"
#include "../ADT/ADT_MesinKarakter/mesinkarakter.h"
#include "../ADT/ADT_Queue/circular_queue.h"
#include "../ADT/ADT_Queue/queue.h"
#include "../ADT/ADT_Set/set.h"
#include "../ADT/ADT_Stack/stack.h"


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
    displayWordNewLine(namalagu);
    displayWordNewLine(penyanyitemp);
    displayWordNewLine(albumtemp);
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