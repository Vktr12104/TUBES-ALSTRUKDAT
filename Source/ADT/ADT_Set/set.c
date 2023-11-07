#include <stdio.h>
#include "set.h"
#include <stdlib.h>

/* *** Konstruktor/Kreator *** */


void CreateEmptyLagu(Lagu *S) {
    S->album_id = Nil;
    S->count = 0; // Inisialisasi count ke 0
    for (int i = 0; i < MaxEl; i++) {
        S->lagu_nama[i] = NULL;
    }
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */

boolean IsEmptyLagu(Lagu S) {
    return (S.count == 0); // Set kosong jika count adalah 0
}

boolean IsFullLagu(Lagu S){
    return(S.count == MaxEl);
}
/* Mengirim true jika Lagu S penuh */
/* ********** Operator Dasar Lagu ********* */
void InsertLagu(Lagu *S, infotype Elmt) {
    if (!IsMemberLagu(*S, Elmt) && S->count < MaxEl) {
        int i;
        for (i = 0; i < MaxEl; i++) {
            if (S->lagu_nama[i] == NULL) {
                S->lagu_nama[i] = Elmt;
                S->count++; // Menambah count saat menambahkan elemen
                break;
            }
        }
    }
}

void DeleteLagu(Lagu *S, infotype Elmt) {
    int i, j;
    for (i = 0; i < MaxEl; i++) {
        if (S->lagu_nama[i] != NULL) {
            for (j = 0; S->lagu_nama[i][j] != '\0' && Elmt[j] != '\0'; j++) {
                if (S->lagu_nama[i][j] != Elmt[j]) {
                    break;
                }
            }
            if (S->lagu_nama[i][j] == '\0' && Elmt[j] == '\0') {
                S->lagu_nama[i] = NULL;
                S->count--; // Mengurangi count saat menghapus elemen
                break;
            }
        }
    }
}

boolean IsMemberLagu(Lagu S, infotype Elmt) {
    int i, j;
    for (i = 0; i < MaxEl; i++) {
        if (S.lagu_nama[i] != NULL) {
            for (j = 0; S.lagu_nama[i][j] != '\0' && Elmt[j] != '\0'; j++) {
                if (S.lagu_nama[i][j] != Elmt[j]) {
                    break;
                }
            }
            if (S.lagu_nama[i][j] == '\0' && Elmt[j] == '\0') {
                return true;
            }
        }
    }
    return false;
}
void DisplayLagu(Lagu S) {
    printf("Album ID: %d\n", S.album_id);
    printf("Daftar Lagu:\n");

    for (int i = 0; i < MaxEl; i++) {
        if (S.lagu_nama[i] != NULL) {
            printf("%d. %s\n", i + 1, S.lagu_nama[i]);
        }
    }
}
