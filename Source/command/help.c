#include <stdio.h>
#include "help.h"
#include "../ADT/struc.h"


void help() {
    ListPenyanyi L;
    if (IsEmpty(L)) {
        printf ("=====[ Menu Help WayangWave ]=====\n");
        printf ("1. START -> Untuk masuk sesi baru\n");
        printf ("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
        printf ("3. listDef -> Untuk menampilkan daftar penyanyi, album, dan lagu default\n");
        printf ("4. listPlay -> Untuk menampilkan daftar penyanyi, album, dan lagu playlist\n");
        printf ("5. PlayLagu -> Memutar lagu sesuai yang dipilih dan dimasukkan ke dalam history\n");
        printf ("6. Play2List -> Memutar Seluruh lagu pada playlist dan dimasukan ke dalam history\n");
        printf ("7. QueSong -> Memasukkan lagu yang dipilih ke dalam antrian\n");
        printf ("8. QueList -> Menambahkan lagu yang ada dalam playlist ke dalam queue\n");
        printf ("9. QueSwap -> Melakukan pertukaran lagu pada queue\n");
        printf ("10. QueMove -> Menghapus Que pada urutan tertentu\n");
        printf ("11. QueClear -> Menghapus semua lagu pada queue\n");
        printf ("12. SongNext -> Jika keadaan belum memutar lagu tetapi sudah ada que maka akan memuta lagu pada que, Jika sedang memutar lagu maka lagu akan dimasukkan pada History Lagu dan memutar lagu pada queue\n");
        printf ("13. SongPrev -> Memutar lagu pada history lagu, jika belum ada dan baru memutar laguu yang diputar maka lagu lagu yang sedang diputar\n");
        printf ("14. CreatePlayList -> Tercipta satu playlist\n");
        printf ("15. playlist_add -> Menambahkan lagu pada playlist tertentu\n");
        printf ("16. RemoveLagu -> Menghapus lagu pada playlist tertentu\n");
        printf ("17. SwapLagu -> Menukar lagu pada playlist tertentu\n");
        printf ("18. DelPlayList -> Menghapus Playlist\n");
        printf ("19. Status -> Mengeluarkan output status pemutaran lagu\n");
        printf ("20. help -> Mengembalikan output berupa daftar command yang dapat dimasukkan berikut fungsinya\n");
        printf ("21. save -> Menyimpan Array dalam file eksternal\n");
        printf ("22. QUIT -> Keluar dari sesi\n");
    }
    else {
        printf ("=====[ Menu Help WayangWave ]=====\n");
        printf ("1. listDef -> Untuk menampilkan daftar penyanyi, album, dan lagu default\n");
        printf ("2. listPlay -> Untuk menampilkan daftar penyanyi, album, dan lagu playlist\n");
        printf ("3. PlayLagu -> Memutar lagu sesuai yang dipilih dan dimasukkan ke dalam history\n");
        printf ("4. Play2List -> Memutar Seluruh lagu pada playlist dan dimasukan ke dalam history\n");
        printf ("5. QueSong -> Memasukkan lagu yang dipilih ke dalam antrian\n");
        printf ("6. QueList -> Menambahkan lagu yang ada dalam playlist ke dalam queue\n");
        printf ("7. QueSwap -> Melakukan pertukaran lagu pada queue\n");
        printf ("8. QueMove -> Menghapus Que pada urutan tertentu\n");
        printf ("9. QueClear -> Menghapus semua lagu pada queue\n");
        printf ("10. SongNext -> Jika keadaan belum memutar lagu tetapi sudah ada que maka akan memuta lagu pada que, Jika sedang memutar lagu maka lagu akan dimasukkan pada History Lagu dan memutar lagu pada queue\n");
        printf ("11. SongPrev -> Memutar lagu pada history lagu, jika belum ada dan baru memutar laguu yang diputar maka lagu lagu yang sedang diputar\n");
        printf ("12. CreatePlayList -> Tercipta satu playlist\n");
        printf ("13. playlist_add -> Menambahkan lagu pada playlist tertentu\n");
        printf ("14. RemoveLagu -> Menghapus lagu pada playlist tertentu\n");
        printf ("15. SwapLagu -> Menukar lagu pada playlist tertentu\n");
        printf ("16. DelPlayList -> Menghapus Playlist\n");
        printf ("17. Status -> Mengeluarkan output status pemutaran lagu\n");
        printf ("18. help -> Mengembalikan output berupa daftar command yang dapat dimasukkan berikut fungsinya\n");
        printf ("19. save -> Menyimpan Array dalam file eksternal\n");
        printf ("20. QUIT -> Keluar dari sesi\n");
    }
}