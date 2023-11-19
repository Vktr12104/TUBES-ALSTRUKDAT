#include "listdinamis.h"

int main() {
    // Deklarasi list
    List myList = MakeList();

    // Menambahkan beberapa elemen ke dalam list
    ListPlaylist playlist1, playlist2, playlist3;
    // Inisialisasi playlist1, playlist2, playlist3

    InsertFirst(&myList, playlist1);
    InsertLast(&myList, playlist2);
    InsertAt(&myList, playlist3, 1);

    // Menampilkan isi list
    printf("Isi List:\n");
    int i;
    for (i = 0; i < Length(myList); i++) {
        // Tampilkan elemen-elemen playlist
        printf("Playlist %d:\n", i + 1);
        // Tampilkan detil playlist seperti NamaPlaylist, idxPlaylist, dll.
    }

    // Menghapus elemen pertama dan menampilkan isi list setelah penghapusan
    DeleteFirst(&myList);
    printf("\nSetelah Menghapus Elemen Pertama:\n");
    for (i = 0; i < Length(myList); i++) {
        // Tampilkan elemen-elemen playlist setelah penghapusan
    }

    // Menghapus elemen pada indeks tertentu dan menampilkan isi list setelah penghapusan
    IdxType indexToDelete = 1;
    DeleteAt(&myList, indexToDelete);
    printf("\nSetelah Menghapus Elemen pada Indeks %d:\n", indexToDelete);
    for (i = 0; i < Length(myList); i++) {
        // Tampilkan elemen-elemen playlist setelah penghapusan
    }

    return 0;
}
