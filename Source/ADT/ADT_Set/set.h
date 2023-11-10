#ifndef set_H
#define set_H
#include <stdio.h>
#include "boolean.h"
# include "../struc.h"

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyLagu(Lagu *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */


/* ********* Predikat Untuk test keadaan KOLEKSI ********* */

boolean IsEmptyLagu(Lagu S);
/* Mengirim true jika Set S kosong*/

boolean IsFullLagu(Lagu S);
/* Mengirim true jika Lagu S penuh */


/* ********** Operator Dasar Lagu ********* */
void InsertLagu(Lagu *S, Title Elmt);
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

boolean IsMemberLagu(Lagu S, Title Elmt);

#endif