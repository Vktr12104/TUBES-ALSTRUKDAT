#include "liststatis.h"
#include "../../boolean.h"

List MakeList(){
    List L;
    int i;
    L.NEff = 0  ;
    return L;
}

boolean IsEmpty(List L){
    return L.NEff == 0;
}

ElType Get(List L, IdxType i){
    return L.A[i];
}

void Set(List *L, IdxType i, ElType v){
    L->A[i] = v;
}

int Length(List L){
    return L.NEff;
}

IdxType FirstIdx(List L){
    return 0;
}

IdxType LastIdx(List L){
    return Length(L)-1;
}

boolean IsIdxValid (List L, IdxType i){
    return(i>=FirstIdx(L) && i < MaxEl);
}

boolean IsIdxEff (List L, IdxType i){
    return(i>=FirstIdx(L) && i<= LastIdx(L));
}

boolean Search(List L, ElType X){
    boolean isFound = false;
    for (int i=0; i < L.NEff; i++){
        if (isWordEqual (X,L.A[i])) isFound = true; break;
    }
    return isFound;
}

void InsertFirst(List *L, ElType X){
    InsertAt(L,X,0);
}

void InsertAt(List *L, ElType X, IdxType i)
{
    int j;
    for (j = LastIdx(*L) + 1; j > i; j--)
    {
        L->A[j] = L->A[j - 1];
    }
    L->A[i] = X;
    L->NEff++;
}

void InsertLast(List *L, ElType X){
    InsertAt(L, X, Length(*L));
}

void DeleteFirst(List *L) {
    DeleteAt(L, 0);
}

void DeleteAt(List *L, IdxType i)
{
    int j;
    for (j = i; j < LastIdx(*L); j++)
    {
        L->A[j] = L->A[j + 1];
    }
    L->NEff--;
}

void DeleteLast(List *L){
    DeleteAt(L, LastIdx(*L));
}

List Concat(List L1, List L2){
    List L = MakeList(L);
    int i;
    for (i = 0; i<Length(L1);i++)
    {
        InsertLast(&L, Get(L1,i));
    }
    for (i = 0; i < Length(L2); i++){
        InsertLast(&L, Get(L2, i));
    }
    return L;
}

void DisplayList(List L){
    for (int i=0; i < L.NEff; i++){
        printf("   %d. %s\n", (i+1), L.A[i].TabWord);
    }
}