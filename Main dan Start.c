#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/* Definisi ADT List statis dan ADT List dinamis */
#define MAX_SINGERS 50
#define MAX_ALBUMS 10
#define MAX_SONGS 100

typedef struct {
    char singerName[100];
    char albums[MAX_ALBUMS][100];
    int albumCount;
} Singer;

typedef struct {
    char title[100];
    char singer[100];
    int duration;
} Song;

typedef struct {
    char name[100];
    Song songs[MAX_SONGS];
    int songCount;
} Album;

Singer singers[MAX_SINGERS];
int singerCount = 0;

Album albums[MAX_ALBUMS];
int albumCount = 0;

/* Definisi Fungsi-Fungsi */
void displayMainMenu() {
    printf("--- Selamat datang di WayangWave ---\n");
    printf("Command:\n");
    printf("1. START\n");
    printf("2. LOAD\n");
    printf("3. HELP\n");
    printf("------------\n");
}

void parseSTARTCommand() {
    /* Contoh implementasi membaca file konfigurasi default */
    /* Mengisi data penyanyi */
    strcpy(singers[0].singerName, "HIVI!");
    strcpy(singers[0].albums[0], "Kereta Kencan");
    singers[0].albumCount = 1;

    /* Mengisi data album dan lagu */
    strcpy(albums[0].name, "Kereta Kencan");
    strcpy(albums[0].songs[0].title, "Gadis Sampul");
    strcpy(albums[0].songs[0].singer, "HIVI!");
    albums[0].songs[0].duration = 221;
    albums[0].songCount = 1;

    singerCount = 1;
    albumCount = 1;
}

int main() {
    char command[10];

    while (1) {
        displayMainMenu();
        printf("Masukkan Command : ");
        scanf("%s", command);

        if (strcmp(command, "START") == 0) {
            parseSTARTCommand();
            printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
            break; /* Keluar loop setelah aplikasi berhasil dimulai */
        } else if (strcmp(command, "LOAD") == 0) {
            /* Implementasikan perintah LOAD di sini */
        } else if (strcmp(command, "HELP") == 0) {
            /* Implementasikan perintah HELP di sini */
        } else {
            printf("Command tidak valid. Harap masukkan command yang valid.\n");
        }
    }

    return 0;
}
