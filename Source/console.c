#include <stdio.h>
#include <stdlib.h>
#include "ADT/struc.h"
#include "ADT/ADT_Mesin-Kata/mesinkata.h"
#include "ADT/ADT_Queue/queue.h"
#include "ADT/ADT_Queue/circular_queue.h"
#include "ADT/ADT_List/liststatis.h"
#include "ADT/ADT_Map/map.h"
#include "ADT/ADT_Set/set.h"
#include "ADT/ADT_LinkedList/listb.h"
#include "ADT/ADT_List/listdinamis.h"
#include "ADT/ADT_Stack/stack.h"


void QueSong(ListPenyanyi lp, MapAlbum m2,SetLagu S ,QueueLagu *Ql) {
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
    char *comm3=wordToString(namalagu);
    if (CIsFull(*Ql)){
        printf("Queue Lagu Penuh!\n");
    }else{
        printf("Berhasil masuk\n");
        Cenqueue(Ql,comm,comm1,comm3);
        printf("Berhasil menambahkan lagu %s oleh %s ke queue.\n",comm3, comm);
    }
}

void QueList(ListD list_dinamis, QueueLagu *Ql) {
    printf("Masukkan ID PlayList : ");
    STARTCOMMAND();
    int x = wordToInt(currentCommand);

    if (x >= list_dinamis.NEff) {
        printf("Queue Playlist gagal. ID Playlist tidak ditemukan!\n");
    } else {
        listBerkait ply = list_dinamis.A[x];
        address P = First(ply);
        while (P != NULL) {
            Cenqueue(Ql,P->infoplaylist.Penyanyi_playlist, P->infoplaylist.album_playlist,P->infoplaylist.lagu_playlist);
            P=Next(P);
        }printf("Berhasil menambahkan playlist %s ke queue.\n", ply.NamaPlaylist);
    }
}
    

/*I.S. List Pada Playlist sudah terdefinisi*/
/*F.S. Memasukkan lagu pada playlist yang dipilih ke dalam antrian */

void QueSwap(QueueLagu *q) {
    QueueLagu Qtemp;
    char *penyanyi1, *album1, *lagu1;
    char *penyanyi2, *album2, *lagu2;
    char *Penyanyitemp, *albumtemp, *lagutemp;
    CCreateQueue(&Qtemp);

    STARTCOMMAND();
    int x = wordToInt(currentCommand);
    STARTCOMMAND();
    int y = wordToInt(currentCommand);
    if (x > q->idxTail && y > q->idxTail) {
        if (x > q->idxTail) {
            printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", x);
        } else {
            printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", y);
        }
    } else {
        int i = 0;
        while (!CIsEmpty(*q)) {
            Cdequeue(q, Penyanyitemp, albumtemp, lagutemp);
            if (i == x) {
                *penyanyi1 = *Penyanyitemp;
                *album1 = *albumtemp;
                *lagu1 = *lagutemp;
            }

            if (i == y) {
                *penyanyi2 = *Penyanyitemp;
                *album2 = *albumtemp;
                *lagu2 = *lagutemp;
            }

            Cenqueue(&Qtemp, Penyanyitemp, albumtemp, lagutemp);
            i++;
        }

        int j = 0;
        while (!CIsEmpty(Qtemp)) {
            Cdequeue(&Qtemp, Penyanyitemp, albumtemp, lagutemp);
            if (j == x) {
                *Penyanyitemp = *penyanyi2;
                *albumtemp = *album2;
                *lagutemp = *lagu2;
            }
            if (j == y) {
                *Penyanyitemp = *penyanyi1;
                *albumtemp = *album1;
                *lagutemp = *lagu1;
            }
            Cenqueue(q, Penyanyitemp, albumtemp, lagutemp);
            j++;
        }printf("Lagu %s berhasil ditukar dengan %s \n",lagu1,lagu2);
    }
}

/*I.S. Antrian pada lagu sudah terdefinisi */
/*F.S. Melakukan pertukaran lagu pada queue */
void QueMove(QueueLagu *Q){
    QueueLagu Qtemp;
    CCreateQueue(&Qtemp);
    char *Penyanyitemp, *albumtemp, *lagutemp;
    STARTCOMMAND();
    int x = wordToInt(currentCommand);
    
    if (x > CLength(*Q)) {
        printf("Lagu dengan urutan ke %d tidak ada.\n", x);
    } else {
        int i = 0;
        while (!CIsEmpty(*Q)) {
            Cdequeue(Q, Penyanyitemp, albumtemp, lagutemp);
            if (i + 1 != x) {
                Cenqueue(&Qtemp, Penyanyitemp, albumtemp, lagutemp);
            }
            i++;
        }
    }
    *Q = Qtemp;
}

/*I.S. Antrian pada lagu sudah terdefinisi */
/*F.S. Menghapus Que pada urutan tertentu*/

void QueClear(QueueLagu *Q) {
    char *Penyanyitemp,*albumtemp,*lagutemp;
    while (!CIsEmpty(*Q)) {
        Cdequeue(Q,Penyanyitemp,albumtemp,lagutemp);
    }printf("Queue berhasil dikosongkan");
}

/*I.S. Antrian pada lagu sudah terdefinisi */
/*F.S. Menghapus semua lagu pada queue*/    
void SongNext(HistoriLagu *HS, QueueLagu *Q){
    boolean isNotPlaying=true; 
    if(isNotPlaying && CIsEmpty(*Q)){
        printf("Queue kosong dan tidak ada lagu yang sedang dimainkan\n");
    }else if(CIsEmpty(*Q)) {
        printf("Queue kosong, memutar kembali lagu\n");
        printf("\"%s\" oleh \"%s\"",current.lagu,current.penyanyi);
    }else{
        PushLagu(HS,current.lagu,current.album,current.penyanyi);
        Cdequeue(Q,current.lagu,current.album,current.penyanyi);
        printf("Memutar lagu selanjutnya\n");
        printf("\"%s\" oleh \"%s\"",current.lagu,current.lagu);
    }
}

/*I.S. Antrian pada lagu sudah terdefinisi  */
/*F.S. Jika keadaan belum memutar lagu tetapi sudah ada que maka akan memuta lagu pada que, Jika sedang memutar lagu 
maka lagu akan dimasukkan pada History Lagu dan memutar lagu pada queue*/
void SongPrev(HistoriLagu *HS,QueueLagu *Q){
    QueueLagu Qtemp;
    char *lagutemp,*albumtemp,*penyanyitemp;
    CCreateQueue(&Qtemp);
    if(IsHistEmpty(*HS)){
        printf("History kosong, memutar kembali lagu\n");
        printf("\"%s\" oleh \"%s\"",current.lagu,current.penyanyi);
    }else{
        Cenqueue(&Qtemp,current.penyanyi,current.album,current.lagu);
        while(!CIsEmpty(*Q)){
            Cdequeue(Q,penyanyitemp,albumtemp,lagutemp);
            Cenqueue(&Qtemp,penyanyitemp,albumtemp,lagutemp);
        }while(CIsEmpty(Qtemp)){
            Cdequeue(&Qtemp,penyanyitemp,albumtemp,lagutemp);
            Cenqueue(Q,penyanyitemp,albumtemp,lagutemp);
        }PopLagu(HS,(current).lagu,(current).album,(current).penyanyi);
        printf("Memutar lagu sebelumnya\n");
        printf("\"%s\" oleh \"%s\"", current.lagu, current.penyanyi);
    }
}
/*I.S. History  pada lagu sudah terdefinisi  */
/*F.S Memutar lagu pada history lagu, jika belum ada dan baru memutar laguu yang diputar maka lagu 
lagu yang sedang diputar*/

void save (ListPenyanyi p,MapAlbum al ,SetLagu lg){
    FILE* input = fopen("C:/Users/USER/Documents/STI Semester 3/Alstrukdat/Tubes 1/TUBES-ALSTRUKDAT/save/test.txt", "w");
    Word tempPenyanyi, tempAlbum, tempLagu, tempPlaylist, tempInt;
    int NPenyanyi, NAlbum, NLagu, NQueue, NRiwayat, NPlaylist;
    fprintf(input, "%d\n", p.NEff);
    int counter=1;
    int counter2=0;
    for (int i = 0; i < p.NEff; i++){
        int jumlahalbumperpenyanyi2 = jumlahalbumperpenyanyi(al,i);
        fprintf(input,"%d ", jumlahalbumperpenyanyi2);
        for (int a=0;a<p.A[i].Length;a++){
            if (a<p.A[i].Length-1){
                fprintf(input,"%c",p.A[i].TabWord[a]);      
            }
            else{
                fprintf(input,"%c\n",p.A[i].TabWord[a]);   
            }
        }
        for (int j = 0;j<jumlahalbumperpenyanyi2;j++){
            int jumlahlagu = CountLaguByAlbumID(&lg,counter);
            fprintf(input, "%d ", jumlahlagu);
            for (int b=0 ; b<al.Elements[counter].nama_album.Length;b++){
                if (b<al.Elements[counter].nama_album.Length-1){
                    fprintf(input,"%c",al.Elements[counter].nama_album.TabWord[b]);      
                }
                else{
                    fprintf(input,"%c\n",al.Elements[counter].nama_album.TabWord[b]);   
                }
            }
            counter++;
            for (int k=0;k<jumlahlagu;k++){
                counter2++;
                for (int c=0 ; c<lg.A[counter2].nama_lagu.Length;c++){
                    if (c<lg.A[counter2].nama_lagu.Length-1){
                        fprintf(input,"%c",lg.A[counter2].nama_lagu.TabWord[c]);      
                    }
                    else{
                        fprintf(input,"%c\n",lg.A[counter2].nama_lagu.TabWord[c]);   
                    }
                }
            }
        }
    }
    fclose(input);
    printf("Save file berhasil disimpan.\n");
    printf("// File disimpan pada /save/savefile.txt\n");
}