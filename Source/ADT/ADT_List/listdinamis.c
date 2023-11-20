#include "listdinamis.h"

/* ********** KONSTRUKTOR ********** */
ListD MakeListD() {
    ListD L;
    L.NEff = 0;
    L.Max = MaxEl;

    L.A = (listBerkait*)malloc(MaxEl * sizeof(listBerkait));

    if (L.A == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        L.NEff = -1;
    } else {
        for (int i = 0; i < MaxEl; i++) {
            L.A[i].First = '\0';
        }
    }

    return L;
}

/* ********** TEST KOSONG/PENUH ********** */
boolean IsEmptyListD(ListD L) {
    return L.A->First == NULL;
}

/* ********** SELEKTOR ********** */
int LengthListD(ListD L) {
    return L.NEff;
}

IdxType FirstIdxListD(ListD L) {
    return 1;
}

IdxType LastIdxListD(ListD L) {
    return L.NEff;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidListD(ListD L, IdxType i) {
    return i >= 1 && i <= L.Max;
}

boolean IsIdxEffListD(ListD L, IdxType i) {
    return i >= FirstIdxListD(L) && i <= LastIdxListD(L);
}

/* ********** Operasi-operasi ********** */
boolean IsMemberdinamis(ListD L, listBerkait X) {
    int i;
    for (i = 0; i < L.NEff; i++) {
        if (isWordEqual(L.A[i].NamaPlaylist, X.NamaPlaylist)) {
            return true;
        }
    }
    return false;
}

void InsertFirstListD(ListD *L, Word nama) {
    if (L->NEff < L->Max) {
        int i;
        for (i = L->NEff; i > 0; i--) {
            (*L).A[i] = L->A[i - 1];
        }
        L->A[0].NamaPlaylist = nama;
        L->NEff++;
    }
}

void InsertAtListD(ListD *L, Word nama, IdxType i) {
    if (L->NEff < L->Max && IsIdxEffListD(*L, i)) {
        int j;
        for (j = L->NEff; j > i; j--) {
            L->A[j] = L->A[j - 1];
        }
        L->A[i].NamaPlaylist = nama;
        L->NEff++;
    }
}

void InsertLastListD(ListD *L, Word nama) {
    if (L->NEff < L->Max) {
        L->A[L->NEff].NamaPlaylist = nama;
        L->NEff++;
    }
}

void DeleteFirstListD(ListD *L) {
    if (!IsEmptyListD(*L)) {
        for (int i = 0; i < L->NEff - 1; i++) {
            L->A[i] = L->A[i + 1];
        }
        L->NEff--;
    }
}

void DeleteAtListD(ListD *L, IdxType i) {
    if (IsIdxEffListD(*L, i)) {
        for (int j = i - 1; j < L->NEff - 1; j++) {
            L->A[j] = L->A[j + 1];
        }
        L->NEff--;
    }
}
