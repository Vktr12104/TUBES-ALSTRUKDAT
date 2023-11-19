#include <stdio.h>
#include <stdlib.h>
#include "ADT/struc.h"
#include "ADT/ADT_Mesin-Kata/mesinkata.h"
#include "ADT/ADT_Queue/queue.h"
#include "ADT/ADT_Queue/circular_queue.h"
#include "ADT/ADT_List/liststatis.h"
#include "ADT/ADT_Map/map.h"
#include "ADT_Set/set.h"
#include "ADT/ADT_LinkedList/listb.h"
#include "ADT/ADT_List/listdinamis.h"

void QueSong(ListPenyanyi lp, MapAlbum m2,SetLagu S ,QueueLagu *Ql) {
    QueueLagu Q;
    CreateQueue(&Q);\

    printf("Daftar Penyanyi:\n");
    DisplayListPenyanyi(lp);

    printf("Masukkan Nama Penyanyi: ");
    STARTCOMMAND();
    char *comm=wordToString(currentCommand);
    int idxpenyanyi=albumtoidpenyanyi(lp,currentCommand);

    printf("Daftar Album oleh %s:\n",comm);
    displayMapAlbum(m2,idxpenyanyi);

    printf("Masukkan Nama Album yang dipilih: ");
    STARTCOMMAND();
    char *comm1=wordToString(currentCommand);
    int idxalbum=laguAlbumID(currentCommand,m2);
    
    printf("Daftar Lagu Album %s oleh %s\n : ",comm1,comm);
    DisplaySetLagu(S,idxalbum);

    printf("Masukkan ID Lagu yang dipilih: ");
    STARTCOMMAND();
    int idxlagu=wordToInt(currentCommand);
    Word namalagu=namalagufromalbum(S,idxalbum,idxlagu);
    if (!isFull(*Ql)){
        prinf("Queue Lagu Penuh!\n");
    }else{
        Cenqueue(&Q,idxpenyanyi,idxalbum,idxlagu);
        printf("Berhasil menambahkan lagu %s oleh %s ke queue.\n", namalagu, comm);
    }
}

void QueList(List *playlists, QueueLagu *Ql) {
    printf("Masukkan ID PlayList : ");
    STARTCOMMAND();
    int x = wordToInt(currentCommand);

    if (x >= playlists->NEff) {
        printf("Queue Playlist gagal. ID Playlist tidak ditemukan!\n");
    } else {
        ListPlaylist ply = playlists->A[x];
        address P = ply.First;
        while (P != NULL) {
            Cenqueue(Ql, P->Penyanyi_playlist, P->album_playlist, P->lagu_playlist);
            P = P->next;
        }printf("Berhasil menambahkan playlist %s ke queue.\n", ply.NamaPlayList.TabWord);
    }
}

    

/*I.S. List Pada Playlist sudah terdefinisi*/
/*F.S. Memasukkan lagu pada playlist yang dipilih ke dalam antrian */

void QueSwap(QueueLagu *q) {
    QueueLagu Qtemp;
    int idxtemp,idxtemp1,idxtemp2;
    int idxpenyanyi1,idxalbum1,idxlagu1;
    int idxpenyanyi2,idxalbum2,idxlagu2;
    CreateQueue(&Qtemp);

    STARTCOMMAND();
    int x = wordToInt(currentCommand);
    STARTCOMMAND();
    int y = wordToInt(currentCommand);

    int i = 0;
    while (!isEmpty(*q)) {
        Cdequeue(q,&idxtemp,&idxtemp1,&idxtemp2);
        if (i == x) {
            idxpenyanyi1=idxtemp;
            idxalbum1=idxtemp1;
            idxlagu1=idxtemp2;
        }

        if (i == y) {
            idxpenyanyi2=idxtemp;
            idxalbum2=idxtemp1;
            idxlagu2=idxtemp2;
        }

        Cenqueue(&Qtemp,idxtemp,idxtemp1,idxtemp2);
        i++;
    }

    int j = 0;
    while (!isEmpty(Qtemp)) {
        Cdequeue(&Qtemp,&idxtemp,&idxtemp1,&idxtemp2);
        if (j == x) {
            idxtemp=idxpenyanyi2;
            idxtemp1=idxalbum2;
            idxtemp2=idxlagu2;
        }
        if (j == y) {
            idxtemp=idxpenyanyi1;
            idxtemp1=idxalbum1;
            idxtemp2=idxlagu1;
        }
        Cenqueue(q,idxtemp,idxtemp1,idxtemp2);
        j++;
    }
}
/*I.S. Antrian pada lagu sudah terdefinisi */
/*F.S. Melakukan pertukaran lagu pada queue */
void QueMove(QueueLagu *Q){
    QueueLagu Qtemp;
    CreateQueue(&Qtemp);
    int idxtemp,idxtemp1,idxtemp2;
    STARTCOMMAND();
    int x= wordToInt(currentCommand);
    if(x>CLength(*Q)){
        printf("Lagu dengan urutan ke %d tidak ada.",x);
    }else{
        while(!isEmpty(*Q)){
            int i=0;
            Cdequeue(Q,&idxtemp,&idxtemp1,&idxtemp2);
            if (i+1!=x){
                Cenqueue(&Qtemp,idxtemp,idxtemp1,idxtemp2);
            }i++;
        }
    }*Q=Qtemp;
}
/*I.S. Antrian pada lagu sudah terdefinisi */
/*F.S. Menghapus Que pada urutan tertentu*/

void QueClear(QueueLagu *Q) {
    int idxtemp,idxtemp1,idxtemp2;
    while (!isEmpty(*Q)) {
        Cdequeue(Q,&idxtemp,&idxtemp1,&idxtemp2);
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