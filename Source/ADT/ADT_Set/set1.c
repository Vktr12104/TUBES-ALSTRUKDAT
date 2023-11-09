#include <stdio.h>
#include "../structure.h"

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Lagu *S) {
    for (int i = 0; i < MaxEl; i++) {
        S->lagu_nama[i] = STR_UNDEF;  // Mengisi dengan nilai '0' sebagai nilai undefinied
    }
    S->album_id = INT_UNDEF;  // Mengisi album_id dengan nilai -999 sebagai nilai undefinied
}

/* Ciri Lagu kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Lagu S){
        int i = 0;
    boolean empty = true;
    
    while (i < MaxEl && empty) {
        if (S.lagu_nama[i] != STR_UNDEF) {  // Memeriksa apakah ada elemen yang tidak undefinied
            empty = false;
        }
        i++;
    }
    
    if (S.album_id != INT_UNDEF) {  // Memeriksa apakah album_id sudah terisi
        empty = false;
    }
    
    return empty;
}
/* Mengirim true jika Lagu S kosong*/


boolean IsFull(Lagu S){
    int i = 0;
    boolean full = true;
    
    while (i < MaxEl && full) {
        if (S.lagu_nama[i] == STR_UNDEF) {  // Memeriksa apakah ada elemen yang masih undefinied
            full = false;
        }
        i++;
    }
    
    if (S.album_id == INT_UNDEF) {  // Memeriksa apakah album_id masih undefinied
        full = false;
    }
    
    return full;
}
/* Mengirim true jika Lagu S penuh */


/* ********** Operator Dasar Lagu ********* */
void Insert(Lagu *S, Title song) {
    // Periksa apakah Lagu S sudah penuh
    if (S->album_id == MaxEl) {
        printf("Lagu sudah penuh, operasi tidak bisa dilakukan\n");
        return;
    }

    // Periksa apakah song sudah ada di Lagu S
    for (int i = 0; i < S->album_id; i++) {
        if (S->lagu_nama[i] == song) {
            printf("song sudah merupakan anggota, operasi tidak dilakukan\n");
            return;
        }
    }

    // Tambahkan song ke Lagu S
    S->lagu_nama[S->album_id] = song;
    S->album_id++; // Naikkan album_id sesuai dengan jumlah lagu yang sudah ada
}


void Delete(Lagu *S, Title song) {
    // Periksa apakah Lagu S kosong
    if (S->album_id == 0) {
        printf("Lagu kosong, operasi tidak bisa dilakukan\n");
        return;
    }

    int i;
    for (i = 0; i < S->album_id; i++) {
        if (S->lagu_nama[i] == song) {
            break; // Temukan indeks dari song
        }
    }

    if (i == S->album_id) {
        printf("song tidak merupakan anggota, operasi tidak dilakukan\n");
        return;
    }

    // Geser elemen-elemen di bawah song ke atas
    for (int j = i; j < S->album_id - 1; j++) {
        S->lagu_nama[j] = S->lagu_nama[j + 1];
    }

    S->album_id--; // Kurangi jumlah elemen di Lagu S
}

boolean IsMember(Lagu S, Title song){
    for (int i = 0; i < MaxEl; i++) {
        if (S.lagu_nama[i] == song) {
            return true; // Jika ditemukan, kembalikan true
        }
    }
    return false; // Jika tidak ditemukan, kembalikan false
}
/* Mengembalikan true jika song adalah member dari S */


