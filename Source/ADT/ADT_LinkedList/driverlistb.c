#include <stdio.h>
#include <string.h>
#include "listb.h"
#include "../ADT_Set/boolean.h"
#include <stdio.h>
#include "listb.h"

int main() {
    listBerkait playlist1, playlist2, playlist3;
    isi_playlist song, dream, newSong;

    // Inisialisasi playlist dan lagu
    CreateEmpty(&playlist1);
    CreateEmpty(&playlist2);
    CreateEmpty(&playlist3);

    // Lagu pertama
    song.lagu_playlist.Length = 4;
    song.lagu_playlist.TabWord[0] = 's';
    song.lagu_playlist.TabWord[1] = 'o';
    song.lagu_playlist.TabWord[2] = 'n';
    song.lagu_playlist.TabWord[3] = 'g';

    // Lagu kedua
    dream.lagu_playlist.Length = 5;
    dream.lagu_playlist.TabWord[0] = 'd';
    dream.lagu_playlist.TabWord[1] = 'r';
    dream.lagu_playlist.TabWord[2] = 'e';
    dream.lagu_playlist.TabWord[3] = 'a';
    dream.lagu_playlist.TabWord[4] = 'm';

    // Menambahkan lagu ke playlist pertama
    InsVFirst(&playlist1, song);
    printf("Playlist 1: ");
    PrintInfo(playlist1);
    printf("\n");

    // Menambahkan lagu ke playlist kedua
    InsVFirst(&playlist2, dream);
    printf("Playlist 2: ");
    PrintInfo(playlist2);
    printf("\n");

    // Menggabungkan playlist pertama dan kedua ke playlist ketiga
    Konkat1(&playlist1, &playlist2, &playlist3);
    printf("Playlist 3 (setelah penggabungan): ");
    PrintInfo(playlist3);
    printf("\n");

    // Menambahkan lagu baru ke playlist ketiga
    newSong.lagu_playlist.Length = 4;
    newSong.lagu_playlist.TabWord[0] = 's';
    newSong.lagu_playlist.TabWord[1] = 'o';
    newSong.lagu_playlist.TabWord[2] = 'n';
    newSong.lagu_playlist.TabWord[3] = 'g';
    InsVLast(&playlist3, newSong);
    printf("Playlist 3 (setelah menambahkan lagu terakhir): ");
    PrintInfo(playlist3);
    printf("\n");

    // Menghapus lagu pertama dari playlist ketiga
    DelVFirst(&playlist3, &newSong);
    printf("Playlist 3 (setelah menghapus lagu pertama): ");
    PrintInfo(playlist3);
    printf("\n");

    // Mencari lagu "dream" di playlist ketiga
    address foundSong = Search(playlist3, dream);
    if (foundSong != NULL) {
        printf("Lagu 'dream' ditemukan di playlist 3.\n");
    } else {
        printf("Lagu 'dream' tidak ditemukan di playlist 3.\n");
    }

    // Menghapus lagu terakhir dari playlist ketiga
    DelVLast(&playlist3, &newSong);
    printf("Playlist 3 (setelah menghapus lagu terakhir): ");
    PrintInfo(playlist3);
    printf("\n");

    // Membalik urutan lagu di playlist ketiga
    InversList(&playlist3);
    printf("Playlist 3 (setelah dibalik): ");
    PrintInfo(playlist3);
    printf("\n");

    // Jumlah lagu di playlist ketiga
    int count = NbElmt(playlist3);
    printf("Jumlah lagu di playlist 3: %d\n", count);

    // Membersihkan playlist
    CreateEmpty(&playlist1);
    CreateEmpty(&playlist2);
    CreateEmpty(&playlist3);

    return 0;
}