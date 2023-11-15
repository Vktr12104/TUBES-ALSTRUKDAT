#ifndef set_H
#define set_H
#include <stdio.h>
#include "boolean.h"
#include "../ADT_Mesin-Kata/mesinkata.h"
# include "../struc.h"


/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyListLagu(ListLagu *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */


/* ********* Predikat Untuk test keadaan KOLEKSI ********* */

boolean IsEmptyListLagu(ListLagu W);
/* Mengirim true jika Set S kosong*/

/* ********** Operator Dasar Lagu ********* */
void InsertListLagu(ListLagu *S, Word Elmt,int idalbum);
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

boolean IsMemberLagu(ListLagu S, Word Elmt);
/* True jika Elmt sudah member dari ListLagu*/

void DisplayListLagu(ListLagu S, int idalbum);

#endif