#include <stdio.h>
#include "../structure.h" // Sesuaikan dengan lokasi header file yang sesuai

int main() {
    Lagu S;
    CreateEmpty(&S);

    printf("Is Lagu S empty? %s\n", IsEmpty(S) ? "Yes" : "No");

    Title song1 = "Song1";
    int element1 = 1;
    Title song2 = "Song2";
    int element2 = 2;

    Insert(&S, song1);
    Insert(&S, song2);

    printf("Is Song1 a member of Lagu S? %s\n", IsMember(S, song1) ? "Yes" : "No");
    printf("Is Song2 a member of Lagu S? %s\n", IsMember(S, song2) ? "Yes" : "No");

    Title song3 = "Song3";
    Delete(&S, song3);

    printf("Is Song3 a member of Lagu S? %s\n", IsMember(S, song3) ? "Yes" : "No");

    return 0;
}
