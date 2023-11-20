#include "listdinamis.h"

/* ********** KONSTRUKTOR ********** */
ListD MakeListD() {
    ListD L;
    L.NEff = 0;
    L.Max = MaxEl;
    L.A.First = NULL;
    return L;
}

/* ********** TEST KOSONG/PENUH ********** */
boolean IsEmptyListD(ListD L) {
    return L.A.First == NULL;
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
boolean IsMemberdinamis(ListD L, ListPlaylist X) {
    address P = L.A.First;
    while (P != NULL) {
        if (IsEqualPlaylist(P->infoplaylist, X)) {
            return true;
        }
        P = P->next;
    }
    return false;
}

void InsertFirstListD(ListD *L, Word nama) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != NULL) {
        P->infoplaylist = MakePlaylist(nama);
        P->next = L->A.First;
        L->A.First = P;
        L->NEff++;
    }
}

void InsertAtListD(ListD *L, Word nama, IdxType i) {
    if (IsIdxValidListD(*L, i)) {
        address P = (address)malloc(sizeof(ElmtList));
        if (P != NULL) {
            P->infoplaylist = MakePlaylist(nama);
            if (i == FirstIdxListD(*L)) {
                P->next = L->A.First;
                L->A.First = P;
            } else {
                address Prec = L->A.First;
                IdxType j = 1;
                while (j < i - 1) {
                    Prec = Prec->next;
                    j++;
                }
                P->next = Prec->next;
                Prec->next = P;
            }
            L->NEff++;
        }
    }
}

void InsertLastListD(ListD *L, Word nama) {
    if (IsEmptyListD(*L)) {
        InsertFirstListD(L, nama);
    } else {
        address P = (address)malloc(sizeof(ElmtList));
        if (P != NULL) {
            P->infoplaylist = MakePlaylist(nama);
            P->next = NULL;

            address Last = L->A.First;
            while (Last->next != NULL) {
                Last = Last->next;
            }

            Last->next = P;
            L->NEff++;
        }
    }
}

void DeleteFirstListD(ListD *L) {
    if (!IsEmptyListD(*L)) {
        address P = L->A.First;
        L->A.First = P->next;
        free(P);
        L->NEff--;
    }
}

void DeleteAtListD(ListD *L, IdxType i) {
    if (IsIdxEffListD(*L, i)) {
        address P;
        if (i == FirstIdxListD(*L)) {
            P = L->A.First;
            L->A.First = P->next;
        } else {
            address Prec = L->A.First;
            IdxType j = 1;
            while (j < i - 1) {
                Prec = Prec->next;
                j++;
            }
            P = Prec->next;
            Prec->next = P->next;
        }
        free(P);
        L->NEff--;
    }
}
