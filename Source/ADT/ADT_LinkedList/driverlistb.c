#include <stdio.h>
#include "listb.h"

int main() {
    // Buat listBerkait
    listBerkait L;
    CreateEmptylistb(&L);

    // Tambahkan elemen ke list
    InsVFirstlistb(&L, "Penyanyi1", "Album1", "Lagu1");
    InsVLastlistb(&L, "Penyanyi2", "Album2", "Lagu2");
    InsVLastlistb(&L, "Penyanyi3", "Album3", "Lagu3");

    // Cetak isi list
    printf("Isi List Awal: ");
    PrintInfolistb(L);
    printf("\n");

    // Contoh penggunaan fungsi lain
    if (!IsEmptylistb(L)) {
        printf("Jumlah elemen dalam list: %d\n", NbElmtlistb(L));
        
        address found = Searchlistb(L, "Lagu2");
        if (found != NULL) {
            printf("Elemen ditemukan: %.*s\n", Info(found).lagu_playlist, Info(found).lagu_playlist);
        } else {
            printf("Elemen tidak ditemukan\n");
        }
    }

    // Hapus elemen dari list
    Isi_Que deleted;
    DelVFirstlistb(&L, &deleted);
    printf("Elemen pertama dihapus: %.*s\n", deleted.lagu_playlist, deleted.lagu_playlist);

    // Cetak isi list setelah penghapusan
    printf("Isi List setelah penghapusan: ");
    PrintInfolistb(L);
    printf("\n");

    // Dealokasi list
    address P;
    DelLastlistb(&L, &P);
    Dealokasilistb(&P);

    // Cetak isi list setelah dealokasi
    printf("Isi List setelah dealokasi: ");
    PrintInfolistb(L);
    printf("\n");

    return 0;
}
