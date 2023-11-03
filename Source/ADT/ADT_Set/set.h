#ifndef set_H
#define set_H
#include <stdio.h>
#include "boolean.h"

/* MODUL Set
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/
#define Nil 0
#define MaxEl 100

typedef char* title;
typedef char* infotype;

typedef struct {
    title lagu_nama[MaxEl];
    int album_id;
    int count; // Menambahkan variabel count untuk menghitung elemen
} Lagu;

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
void InsertLagu(Lagu *S, infotype Elmt);
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteLagu(Lagu *S, infotype Elmt);
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberLagu(Lagu S, infotype Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

void DisplayLagu(Lagu S);

#endif