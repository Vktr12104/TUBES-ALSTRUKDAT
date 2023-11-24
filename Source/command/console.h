
#include "../ADT/ADT_List/listdinamis.h"
#include "../ADT/ADT_List/liststatis.h"
#include "../ADT/ADT_Mesin-Kata/mesinkata.h"
#include "../ADT/ADT_Queue/circular_queue.h"
#include "../ADT/ADT_List/liststatis.h"
#include "../ADT/ADT_Map/map.h"
#include "../ADT/ADT_Set/set.h"
#include "../ADT/ADT_LinkedList/listb.h"
#include "../ADT/ADT_List/listdinamis.h"
#include "../ADT/ADT_Stack/stack.h"

#ifndef CONSOLE_H
#define CONSOLE_H


//LIST COMMAND START

void STARTREAD(ListPenyanyi * LP, SetLagu *lagu2,MapAlbum *m2,ListDinamik *daftarplaylist, char NamaFile []);

// LIST COMMAND PLAYLIST

void CreatePlayList(ListDinamik *DaftarPlaylist);

void PLAYLISTADDSONG(ListPenyanyi lp, MapAlbum m2,SetLagu S ,ListDinamik *daftarplaylist);

void PLAYLISTADDALBUM(ListPenyanyi lp, MapAlbum m2,SetLagu S ,ListDinamik *daftarplaylist);

void PLAYLISTSWAP(ListDinamik *DaftarPlaylist);

void PLAYLISTREMOVE(ListDinamik *DaftarPlaylist);

void PLAYLISTDELETE(ListDinamik *DaftarPlaylist);



// LIST COMMAND QUEUE

void QueSong(ListPenyanyi lp, MapAlbum m2,SetLagu S ,QueueLagu *Ql);
/*I.S. List pada lagu sudah terdefinisi*/
/*F.S. Memasukkan lagu yang dipilih ke dalam antrian*/
void QueSwap(QueueLagu *q) ;


void QueMove(QueueLagu *Q);

void QueClear(QueueLagu *Q);

void SongNext(HistoriLagu *HS, QueueLagu *Q);

void SongPrev(HistoriLagu *HS,QueueLagu *Q);

void save (ListPenyanyi p,MapAlbum al ,SetLagu lg, QueueLagu QL, HistoriLagu HL, ListDinamik LD);

void QUIT (ListPenyanyi p,MapAlbum al ,SetLagu lg, QueueLagu QL, HistoriLagu HL, ListDinamik LD);

void help(boolean start);

void invalidCommand(Word* w);

void NotPlaying ();

void statuscurrent(QueueLagu Q,ListDinamik LD);
/**
 * Membuat playlist yang dimainkan menjadi tidak ada/idx undef
*/
void NotPlayingPlaylist();

/**
 * Mengembalikan nilai true jika tidak ada playlist yang dimainkan
*/
boolean isNotPlayingPlaylist();

/**
 * Mengembalikan nilai true jika tidak ada lagu yang dimainkan
*/
boolean isNotPlaying();

void welcome();

#endif