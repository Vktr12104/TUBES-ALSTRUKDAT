#include "playsong.h"

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

void playPlaylist (ListDinamik LD, QueueLagu Ql, HistoriLagu* Hl){
    printf("Masukkan ID Playlist: \n");
    STARTCOMMAND();
    
}