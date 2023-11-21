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
        InsertLD(&*DaftarPlaylist, currentCommand, DaftarPlaylist->Neff);
        printf("Playlist ");
        displayWord(currentCommand);
        printf(" berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n");        
    }
    else {
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.");
    }
}   

