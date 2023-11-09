#ifndef map_H
#define map_H
#include "struct.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */
/* Membuat Album kosong (A.lagu_length = Nil) sebagai Map dari Lagu */
void CreateMapLagu(Album* A);

/* Membuat Penyanyi kosong (P.album_length = Nil) sebagai Map dari Album */
void CreateMapAlbum(Penyanyi* P);

/* Mengirim true jika lagu Album A kosong (A.lagu_length = Nil) */
boolean IsEmptyMapLagu(Album A);

/* Mengirim true jika album Penyanyi P kosong (P.album_length = Nil) */
boolean IsEmptyMapAlbum(Penyanyi P);

/* Mengirim true jika lagu Album A penuh (A.lagu_length = MaxEl) */
boolean IsFullMapLagu(Album A);

/* Mengirim true jika album Penyanyi P penuh (P.album_length = MaxEl) */
boolean IsFullMapAlbum(Penyanyi P);

/* Mengembalikan true jika Key K adalah member dari Album A */
boolean IsMemberMapLagu(Album A, Key K);

/* Mengembalikan true jika Key K adalah member dari Penyanyi P */
boolean IsMemberMapAlbum(Penyanyi P, Key K);

/* ### Operator Dasar Map ### */
/* Mendapatkan indeks sebuah Album pada Penyanyi */
int IndexOfAlbum(Penyanyi P, Album A);

/* Mendapatkan indeks sebuah Penyanyi pada List Penyanyi  */
int IndexOfPenyanyi(ListPenyanyi LP, Penyanyi P);

/* Mengembalikan nilai value Lagu dengan Key K dari Album A */
Lagu ValueMapLagu(Album A, Key K);

/* Mengembalikan nilai value Album dengan Key K dari Penyanyi P */
Album ValueMapAlbum(Penyanyi P, Key K);

/* Menambahkan array of character (Title) ST sebagai value elemen Album A dengan Key K. */
void InsertMapLagu(Penyanyi* P, Album* A, Title* ST);

/* Menambahkan array of character (Title) AT sebagai value elemen Penyanyi P dengan Key K. */
void InsertMapAlbum(ListPenyanyi* LP, Penyanyi P, Title AT);

/* Menghapus array of character (Title) ST sebagai value elemen Album A dengan Key K. */
void DeleteMapLagu(Album *A, Key K);

/* Menghapus array of character (Title) AT sebagai value elemen Penyanyi P dengan Key K. */
void DeleteMapAlbum(Penyanyi *P, Key K);

#endif

