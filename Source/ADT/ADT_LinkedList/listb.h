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
    Title NamaPlaylist;
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
void CreateEmptylistb(listBerkait *L);
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */

void Dealokasilistb(address *P);
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Searchlistb (listBerkait L, char *kata) ;
/* Mencari apakah ada elemen list dengan info(P) = X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstlistb (listBerkait *L,char *penyanyi,  char *album,  char *lagu );
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLastlistb (listBerkait *L, char *penyanyi,  char *album,  char *lagu) ;
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S. = F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstlistb(listBerkait *L, Isi_Que *X);
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/* dan alamat elemen pertama di-dealokasi */
void DelVLastlistb(listBerkait *L, Isi_Que *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstlistb(listBerkait *L, address P);
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfterlistb(listBerkait *L, address P, address Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLastlistb(listBerkait *L, address P);
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstlistb(listBerkait *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelPlistb (listBerkait *L, char *lagu);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list ber-address P, dengan info(P) = X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLastlistb(listBerkait *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfterlistb(listBerkait *L, address *Pdel, address Prec);
/* I.S. List tidak kosong. Prec adalah anggota list */
/* F.S. Menghapus Next(Prec): */
/* Pdel adalah alamat elemen list yang dihapus */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfolistb(listBerkait L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, ia list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh: jika ada tiga elemen bernilai "one", "two", "three" akan dicetak: ["one","two","three"] */
/* Jika list kosong: menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmtlistb(listBerkait L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/

void InversListlistb(listBerkait *L);
/* I.S. sembarang. */
/* F.S. elemen list dibalik: */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void Konkat1listb(listBerkait *L1, listBerkait *L2, listBerkait *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list: L1 dan L2 */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */

/* Tidak ada alokasi/dealokasi pada prosedur ini */

boolean IsMemberlistb(listBerkait S, char* Elmt);

#endif