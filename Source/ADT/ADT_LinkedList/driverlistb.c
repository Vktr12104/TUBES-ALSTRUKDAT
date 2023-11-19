#include <stdio.h>
#include <string.h>
#include "listb.h"
#include "../ADT_Set/boolean.h"
int main() {
    listBerkait L1, L2, L3;
    isi_playlist lagu1, lagu2, lagu3;

    // Inisialisasi lagu
    lagu1.lagu_playlist.TabWord[0] = 'S';
    lagu1.lagu_playlist.TabWord[1] = 'o';
    lagu1.lagu_playlist.TabWord[2] = 'n';
    lagu1.lagu_playlist.TabWord[3] = 'g';
    lagu1.lagu_playlist.Length = 4;

    lagu2.lagu_playlist.TabWord[0] = 'M';
    lagu2.lagu_playlist.TabWord[1] = 'y';
    lagu2.lagu_playlist.TabWord[2] = 'W';
    lagu2.lagu_playlist.TabWord[3] = 'a';
    lagu2.lagu_playlist.TabWord[4] = 'y';
    lagu2.lagu_playlist.Length = 5;

    lagu3.lagu_playlist.TabWord[0] = 'H';
    lagu3.lagu_playlist.TabWord[1] = 'e';
    lagu3.lagu_playlist.TabWord[2] = 'l';
    lagu3.lagu_playlist.TabWord[3] = 'l';
    lagu3.lagu_playlist.TabWord[4] = 'o';
    lagu3.lagu_playlist.Length = 5;

    // Inisialisasi list
    CreateEmpty(&L1);
    CreateEmpty(&L2);
    CreateEmpty(&L3);

    // Menambahkan lagu ke list
    InsVLast(&L1, lagu1);
    InsVLast(&L1, lagu2);

    InsVLast(&L2, lagu3);

    // Menampilkan isi list
    printf("Isi List 1: ");
    PrintInfo(L1);
    printf("\n");

    printf("Isi List 2: ");
    PrintInfo(L2);
    printf("\n");

    // Menggabungkan dua list
    Konkat1(&L1, &L2, &L3);

    // Menampilkan hasil penggabungan
    printf("Isi List Setelah Penggabungan: ");
    PrintInfo(L3);
    printf("\n");

    return 0;
}
