#include "listdinamis.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
List MakeList() {
    List L;
    L.A = (ListPlaylist*)malloc(MaxEl * sizeof(ListPlaylist));
    L.NEff = 0;
    L.Max = MaxEl;
    return L;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(List L) {
    return L.NEff == 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(List L) {
    return L.NEff;
}

/* *** Selektor INDEKS *** */
IdxType FirstIdx(List L) {
    return 0;
}

IdxType LastIdx(List L) {
    return L.NEff - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(List L, IdxType i) {
    return (i >= 0) && (i < L.Max);
}

boolean IsIdxEff(List L, IdxType i) {
    return (i >= 0) && (i < L.NEff);
}

/* ********** Operasi-operasi ********** */
boolean IsMemberdinamis(List L, ListPlaylist X) {
    int i;
    for (i = 0; i < L.NEff; i++) {
        if (StrComp(X.playlist->playlist_nama,L.A[i].playlist->playlist_nama)) {
            return true;
        }
    }
    return false;
}

void InsertFirst(List *L, ListPlaylist X) {
    if (L->NEff < L->Max) {
        int i;
        for (i = L->NEff; i > 0; i--) {
            L->A[i] = L->A[i - 1];
        }
        L->A[0] = X;
        L->NEff++;
    }
}

void InsertAt(List *L, ListPlaylist X, IdxType i) {
    if (L->NEff < L->Max && IsIdxEff(*L, i)) {
        int j;
        for (j = L->NEff; j > i; j--) {
            L->A[j] = L->A[j - 1];
        }
        L->A[i] = X;
        L->NEff++;
    }
}

void InsertLast(List *L, ListPlaylist X) {
    if (L->NEff < L->Max) {
        L->A[L->NEff] = X;
        L->NEff++;
    }
}

void DeleteFirst(List *L) {
    if (!IsEmpty(*L)) {
        int i;
        for (i = 0; i < L->NEff - 1; i++) {
            L->A[i] = L->A[i + 1];
        }
        L->NEff--;
    }
}

void DeleteAt(List *L, IdxType i) {
    if (!IsEmpty(*L) && IsIdxEff(*L, i)) {
        int j;
        for (j = i; j < L->NEff - 1; j++) {
            L->A[j] = L->A[j + 1];
        }
        L->NEff--;
    }
}
