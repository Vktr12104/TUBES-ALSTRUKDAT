/* MODUL LIST INTEGER */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */

#ifndef ADTList1
#define ADTList1

#include "../ADT_Set/boolean.h"
#include "../ADT_Mesin-Kata/mesinkata.h"
#include <stdio.h>
#include <stdlib.h>
#include "../struc.h"
#include "../ADT_LinkedList/listb.h"

/* Kamus Umum */
#define MaxEl 100
#define InvalidIdx -1  /* Indeks tak terdefinisi */

/* Definisi elemen dan koleksi objek */
#define IdxType int

typedef struct {
	listBerkait *A;  /* Memori tempat penyimpanan elemen (container) */
	int NEff;
	int Max;
} ListD;

extern ListD list_dinamis ;
#define list(i) L.A[i]

/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah List, cara deklarasi dan akses: */
/* Deklarasi: L : List */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen list
 * L.A[i] untuk mengakses elemen ke-i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
ListD MakeList();
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(ListD L);
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(ListD L);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */
IdxType FirstIdx(ListD L);
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType LastIdx(ListD L);
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (ListD L, IdxType i);
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/

boolean IsIdxEff (ListD L, IdxType i);
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang valid utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */
boolean IsMemberdinamis(ListD L, ListPlaylist X);
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

void InsertFirst(ListD *L, Word nama);
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

void InsertAt(ListD *L, Word nama, IdxType i) ;
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLast(ListD *L, Word nama );
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void DeleteFirst(ListD *L);
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

void DeleteAt(ListD *L, IdxType i);
#endif