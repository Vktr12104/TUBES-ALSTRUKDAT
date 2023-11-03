#include <stdio.h>
#include "set.h"
#include "boolean.h"

int main() {
    Lagu mySet;
    CreateEmptyLagu(&mySet);

    // Menambahkan beberapa elemen ke Set
    InsertLagu(&mySet, "Lagu 1");
    InsertLagu(&mySet, "Lagu 2");
    InsertLagu(&mySet, "Lagu 3");
    DisplayLagu(mySet);
    printf("jumlah lagu %d\n", mySet.count);
    // Mengecek apakah Set kosong
    if (IsEmptyLagu(mySet)) {
        printf("Set kosong.\n");
    } else {
        printf("Set tidak kosong.\n");
    }

    // Mengecek apakah Set penuh
    if (IsFullLagu(mySet)) {
        printf("Set penuh.\n");
    } else {
        printf("Set tidak penuh.\n");
    }

    // Mengecek keanggotaan elemen
    if (IsMemberLagu(mySet, "Lagu 2")) {
        printf("Lagu 2 adalah anggota Set.\n");
    } else {
        printf("Lagu 2 bukan anggota Set.\n");
    }

    // Menghapus elemen dari Set
    DeleteLagu(&mySet, "Lagu 2");

    // Mengecek apakah elemen telah dihapus
    if (IsMemberLagu(mySet, "Lagu 2")) {
        printf("Lagu 2 adalah anggota Set.\n");
    } else {
        printf("Lagu 2 bukan anggota Set.\n");
    }

    return 0;
}
