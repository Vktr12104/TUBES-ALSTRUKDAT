#include <stdio.h>
#include "queue.h"
#include "../boolean.h"

/* *** Kreator *** */
void CreateQueue(QueueLagu *q){
    IDX_HEAD(*q)=IDX_UNDEF;
    IDX_TAIL(*q)=IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty(QueueLagu q){
    return ((IDX_HEAD(q)==IDX_UNDEF) && (IDX_TAIL(q)==IDX_UNDEF));
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFull(QueueLagu q){
    if (IDX_HEAD(q)==0){
        return (IDX_TAIL(q)==99);
    }
    else {
        return (IDX_TAIL(q)==IDX_HEAD(q)-1);
    }
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(QueueLagu q){
    if (isEmpty(q)){
        return 0;
    }
    else {
        return ( (IDX_HEAD(q) <= IDX_TAIL(q)) ? IDX_TAIL(q)-IDX_HEAD(q)+1 : CAPACITY-IDX_HEAD(q)+IDX_TAIL(q)+1 );
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(QueueLagu *q, Lagu val){
    if (isEmpty(*q)){
        IDX_HEAD(*q)=0;
        IDX_TAIL(*q)=0;
    }
    else {
        IDX_TAIL(*q)=(IDX_TAIL(*q)+1) % CAPACITY;
    }
    (*q).lagu_queue[IDX_TAIL(*q)] = val;
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(QueueLagu *q, Lagu *val){
    *val=HEAD(*q);
    if (IDX_HEAD(*q)==IDX_TAIL(*q)){
        IDX_HEAD(*q)=IDX_UNDEF;
        IDX_TAIL(*q)=IDX_UNDEF;
    }
    else {
        IDX_HEAD(*q) = ((*q).idxHead+1) % CAPACITY;
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(QueueLagu q) {
    if (isEmpty(q)) {
        printf("[]\n");
    } else {
        printf("[");
        for (int i = IDX_HEAD(q); i < (IDX_HEAD(q) + length(q)); i++) {
            printf("%s", q.lagu_queue[i % CAPACITY].nama_lagu);
            if (i < (IDX_HEAD(q) + length(q) - 1)) {
                printf(",");
            }
        }
        printf("]\n");
    }
}


/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
int main() {
    QueueLagu q;
    Lagu val;

    CreateQueue(&q);

    printf("Queue is empty: %s\n", isEmpty(q) ? "true" : "false");
    printf("Queue is full: %s\n", isFull(q) ? "true" : "false");
    printf("Queue length: %d\n", length(q));

    printf("Enqueue 3 elements:\n");
    Lagu lagu1 = {"Lagu 1", 101};
    Lagu lagu2 = {"Lagu 2", 102};
    Lagu lagu3 = {"Lagu 3", 103};
    enqueue(&q, lagu1);
    enqueue(&q, lagu2);
    enqueue(&q, lagu3);

    printf("Queue is empty: %s\n", isEmpty(q) ? "true" : "false");
    printf("Queue is full: %s\n", isFull(q) ? "true" : "false");
    printf("Queue length: %d\n", length(q));

    displayQueue(q);

    printf("Dequeue an element\n");
    dequeue(&q, &val);

    printf("Dequeued value: %s, %d\n", val.nama_lagu, val.album_id);
    printf("Queue is empty: %s\n", isEmpty(q) ? "true" : "false");
    printf("Queue is full: %s\n", isFull(q) ? "true" : "false");
    printf("Queue length: %d\n", length(q));

    displayQueue(q);

    return 0;
}
