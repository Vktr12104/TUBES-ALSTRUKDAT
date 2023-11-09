#include <stdio.h>
#include "circular_queue.h"
#include "../boolean.h"



/* ********* Prototype ********* */
boolean CIsEmpty (QueueLagu Q) {
    return ((CIDX_HEAD(Q)==IDX_UNDEF) && (CIDX_TAIL(Q)==IDX_UNDEF));
}
/* Mengirim true jika Q kosong */
/* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */
boolean CIsFull (QueueLagu Q){
    if (CIDX_HEAD(Q) == 0) {
        return (CIDX_TAIL(Q)==IDX_MAX);
    }
    else {
        return (CIDX_HEAD(Q)==CIDX_TAIL(Q)+1);
    }
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu ketika idxHead=0 dan idxTail=IDX_MAX atau idxHead=idxTail+1 ketika idxHead > idxTail */
int CLength (QueueLagu Q){
    if (CIsEmpty(Q))
    {
        return 0;
    }
    else if (CIDX_HEAD(Q) <= CIDX_TAIL(Q))
    {
        return CIDX_TAIL(Q) - CIDX_HEAD(Q) + 1;
    }
    else {
        return (CIDX_TAIL(Q)+1 + (IDX_MAX-CIDX_HEAD(Q)+1));
    }
}
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */

/* *** Kreator *** */
void CCreateQueue (QueueLagu * Q){
    CIDX_HEAD(*Q)=IDX_UNDEF;
    CIDX_TAIL(*Q)=IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/* - idxHead=IDX_UNDEF; */
/* - idxTail=IDX_UNDEF. */

/* *** Primitif Add/Delete *** */
void Cenqueue(QueueLagu *Q, Lagu X) {
    if (CIsEmpty(*Q)) {
        CIDX_HEAD(*Q) = CIDX_TAIL(*Q) = 0;
    } else {
        if (CIDX_TAIL(*Q) == IDX_MAX) {
            CIDX_TAIL(*Q) = 0;
        } else {
            CIDX_TAIL(*Q)++;
        }
    }
    CTAIL(*Q) = X;
}

Lagu Cdequeue(QueueLagu *Q) {
    Lagu val;
    val =(*Q).lagu_queue[(*Q).idxHead];
    if (CIDX_HEAD(*Q) == CIDX_TAIL(*Q)) {
        CIDX_HEAD(*Q) = CIDX_TAIL(*Q) = IDX_UNDEF;
    } else {
        if (CIDX_HEAD(*Q) == IDX_MAX) {
            CIDX_HEAD(*Q) = 0;
        } else {
            CIDX_HEAD(*Q)++;
        }
    }
    return val;
}

/* Proses: Menghapus idxHead pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada idxHead;
        Head "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* *** Display CQueue *** */
void displayQueue(QueueLagu Q) {
    printf("[");
    if (!CIsEmpty(Q)) {
        for (int i = CIDX_HEAD(Q); i < CIDX_HEAD(Q) + CLength(Q); i++) {
            Lagu currentLagu = Q.lagu_queue[i % (IDX_MAX + 1)];
            printf("(%s, %d)", currentLagu.nama_lagu, currentLagu.album_id);
            if (i % (IDX_MAX + 1) != CIDX_TAIL(Q)) {
                printf(", ");
            }
        }
    }
    printf("]\n");
}

/* Proses : Menuliskan isi CQueue dengan traversal; CQueue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma" */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika CQueue kosong : menulis [] */
/* Note: Output mengandung newline */
/* Proses : Menuliskan isi Queue dengan traversal dan mekanisme circular buffer;
/* Queue ditulis di antara kurung siku; antara dua elemen dipisahkan dengan separator "koma" */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
/* Note: Output mengandung newline */

int main() {
    QueueLagu q;
    Lagu lagu1 = {"Lagu 1", 101};
    Lagu lagu2 = {"Lagu 2", 102};
    Lagu lagu3 = {"Lagu 3", 103};

    CCreateQueue(&q); 

    printf("Is Queue Empty: %s\n", CIsEmpty(q) ? "True" : "False");

    Cenqueue(&q, lagu1);
    Cenqueue(&q, lagu2);
    Cenqueue(&q, lagu3);

    printf("Is Queue Empty: %s\n", CIsEmpty(q) ? "True" : "False");
    printf("Is Queue Full: %s\n", CIsFull(q) ? "True" : "False");
    printf("Queue Length: %d\n", CLength(q));

    printf("Isi Queue: ");
    displayQueue(q);

    Lagu ambil = Cdequeue(&q);
    printf("Popped Lagu: Nama Lagu = %s, Album ID = %d\n", ambil.nama_lagu, ambil.album_id);
    displayQueue(q);
    return 0;
}

