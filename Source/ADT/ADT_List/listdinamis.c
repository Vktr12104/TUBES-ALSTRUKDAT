#include "listdinamis.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
ListD MakeList() {
    ListD L;
    L.A = (ListPlaylist*)malloc(MaxEl * sizeof(ListPlaylist));
    L.NEff = 0;
    L.Max = MaxEl;
    return L;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(ListD L) {
    return L.NEff == 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(ListD L) {
    return L.NEff;
}

/* *** Selektor INDEKS *** */
IdxType FirstIdx(ListD L) {
    return 0;
}

IdxType LastIdx(ListD L) {
    return L.NEff - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(ListD L, IdxType i) {
    return (i >= 0) && (i < L.Max);
}

boolean IsIdxEff(ListD L, IdxType i) {
    return (i >= 0) && (i < L.NEff);
}

/* ********** Operasi-operasi ********** */
boolean IsMemberdinamis(ListD L, ListPlaylist X) {
    int i;
    for (i = 0; i < L.NEff; i++) {
        if (StrComp(X.playlist->playlist_nama,L.A[i].NamaPlaylist)) {
            return true;
        }
    }
    return false;
}

void InsertFirst(ListD *L, Word nama) {
    if (L->NEff < L->Max) {
        int i;
        for (i = L->NEff; i > 0; i--) {
            L->A[i] = L->A[i - 1];
        }
        *L->A[0].NamaPlaylist = nama;
        L->NEff++;
    }
}

void InsertAt(ListD *L, Word nama, IdxType i) {
    if (L->NEff < L->Max && IsIdxEff(*L, i)) {
        int j;
        for (j = L->NEff; j > i; j--) {
            L->A[j] = L->A[j - 1];
        }
        *L->A[i].NamaPlaylist=nama;
        L->NEff++;
    }
}
void InsertLast(ListD *L, Word nama ) {
    if (L->NEff < L->Max) {
        *L->A[L->NEff].NamaPlaylist = nama;
        L->NEff++;
    }
}

void DeleteFirst(ListD *L) {
    if (!IsEmpty(*L)) {
        int i;
        for (i = 0; i < L->NEff - 1; i++) {
            L->A[i] = L->A[i + 1];
        }
        L->NEff--;
    }
}

void DeleteAt(ListD *L, IdxType i) {
    if (!IsEmpty(*L) && IsIdxEff(*L, i)) {
        int j;
        for (j = i; j < L->NEff - 1; j++) {
            L->A[j] = L->A[j + 1];
        }
        L->NEff--;
    }
}
