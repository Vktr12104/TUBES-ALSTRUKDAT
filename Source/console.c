#include <stdio.h>
#include <stdlib.h>
#include "ADT/struc.h"
#include "ADT/ADT_Mesin-Kata/mesinkata.h"
#include "ADT/ADT_Queue/queue.h"
#include "ADT/ADT_Queue/circular_queue.h"
#include "ADT/ADT_List/liststatis.h"

void QueSong(ListPenyanyi lp, QueueLagu *Ql) {
    QueueLagu Q;
    CreateQueue(&Q);

    printf("Daftar Penyanyi:\n");
    for (int i = 0; i < lp.penyanyi_length; i++) {
        printf("%d. %s\n", i + 1, lp.penyanyi[i].nama_penyanyi);
    }

    printf("Masukkan Nama Penyanyi: ");
    STARTCOMMAND();
    char *comm = wordToString(currentCommand);

    Penyanyi P;
    for (int i = 0; i < lp.penyanyi_length; i++) {
        if (StrComp(comm, lp.penyanyi[i].nama_penyanyi) == 0) {
            P = lp.penyanyi[i];
            break;
        }
    }

    printf("Daftar Album oleh %s:\n", comm);
    for (int i = 0; i < P.album_length; i++) {
        printf("%d. %s\n", i + 1, P.album_penyanyi[i].nama_album);
    }

    printf("Masukkan Nama Album yang dipilih: ");
    STARTCOMMAND();
    char *comm1 = wordToString(currentCommand);

    Album get;
    for (int i = 0; i < P.album_length; i++) {
        if (StrComp(comm1, P.album_penyanyi[i].nama_album) == 0) {
            get = P.album_penyanyi[i];
            break;
        }
    }

    printf("Daftar Lagu Album %s oleh %s:\n", comm1, comm);
    for (int i = 0; i < get.lagu_length; i++) {
        printf("%d. %s\n", i + 1, get.album_lagu[i].nama_lagu);
    }

    printf("Masukkan ID Lagu yang dipilih: ");
    STARTCOMMAND();
    char *comm2 = wordToString(currentCommand);

    Lagu lg;
    for (int i = 0; i < get.lagu_length; i++) {
        if (StrComp(comm2, get.album_lagu[i].album_id) == 0) {
            lg = get.album_lagu[i];
            break;
        }
    }
    enqueue(&Q, lg);
    printf("Berhasil menambahkan lagu %s oleh %s ke queue.\n", comm2, comm);
}


void QueList(LaguPlaylist Lp, QueueLagu *Ql){
    printf("Masukkan ID PlayList :");
    STARTCOMMAND();
    char *comm = wordToInt(currentCommand);
    
    
    
}

/*I.S. List Pada Playlist sudah terdefinisi*/
/*F.S. Memasukkan lagu pada playlist yang dipilih ke dalam antrian */

void QueSwap(QueueLagu *q) {
    QueueLagu Qtemp;
    Lagu temp1, temp2;
    CreateQueue(&Qtemp);

    STARTCOMMAND();
    int x = wordToInt(currentCommand);
    STARTCOMMAND();
    int y = wordToInt(currentCommand);

    int i = 0;
    while (!isEmpty(*q)) {
        Lagu item = Cdequeue(q);
        if (i == x) {
            temp1 = item;
        }

        if (i == y) {
            temp2 = item;
        }

        Cenqueue(&Qtemp, item);
        i++;
    }

    int j = 0;
    while (!isEmpty(Qtemp)) {
        Lagu item = Cdequeue(&Qtemp);

        if (j == x) {
            item = temp2;
        }

        if (j == y) {
            item = temp1;
        }

        Cenqueue(q, item);
        j++;
    }
}
/*I.S. Antrian pada lagu sudah terdefinisi */
/*F.S. Melakukan pertukaran lagu pada queue */
void QueMove(QueueLagu *Q){
    QueueLagu Qtemp;
    CreateQueue(&Qtemp);
    STARTCOMMAND();
    int x= wordToInt(currentCommand);
    if(x>CLength(*Q)){
        printf("Lagu dengan urutan ke %d tidak ada.",x);
    }else{
        while(!isEmpty(*Q)){
            int i=0;
            Lagu item=Cdequeue(Q);
            if (i+1!=x){
                Cenqueue(&Qtemp,item);
            }i++;
        }
    }*Q=Qtemp;
}
/*I.S. Antrian pada lagu sudah terdefinisi */
/*F.S. Menghapus Que pada urutan tertentu*/

void QueClear(QueueLagu *Q) {
    Lagu l;
    while (!isEmpty(*Q)) {
        dequeue(Q, &l); 
    }
}

/*I.S. Antrian pada lagu sudah terdefinisi */
/*F.S. Menghapus semua lagu pada queue*/    
void SongNext(HistoriLagu *HS, QueueLagu *Q){
    boolean isNotPlaying=true; 
    if(isNotPlaying && isEmpty(*Q)){
        printf("Queue kosong dan tidak ada lagu yang sedang dimainkan");
    }else if(isEmpty(*Q)) {
        printf("Queue kosong, memutar kembali lagu\n");
        printf("\"%s\" oleh \"%s\""c);
    }else{

    }
}

/*I.S. Antrian pada lagu sudah terdefinisi  */
/*F.S. Jika keadaan belum memutar lagu tetapi sudah ada que maka akan memuta lagu pada que, Jika sedang memutar lagu 
maka lagu akan dimasukkan pada History Lagu dan memutar lagu pada queue*/
void SongPrev(HistoriLagu *HS);
/*I.S. History  pada lagu sudah terdefinisi  */
/*F.S Memutar lagu pada history lagu, jika belum ada dan baru memutar laguu yang diputar maka lagu 
lagu yang sedang diputar*/