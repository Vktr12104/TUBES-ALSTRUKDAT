#include <stdio.h>
#include "set.h"
#include <stdlib.h>

/* *** Konstruktor/Kreator *** */


void CreateEmptyLagu(Lagu *S) {
    int i;
    for (i = 0; i < MaxEl; i++) {
        (*S).nama_lagu[i] = '\0';  // Set each element to null character
    }
    (*S).album_id = INT_UNDEF;     // Set the album_id to undefined value
}

boolean IsEmptyLagu(Lagu S) {
    int i;
    for (i = 0; i < MaxEl; i++) {
        if (S.nama_lagu[i] != '\0') {
            return false;  // If any element is not null, the set is not empty
        }
    }
    return true;  // All elements are null, set is empty
}

boolean IsFullLagu(Lagu S) {
    int i;
    for (i = 0; i < MaxEl; i++) {
        if (S.nama_lagu[i] == '\0') {
            return false;  // If any element is null, the set is not full
        }
    }
    return true;  // All elements are non-null, set is full
}
/* Mengirim true jika Lagu S penuh */
/* ********** Operator Dasar Lagu ********* */
void InsertLagu(Lagu *S, Title Elmt) {
    // Check if Elmt is already a member of S
    if (!IsMemberLagu(*S, Elmt)) {
        int i = 0;

        // Find the first available slot (null character) to insert Elmt
        while ((*S).nama_lagu[i] != '\0') {
            i++;
        }

        // Insert Elmt into the set
        (*S).nama_lagu[i] = Elmt;
    }
}
boolean IsMemberLagu(Lagu S, Title Elmt) {
    int i = 0;
    while (S.nama_lagu[i] != '\0') {
        if (S.nama_lagu[i] == Elmt) {
            return true;  // Elmt is already a member
        }
        i++;
    }
    return false;  // Elmt is not a member
}
/*
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
*/