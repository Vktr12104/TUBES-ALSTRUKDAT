#include "play.h"

void playsong (ListPenyanyi lp, SetLagu sl, MapAlbum ma, QueueLagu* Ql, HistoriLagu* Hl) {
    printf("Daftar Penyanyi :\n");
    DisplayListPenyanyi(lp);

    printf("Masukkan Nama Penyanyi yang dipilih : \n");
    STARTCOMMAND();

    if (!isMemberListPenyanyi(currentCommand, lp)){
        printf("Nama Penyanyi ");
        displayWord(currentCommand);
        printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        return;
    }
    Word namapenyanyi = currentCommand;
    char *penyanyi=wordToString(namapenyanyi);
    int idpenyanyi = albumtoidpenyanyi(lp, namapenyanyi);

    printf("Daftar album oleh ");
    displayWord(namapenyanyi);
    printf(" : \n");
    displayMapAlbum(ma, idpenyanyi);

    printf("Masukkan Nama Album yang dipilih : \n");
    STARTCOMMAND();

    if (!IsMemberMapAlbum(ma,currentCommand)){
        printf("Album ");
        displayWord(currentCommand);
        printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        return;
    }
    Word namaalbum = currentCommand;
    char *album=wordToString(namaalbum);
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
    int jumlahlagu = CountLaguByAlbumID(&sl,idalbum);

    if((idlagu<=0) || (idlagu > jumlahlagu)){
        printf("ID lagu tidak valid\n");
        return;
    }
    Word namalagu = namalagufromalbum (sl, idalbum, idlagu);
    char *lagu=wordToString(namalagu);


    printf ("Memutar lagu ");
    displayWord(namalagu);
    printf (" oleh ");
    displayWord(namapenyanyi);


    printf ("\n");
    QueClear(Ql);
    
    while ((*Hl).idxTop>=0) {
        (*Hl).idxTop--;
        (*Hl).count--;
    }
    printf ("History dikosongkan.\n");

    current.album=album;
    current.lagu=lagu;
    current.penyanyi=penyanyi;
}

void playPlaylist(ListDinamik LD, QueueLagu* Ql, HistoriLagu* Hl) {
    if (IsEmptyLD(LD)) {
        printf("Playlist kosong, tidak ada yang bisa dimainkan.\n");
    } else {
        CreateHist(Hl);
        CCreateQueue(Ql);

        int pilih = pilihPlaylist(LD);
        Address P = LD.Content[pilih].First;
        current.lagu = wordToString(LD.Content[pilih].First->Info.Lagu);
        current.penyanyi = wordToString(LD.Content[pilih].First->Info.Penyanyi);
        current.album = wordToString(LD.Content[pilih].First->Info.Album);

        P = Next(P);
        while (P != NULL) {
            Cenqueue(Ql, wordToString(Info(P).Penyanyi), wordToString(Info(P).Album), wordToString(Info(P).Lagu));
            PushLagu(Hl, wordToString(Info(P).Penyanyi), wordToString(Info(P).Album), wordToString(Info(P).Lagu));
            P = Next(P);
        }
    }
}


int pilihPlaylist(ListDinamik LD) {
    boolean found = false;
    int idxPlaylist;

    while (!found) {
        boolean cek = false;

        while (!cek) {
            printf("\nMasukkan ID Playlist yang dipilih : ");
            STARTCOMMAND();

            if (currentCommand.TabWord[currentCommand.Length - 1] == ';') {
                cek = true;
            } else {
                printf("Command Tidak Valid. Silakan Coba Lagi!\n");
            }
        }

        Word notikom = takewordsemicolon(currentCommand, 1);
        printf("\n");
        int ID = wordToInt(notikom);

        if (ID > 0 && ID <= LD.Neff) {
            found = true;
            idxPlaylist = ID - 1;
        }

        if (!found) {
            printf("ID %d tidak ada dalam daftar, silakan coba lagi\n", ID);
        }
        current.playlistID = ID;
    }

    return idxPlaylist;
}
