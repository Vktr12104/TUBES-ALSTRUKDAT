#include "listdinamis.h"

/* ********** KONSTRUKTOR ********** */
List MakeList() {
	List L;
	L.A = (ElType*) malloc(MaxEl * sizeof(ElType));
	L.NEff = 0;
	L.Max = MaxEl;
	return L;
}

/* ********** TEST KOSONG/PENUH ********** */
boolean IsEmpty(List L) {
	return (L.NEff == 0);
}

boolean IsFull(List L) {
	return (L.NEff == L.Max);
}

/* ********** SELEKTOR ********** */
int Length(List L) {
	return L.NEff;
}

IdxType FirstIdx(List L) {
	return 0;
}

IdxType LastIdx(List L) {
	return L.NEff - 1;
}

/* ********** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set(List *L, IdxType i, ElType v) {
	if (IsIdxEff(*L, i)) {
		L->A[i] = v;
	}
}

/* ********** Operasi-operasi ********** */
void InsertFirst(List *L, ElType X) {
	if (IsFull(*L)) {
		// Alokasikan memori baru untuk list
		ElType *newA = (ElType*) malloc(2 * L->Max * sizeof(ElType));
		// Salin elemen dari list lama ke list baru
		for (int i = 0; i < L->NEff; i++) {
			newA[i] = L->A[i];
		}
		// Alokasikan memori lama
		free(L->A);
		// Atur nilai variabel list
		L->A = newA;
		L->Max *= 2;
	}
	// Masukkan elemen X ke awal list
	for (int i = L->NEff; i > 0; i--) {
		L->A[i] = L->A[i - 1];
	}
	L->A[0] = X;
	L->NEff++;
}

void InsertAt(List *L, ElType X, IdxType i) {
	if (IsFull(*L)) {
		// Alokasikan memori baru untuk list
		ElType *newA = (ElType*) malloc(2 * L->Max * sizeof(ElType));
		// Salin elemen dari list lama ke list baru
		for (int j = 0; j < L->NEff; j++) {
			newA[j] = L->A[j];
		}
		// Alokasikan memori lama
		free(L->A);
		// Atur nilai variabel list
		L->A = newA;
		L->Max *= 2;
	}
	if (IsIdxValid(*L, i)) {
		// Geser elemen dari indeks i ke atas
		for (int j = L->NEff; j > i; j--) {
			L->A[j] = L->A[j - 1];
		}
		// Masukkan elemen X ke indeks i
		L->A[i] = X;
		L->NEff++;
	}
}

void InsertLast(List *L, ElType X) {
	if (IsFull(*L)) {
		// Alokasikan memori baru untuk list
		ElType *newA = (ElType*) malloc(2 * L->Max * sizeof(ElType));
		// Salin elemen dari list lama ke list baru
		for (int i = 0; i < L->NEff; i++) {
			newA[i] = L->A[i];
		}
		// Alokasikan memori lama
		free(L->A);
		// Atur nilai variabel list
		L->A = newA;
		L->Max *= 2;
	}
	// Masukkan elemen X ke akhir list
	L->A[L->NEff] = X;
	L->NEff;
}