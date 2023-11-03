#include <stdio.h>
#include "circular_queue.h"
#include "boolean.h"


/* ********* Prototype ********* */
boolean CIsEmpty (Queue Q){
    return ((CIDX_HEAD(Q)==IDX_UNDEF) && (CIDX_TAIL(Q)==IDX_UNDEF));
}
/* Mengirim true jika Q kosong */
/* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */
boolean CIsFull (Queue Q){
    if (CIDX_HEAD(Q) == 0) {
        return (CIDX_TAIL(Q)==IDX_MAX);
    }
    else {
        return (CIDX_HEAD(Q)==CIDX_TAIL(Q)+1);
    }
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu ketika idxHead=0 dan idxTail=IDX_MAX atau idxHead=idxTail+1 ketika idxHead > idxTail */
int CLength (Queue Q){
    if (CIsEmpty(Q)){
        return 0;
    }
    else {
        return ( (CIDX_HEAD(Q) <= CIDX_TAIL(Q)) ? CIDX_TAIL(Q)-CIDX_HEAD(Q)+1 : (IDX_MAX+1)-CIDX_HEAD(Q)+CIDX_TAIL(Q)+1 );
    }
}
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */

/* *** Kreator *** */
void CCreateQueue (Queue * Q){
    CIDX_HEAD(*Q)=IDX_UNDEF;
    CIDX_TAIL(*Q)=IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/* - idxHead=IDX_UNDEF; */
/* - idxTail=IDX_UNDEF. */

/* *** Primitif Add/Delete *** */
void Cenqueue (Queue * Q, ElType X){
    if (CIsEmpty(*Q)) {
        CIDX_HEAD(*Q)=0;
        CIDX_TAIL(*Q)=0;
    }
    else {
        CIDX_TAIL(*Q)=(CIDX_TAIL(*Q)+1)%(IDX_MAX+1);
    }   
    CTAIL(*Q)=X;
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. Tail "maju" dengan mekanisme circular buffer,
        X menjadi idxTail yang baru
        Jika Q kosong, idxHead dimulai dari 0 */
ElType Cdequeue (Queue * Q){
    ElType val = CHEAD(*Q);
    if (cIDX_HEAD(*Q)==CIDX_TAIL(*Q)) {
        CIDX_HEAD(*Q)=IDX_UNDEF;
        CIDX_TAIL(*Q)=IDX_UNDEF;
    }
    else {
        CIDX_HEAD(*Q)=(CIDX_HEAD(*Q)+1)%(IDX_MAX+1);
    }
    return val;
}
/* Proses: Menghapus idxHead pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada idxHead;
        Head "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* *** Display Queue *** */
void CdisplayQueue(Queue q){
    int i = CIDX_HEAD(q);

    if (CIsEmpty(q)){
        printf("[]\n");
    } else {
        printf("[");
        for (i = CIDX_HEAD(q); i < (CIDX_HEAD(q)+CLength(q))-1; i++){
            printf("%d,", q.Tab[i%(IDX_MAX+1)]);
        }
        printf("%d]\n", q.Tab[(i)%(IDX_MAX+1)]);
    }
}
/* Proses : Menuliskan isi Queue dengan traversal dan mekanisme circular buffer;
/* Queue ditulis di antara kurung siku; antara dua elemen dipisahkan dengan separator "koma" */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
/* Note: Output mengandung newline */
