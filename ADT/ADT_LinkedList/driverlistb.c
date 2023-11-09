#include <stdio.h>
#include <string.h>
#include "listb.h"
#include "../ADT_Set/boolean.h"

int main() {
    List L1, L2, L3;
    char input[50]; // Assuming a maximum string length of 49 characters

    // Initialize the lists
    CreateEmpty(&L1);
    CreateEmpty(&L2);
    CreateEmpty(&L3);

    // Insert some strings into L1 and L2
    printf("Enter strings for L1 (type 'end' to stop):\n");
    while (1) {
        scanf("%s", input);
        if (strcmp(input, "end") == 0) {
            break;
        }
        InsVLast(&L1, input);
    }

    printf("Enter strings for L2 (type 'end' to stop):\n");
    while (1) {
        scanf("%s", input);
        if (strcmp(input, "end") == 0) {
            break;
        }
        InsVLast(&L2, input);
    }

    // Display L1 and L2
    printf("L1: ");
    PrintInfo(L1);
    printf("\n");

    printf("L2: ");
    PrintInfo(L2);
    printf("\n");

    // Test the InversList function
    InversList(&L1);
    InversList(&L2);

    printf("Inversed L1: ");
    PrintInfo(L1);
    printf("\n");

    printf("Inversed L2: ");
    PrintInfo(L2);
    printf("\n");

    // Concatenate L1 and L2 into L3
    Konkat1(&L1, &L2, &L3);

    printf("L3 (Concatenated L1 and L2): ");
    PrintInfo(L3);
    printf("\n");

    return 0;
}
