#include "play.h"

void playsong (ListPenyanyi lp, SetLagu sl, MapAlbum ma, QueueLagu* Ql, HistoriLagu* Hl) {
    printf("Daftar Penyanyi :\n");
    DisplayListPenyanyi(lp);

    printf("Masukkan Nama Penyanyi yang dipilih : \n");
    STARTCOMMAND();
    Word namapenyanyi = currentCommand;
    int idpenyanyi = albumtoidpenyanyi(lp, namapenyanyi);
    printf("Daftar album oleh ");
    displayWord(namapenyanyi);
    printf(" : \n");
    displayMapAlbum(ma, idpenyanyi);

    printf("Masukkan Nama Album yang dipilih : \n");
    STARTCOMMAND();
    Word namaalbum = currentCommand;
    int idalbum = laguAlbumID(namaalbum, ma);
    printf("Daftar lagu album ");
    displayWord(namaalbum);
    printf(" oleh ");
    displayWord(namapenyanyi);
    printf(" : \n");
    DisplaySetLagu(sl, idalbum);

    printf("Masukkan ID Lagu yang dipilih :  ");
    STARTCOMMAND();
    int idlagu = wordToInt(currentCommand);
    Word namalagu = namalagufromalbum (sl, idalbum, idlagu);


    printf ("Memutar lagu ");
    displayWord(namalagu);
    printf (" oleh ");
    displayWord(namapenyanyi);


    QueClear(&Ql);
    while ((*Hl).idxTop>=0) {
        (*Hl).idxTop--;
        (*Hl).count--;
    }
}

void playPlaylist (ListDinamik LD, QueueLagu* Ql, HistoriLagu* Hl){
    if (IsEmptyLD(LD)){
        printf("Playlist kosong, tidak ada yang bisa dimainkan.\n");
    }
    else{
        CreateHist(Hl);
        CCreateQueue(Ql);

    int pilih = pilihPlaylist(LD);
    Address P = LD.Content[pilih].First;
    current.lagu = wordToString(LD.Content[pilih].First->Info.Lagu);
    current.penyanyi = wordToString(LD.Content[pilih].First->Info.Penyanyi);
    current.album = wordToString(LD.Content[pilih].First->Info.Album);

    P = Next(P);
    while(P != NULL){
        Cenqueue(Ql, wordToString(Info(P).Penyanyi), wordToString(Info(P).Album), wordToString(Info(P).Lagu));
        PushLagu(Hl, wordToString(Info(P).Penyanyi), wordToString(Info(P).Album), wordToString(Info(P).Lagu));
        P = Next(P);
    } 
}
}

int pilihPlaylist(ListDinamik LD){
    boolean found = false;
    int idxPlaylist;
    while (!found){
        boolean cek = false;
        while(!cek){
            printf("\nMasukkan ID Playlist yang dipilih : ");
            STARTCOMMAND();
            if (currentCommand.TabWord[currentCommand.Length-1]==';'){
                cek = true;
            }
            else{
                printf("Command Tidak Valid. Silakan Coba Lagi!\n");
            }
        }
        Word notikom = takewordsemicolon(currentCommand,1);
        printf("\n");
        int ID = wordToInt(notikom);
        if (ID > 0 && ID <= LD.Neff){
            found = true;
            idxPlaylist = ID - 1;
        }
        if (!found){
            printf("ID %d tidak ada dalam daftar, silakan coba lagi\n", ID);
        }
    }
    return idxPlaylist;
}
