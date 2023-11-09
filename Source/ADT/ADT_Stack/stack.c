#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "../struc.h"
#include "../boolean.h"

void CreateHist(HistoriLagu *S){
    (*S).idxTop = -1; 
    (*S).count = 0;
}
/*  
I.S. Sembarang
F.S. Terbentuk Stack kosong
*/

boolean IsHistEmpty(HistoriLagu S){
    return(S.count==0);
}
/*  
Menghasilkan True jika Stack kosong, dan False jika Stack tidak kosong
*/
void PushLagu(HistoriLagu *S, Lagu L) {
    if (S->idxTop < MaxEl - 1) {
        S->idxTop++;
        S->hist_lagu[S->idxTop] = L;
        S->count++;
    } else {
        // Tumpukan penuh, tidak dapat menambahkan lagi
        printf("Tumpukan penuh. Tidak dapat menambahkan lagi.\n");
    }
}
/*
I.S. Sembarang, P terdefinisi
F.S. Menempatkan P pada Top dari S (History lagu)
*/

void PopLagu(HistoriLagu *S, Lagu *L) {
    if (S->idxTop >= 0) {
        *L = S->hist_lagu[S->idxTop];
        S->idxTop--;
        S->count--;
    } else {
        // Tumpukan kosong, tidak dapat menghapus lagi
        printf("Tumpukan kosong. Tidak dapat menghapus lagi.\n");
    }
}

/*
I.S. Stack tidak kosong
F.S. Mengambil P dari Top dari S
*/
void Viewhist(HistoriLagu S) {
    if (IsHistEmpty(S)) {
        printf("Tumpukan kosong. Tidak ada informasi yang dapat ditampilkan.\n");
    } else {
        printf("Daftar Lagu dalam HistoriLagu:\n");
        printf("[");
        for (int i = 0; i <= S.idxTop; i++) {
            printf("(%s, %d)", S.hist_lagu[i].nama_lagu, S.hist_lagu[i].album_id);
            if (i < S.idxTop) {
                printf(", ");
            }
        }
        printf("], %d\n", S.count);
    }
}

