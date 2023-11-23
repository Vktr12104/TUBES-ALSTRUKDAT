#ifndef __load__
#define __load__

#include <stdio.h>
#include <stdlib.h>
#include "../ADT/ADT_List/liststatis.h"
#include "../ADT/ADT_List/listdinamis.h"
#include "../ADT/ADT_MesinKarakter/mesinkarakter.h"
#include "../ADT/ADT_Mesin-Kata/mesinkata.h"
#include "playlist.h"
#include "../ADT/ADT_Queue/circular_queue.h"
#include "../ADT/ADT_Stack/stack.h"
#include "start.h"
#include "../ADT/struc.h"

boolean CekLoad (char* NamaFile);

void Load(ListPenyanyi* Penyanyi,MapAlbum* Album, SetLagu* SetLagu, char* NamaFile, QueueLagu* QueueLagu, HistoriLagu* HistoryLagu, ListDinamik ListPlaylist, status *LaguSekarang);

#endif