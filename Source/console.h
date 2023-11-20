#include "boolean.h"
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

void load (Word filename,Penyanyi p,Album al ,Lagu lg,boolean esc );
/* I.S. array kosong */
/* F.S. array terisi dengan list penyanyi, album dan lagu yang dapat ditampilkan ke dalam file eksternal yang disimpan */

void listDef(Penyanyi p); 
/*I.S. List Default Penyanyi terdefinisi*/
/*F.S. Menampilkan Daftar lagu penyanyi*/

void listPlay(ListPlaylist Lp);
/*I.S. List Playlist sudah terdefinisi*/
/*F.S. Menampilkan List Playlist yang dimiliki*/

void PlayLagu(Penyanyi p);
/*I.S. List lagu sudah terdefinisi*/
/*Memutar lagu sesuai yang dipilih dan dimasukkan ke dalam history*/

void Play2List(LaguPlaylist Lp);
/*I.S. List Pada Playlist sudah terdefinisi*/
/*F.S. Memutar Seluruh lagu pada playlist dan*/

void QueSong(Penyanyi P, QueueLagu* Ql);
/*I.S. List pada lagu sudah terdefinisi*/
/*F.S. Memasukkan lagu yang dipilih ke dalam antrian*/

void QueList(LaguPlaylist Lp, QueueLagu *Ql);
/*I.S. List Pada Playlist sudah terdefinisi*/
/*F.S. Memasukkan lagu pada playlist yang dipilih ke dalam antrian */

void QueSwap(QueueLagu *Ql,Lagu l,Lagu l2);
/*I.S. Antrian pada lagu sudah terdefinisi */
/*F.S. Melakukan pertukaran lagu pada queue */

void QueMove(QueueLagu *Ql);
/*I.S. Antrian pada lagu sudah terdefinisi */
/*F.S. Menghapus Que pada urutan tertentu*/

void QueClear(QueueLagu *Ql);
/*I.S. Antrian pada lagu sudah terdefinisi */
/*F.S. Menghapus semua lagu pada queue*/

void SongNext(HistoriLagu *HS, QueueLagu *Ql);
/*I.S. Antrian pada lagu sudah terdefinisi  */
/*F.S. Jika keadaan belum memutar lagu tetapi sudah ada que maka akan memuta lagu pada que, Jika sedang memutar lagu 
maka lagu akan dimasukkan pada History Lagu dan memutar lagu pada queue*/

void SongPrev(HistoriLagu *HS);
/*I.S. History  pada lagu sudah terdefinisi  */
/*F.S Memutar lagu pada history lagu, jika belum ada dan baru memutar laguu yang diputar maka lagu 
lagu yang sedang diputar*/

void CreatePlayList(NamaPlaylist *Pl);
/*I.S. PlayList belum ada */
/*F.S. Tercipta satu playlist*/

void AddLagu(Penyanyi p,LaguPlaylist *lp);
/*I.S. Lagu sudah terdefinsi dan sudah terdapat playlist */
/*F.S Menambahkan lagu pada playlist tertentu*/

void SwapLagu(LaguPlaylist *lp) ;
/*I.S. lagu lagu pada playlist sudah didefinisikan*/
/*F.S Berhasil menukar lagu pada playlist tertentu
*/

void MoveLagu(LaguPlaylist *lp);
/*I.S. lagu lagu pada playlist sudah didefinisikan*/
/*F.S. Menghapus lagu pada playlist tertentu*/

void MoveLagu(LaguPlaylist *lp);
/*I.S. lagu lagu pada playlist sudah didefinisikan*/
/*F.S. menghapus lagu pada urutan tertentu*/

void DelList(ListPlaylist *lp);
/*I.S. lagu lagu pada playlist sudah didefinisikan*/
/*F.S. Menghapus Playlist*/

void Status();
/*I.S. Status kondisi pemutaran lagu sudah terdefinisi*/
/*F.S. Mengeluarkan output status pemutaran lagu*/

void help();
/* I.S. sembarang */
/* F.S. mengembalikan output berupa daftar command yang dapat dimasukkan berikut fungsinya */

void save (Word filename,Penyanyi p,Album al ,Lagu lg);
/* I.S. array terdefinisi */
/* F.S. array disimpan dalam file eksternal */

void QUIT ();
/* I.S. sembarang */
/* F.S. keluar dari sesi*/

#endif
