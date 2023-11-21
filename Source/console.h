
#include "ADT/ADT_List/listdinamis.h"
#include "ADT/ADT_List/liststatis.h"
#include "ADT/ADT_Map/map.h"
#include "ADT/ADT_Mesin-Kata/mesinkata.h"
#include "ADT/ADT_MesinKarakter/mesinkarakter.h"
#include "ADT/ADT_Queue/circular_queue.h"
#include "ADT/ADT_Queue/queue.h"
#include "ADT/ADT_Set/set.h"
#include "ADT/ADT_Stack/stack.h"

#ifndef CONSOLE_H
#define CONSOLE_H

// LIST COMMAND

void QueSong(ListPenyanyi lp, MapAlbum m2,SetLagu S ,QueueLagu *Ql);
/*I.S. List pada lagu sudah terdefinisi*/
/*F.S. Memasukkan lagu yang dipilih ke dalam antrian*/
void QueSwap(QueueLagu *q) ;


void QueMove(QueueLagu *Q);

void QueClear(QueueLagu *Q);

void SongNext(HistoriLagu *HS, QueueLagu *Q);

void SongPrev(HistoriLagu *HS,QueueLagu *Q);

void save (ListPenyanyi p,MapAlbum al ,SetLagu lg);

void QUIT (ListPenyanyi p,MapAlbum al ,SetLagu lg);

void help(boolean start);

#endif
