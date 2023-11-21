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
        printf("Playlist ");
        displayWord(currentCommand);
        printf(" berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n");        
    }
    else {
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.");
    }
}   



void PLAYLISTADDSONG(ListPenyanyi lp, MapAlbum m2,SetLagu S ,ListDinamik *daftarplaylist) {
    printf("Daftar Penyanyi:\n");
    DisplayListPenyanyi(lp);
    printf("\n");

    printf("Masukkan Nama Penyanyi: ");
    STARTCOMMAND();
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
        printf("Nama Album tersebut tidak valid\n");
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
        printf("Lagu dengan judul ");
        displayWord(namalagu);
        printf(" pada album ");
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

