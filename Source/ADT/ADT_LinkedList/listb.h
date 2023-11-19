/* File : listb.h */
/* Contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah string */

#ifndef listb_H
#define listb_H

#include "../ADT_Set/boolean.h"
#include "../ADT_Mesin-Kata/mesinkata.h"
#include <stdio.h>
#include "../struc.h"

typedef char* infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
    isi_playlist infoplaylist;
    address next;
} ElmtList;
typedef struct {
    address First;
} listBerkait;

/* Definisi list: */
/* List kosong: First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list: jika addressnya Last, maka Next(Last) = Nil */
#define Info(P) (P)->infoplaylist
#define Next(P) (P)->next
#define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptylistb(listBerkait L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty(listBerkait *L);
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi(isi_playlist X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi(address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Searchlistb(listBerkait L, isi_playlist X);
/* Mencari apakah ada elemen list dengan info(P) = X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(listBerkait *L, isi_playlist X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast(listBerkait *L, isi_playlist X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S. = F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(listBerkait *L, isi_playlist *X);
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/* dan alamat elemen pertama di-dealokasi */
void DelVLast(listBerkait *L, isi_playlist *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstlistb(listBerkait *L, address P);
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter(listBerkait *L, address P, address Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLastlistb(listBerkait *L, address P);
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(listBerkait *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP(listBerkait *L, isi_playlist X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list ber-address P, dengan info(P) = X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast(listBerkait *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter(listBerkait *L, address *Pdel, address Prec);
/* I.S. List tidak kosong. Prec adalah anggota list */
/* F.S. Menghapus Next(Prec): */
/* Pdel adalah alamat elemen list yang dihapus */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo(listBerkait L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, ia list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh: jika ada tiga elemen bernilai "one", "two", "three" akan dicetak: ["one","two","three"] */
/* Jika list kosong: menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt(listBerkait L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/

void InversList(listBerkait *L);
/* I.S. sembarang. */
/* F.S. elemen list dibalik: */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void Konkat1(listBerkait *L1, listBerkait *L2, listBerkait *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list: L1 dan L2 */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */

/* Tidak ada alokasi/dealokasi pada prosedur ini */

#endif
