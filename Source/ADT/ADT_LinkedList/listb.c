# include <stdio.h>
# include <stdlib.h>
# include "listb.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptylistb (listBerkait L) {
    if (First(L) == NULL) {
        return true;
    }
    else {
        return false;
    }
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptylistb (listBerkait *L) {
    First(*L) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasilistb (char *penyanyi, char *album, char *lagu) {
    address P;
    P = (ElmtList *) malloc(sizeof(ElmtList));
    if (P!= NULL) {
        P->infoplaylist.Penyanyi_playlist=*penyanyi;
        P->infoplaylist.album_playlist=*album;
        P->infoplaylist.lagu_playlist=*lagu;
        Next(P) = NULL;
    }
    return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
void Dealokasilistb (address *P) {
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Searchlistb (listBerkait L, char *kata) {
    address P;
    boolean found;

    P = First(L);
    found = false;
    while ((P != NULL) && (!found)) {
        if (StrComp(P->infoplaylist.lagu_playlist,kata)) {
            found = true;
        }
        else {
            P = Next(P);
        }
    }
    return P;
}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */

/****************** PRIMITIF BERDASARKAN NULLAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstlistb (listBerkait *L,char *penyanyi,  char *album,  char *lagu ) {
    address P;
    P = Alokasi(penyanyi,album,lagu);
    if (P != NULL) {
        Next(P) = First(*L);
        First(*L) = P;
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan NULLai X jika alokasi berhasil */
void InsVLastlistb (listBerkait *L, char *penyanyi,  char *album,  char *lagu) {
    address P;
    P = Alokasi(penyanyi,album,lagu);
    if (P != NULL) {  
        InsertLastlistb(L,P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNULLai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstlistb (listBerkait *L, Isi_Que *X) {
    address P;

    DelFirstlistb(L, &P);
    *X->lagu_playlist = Info(P).lagu_playlist;
    Dealokasilistb(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: NULLai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastlistb (listBerkait *L, Isi_Que *X) {
    address P;

    DelLastlistb(L, &P);
    *X->lagu_playlist = Info(P).lagu_playlist;
    Dealokasilistb(&P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: NULLai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstlistb (listBerkait *L, address P) {
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfterlistb (listBerkait *L, address P, address Prec) {
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLastlistb (listBerkait *L, address P) {
    if (IsEmptylistb(*L)){ // empty list
        Next(P) = NULL;
        First(*L) = P;
    }
    else{
        address last = First(*L);

        while(Next(last) != NULL) {
            last = Next(last);
        }

        InsertAfter(L, P, last);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstlistb (listBerkait *L, address *P) {
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = NULL;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelPlistb (listBerkait *L, char *lagu) {
    address P = Searchlistb(*L, lagu);

    if (P != NULL){   // Found
        address prec = First(*L);

        if (prec == P){ // If its on first element
            DelFirst(L, &P);
        }
        else {

            while(Next(prec) != P) { // search for the predecesor
                prec = Next(prec);
            }

            DelAfter(L, &P, prec);
        }
    }
    Dealokasi(&P);
}

/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLastlistb (listBerkait *L, address *P) {
    if (Next(First(*L)) == NULL){    // 1 element only

        *P = First(*L);
        CreateEmpty(L);

    }
    else {
        address prec = First(*L);

        while(Next(Next(prec)) != NULL) {
            prec = Next(prec);
        }

        // Next Next (prec ) == NULL , got the prec of last element

        DelAfter(L, P, prec);

    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfterlistb (listBerkait *L, address *Pdel, address Prec) {
    address P;
    boolean found;

    P = First(*L);
    found = false;
    while ((P != NULL) && (!found)) {
        if (P == Prec) {
            found = true;
        }
        else {
            P = Next(P);
        }
    }

    *Pdel = Next(P);
    Next(P) = Next(Next(P));
    Next(*Pdel) = NULL;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfolistb(listBerkait L) {
    printf("[");
    if (!IsEmptylistb(L)) {
        address CP = First(L);
        do {
            printf("%.*s", Info(CP).lagu_playlist, Info(CP).lagu_playlist);
            CP = Next(CP);
            if (CP != NULL) {
                printf(",");
            }
        } while (CP != NULL);
    }
    printf("]");
}

/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNULLai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmtlistb (listBerkait L) {
    int count;
    address P;

    count = 0;
    P = First(L);
    while (P != NULL) {
        count++;
        P = Next(P);
    }

    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/

void InversListlistb (listBerkait *L) {
    address P, Prec, Last;

    P = First((*L));
    Prec = NULL;

    while (P != NULL) {
        Last = P;
        P = Next(P);
        Next(Last) = Prec;
        Prec = Last;
    }
    First(*L) = Last;
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void Konkat1listb (listBerkait *L1, listBerkait *L2, listBerkait *L3) {
    CreateEmpty(L3);

    if (!(IsEmptylistb(*L1))){
        First(*L3) = First(*L1);

        address last1 = First(*L1);

        while(Next(last1) != NULL) {
            last1 = Next(last1);
        }

        Next(last1) = First(*L2);
    }
    else{
        First(*L3) = First(*L2);
    }


    CreateEmpty(L1);
    CreateEmpty(L2);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

boolean IsMemberlistb(listBerkait S, char* Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    boolean found = false;
    address P = First(S);
    while (P!=Nil){
        if (StrComp(Info(P).lagu_playlist,Elmt)){
            found = true;
            break;
        }
        P = Next(P);
    }
    return found;
}