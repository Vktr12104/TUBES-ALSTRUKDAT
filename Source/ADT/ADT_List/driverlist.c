#include <stdio.h>
#include <string.h>
#include "liststatis.h"
#include "../ADT_Mesin-Kata/mesinkata.h"

void printList(List L) {
    DisplayList(L);
}

int main() {
    List penyanyi, album, lagu;
    Word input;

    // Membuat list penyanyi
    penyanyi = MakeList();

    // Menambahkan penyanyi ke dalam list penyanyi
    Word temp;
    assignWord(&temp, "New Jeans", 9);
    InsertLast(&penyanyi, temp);
    assignWord(&temp, "BLACKPINK", 9);
    InsertLast(&penyanyi, temp);
    assignWord(&temp, "Central Cee", 11);
    InsertLast(&penyanyi, temp);
    assignWord(&temp, "Rich Brian", 10);
    InsertLast(&penyanyi, temp);
    assignWord(&temp, "Denny Caknan", 12);
    InsertLast(&penyanyi, temp);
    assignWord(&temp, "Via Vallen", 10);
    displayWord(temp);
    InsertLast(&penyanyi, temp);

    Word command[4];
    readCommand(command);
    Word End, CommandListDefault, CommandYes;
    assignWord(&CommandListDefault, "LIST_DEFAULT", 12);
    assignWord(&CommandYes, "Y", 1);
    assignWord(&End, "End", 3);
    while (!isWordEqual(command[0], End)) {
        if (isWordEqual(command[0], CommandListDefault)) {
            printf(">> LIST DEFAULT;\n");
            printf("Daftar Penyanyi :\n");
            printList(penyanyi);
            printf("Ingin melihat album yang ada?(Y/N): ");
            Word confirm = readWord(30);
            if (isWordEqual(confirm, CommandYes)) {
                printf("Pilih penyanyi untuk melihat album mereka: ");
                Word singer = readWord(30);
                if (Search(penyanyi, singer)) {
                    // Membuat list album untuk penyanyi yang dipilih
                    album = MakeList();
                    // Menambahkan album ke dalam list album (sesuai penyanyi)
                    assignWord(&temp, "BLACKPINK", 9);
                    if (isWordEqual(singer, temp)) {
                        assignWord(&temp, "BORN PINK", 9);
                        InsertLast(&album, temp);
                        assignWord(&temp, "THE ALBUM", 9);
                        InsertLast(&album, temp);
                        assignWord(&temp, "SQUARE ONE", 10);
                        InsertLast(&album, temp);
                        assignWord(&temp, "SQUARE TWO", 10);
                        InsertLast(&album, temp);
                    }

                    printf("Daftar Album oleh %s :\n", wordToString(singer));
                    printList(album);

                    printf("Ingin melihat lagu yang ada?(Y/N): ");
                    confirm = readWord(30);
                    if (isWordEqual(confirm, CommandYes)) {
                        printf("Pilih album untuk melihat lagu yang ada di album : ");
                        Word albumm = readWord(30);
                        if (Search(album, albumm)) {
                            // Membuat list lagu untuk album yang dipilih
                            lagu = MakeList();

                            // Menambahkan lagu ke dalam list lagu (sesuai album)
                            assignWord(&temp, "SQUARE ONE", 10);
                            if (isWordEqual(albumm,temp)) {
                                assignWord(&temp, "WHISTLE", 7);
                                InsertLast(&lagu, temp);
                                assignWord(&temp, "BOOMBAYAH", 9);
                                InsertLast(&lagu, temp);
                            }

                            printf("Daftar Lagu di %s:\n", wordToString(albumm));
                            printList(lagu);
                        } else {
                            printf("Album tidak ditemukan.\n");
                        }
                    }
                } else {
                    printf("Penyanyi tidak ditemukan.\n");
                }
            }
        }
        readCommand(command);
    }

    return 0;
}
