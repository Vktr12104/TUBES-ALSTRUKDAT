#include <stdio.h>
#include "quit.h"
#include "../ADT/struc.h"

void QUIT() {
    printf("Apakah kamu ingin menyimpan data sesi sekarang? ");
    STARTWORD();
    if (currentWord.TabWord[0] == 'Y') {
        printf("Masukkan nama file untuk penyimpanan: ");
        STARTCOMMAND();

        Word file;
        file.Length = currentCommand.Length;

        for (int i=0; i<currentCommand.Length; i++){
            file.content[i] = currentWord.TabWord[i];
        }

        SAVE(file);
    } else {
        printf ("Kamu keluar dari WayangWave.\n");
        printf ("Dadah ^_^/\n");
    }
}