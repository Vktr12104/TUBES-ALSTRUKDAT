#include <stdio.h>
#include "listb.h"

int main() {
    listBerkait L1, L2, L3;
    CreateEmpty(&L1);
    CreateEmpty(&L2);
    CreateEmpty(&L3);

    Isi_Que elemen1 = {"Song1"};
    Isi_Que elemen2 = {"Song2"};
    Isi_Que elemen3 = {"Song3"};

    InsVFirst(&L1, elemen1);
    InsVLast(&L1, elemen2);

    InsVFirst(&L2, elemen3);

    printf("List L1: ");
    PrintInfo(L1);
    printf("\n");

    printf("List L2: ");
    PrintInfo(L2);
    printf("\n");

    Konkat1(&L1, &L2, &L3);

    printf("List L3 after concatenation: ");
    PrintInfo(L3);
    printf("\n");

    printf("Is 'Song1' a member of L3? %s\n", IsMember(L3, "Song1") ? "Yes" : "No");

    InversList(&L3);
    printf("List L3 after inversion: ");
    PrintInfo(L3);
    printf("\n");

    printf("Number of elements in L3: %d\n", NbElmt(L3));

    return 0;
}
