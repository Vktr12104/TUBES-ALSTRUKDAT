#include <stdio.h>
#include "map.h"// Sesuaikan dengan lokasi header file "map.h"

int main() {
    ListPenyanyi LP;
    CreateEmptyListPenyanyi(&LP);

    // Membuat beberapa penyanyi
    Penyanyi P1, P2;
    CreateMapAlbum(&P1);
    CreateMapAlbum(&P2);

    // Menambahkan album ke penyanyi
    Album A1, A2;
    CreateMapLagu(&A1);
    CreateMapLagu(&A2);

    // Menambahkan lagu ke album
    Title song1 = "Song1";
    Title song2 = "Song2";

    InsertMapLagu(&P1, &A1, song1);
    InsertMapLagu(&P2, &A2, song2);

    // Mengecek keanggotaan
    printf("Is Song1 a member of Album A1? %s\n", IsMemberMapLagu(A1, song1) ? "Yes" : "No");
    printf("Is Song2 a member of Album A2? %s\n", IsMemberMapLagu(A2, song2) ? "Yes" : "No");

    // Menghapus lagu dari album
    DeleteMapLagu(&A1, song1);
    printf("Is Song1 a member of Album A1 after deletion? %s\n", IsMemberMapLagu(A1, song1) ? "Yes" : "No");

    // Menghapus album dari penyanyi
    return 0;
}
