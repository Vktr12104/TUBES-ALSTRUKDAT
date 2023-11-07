#ifndef structure_H
#define structure_H
#include "boolean.h"

typedef char Title;
typedef int Key;

#define MaxEl 100
#define IDX_UNDEF -1
#define INT_UNDEF -999
#define Nil 0

/*  Akses Elemen Lagu  */
#define LAGU_NAMA(L, i, j, k, l) (L).penyanyi[i].album_penyanyi[j].album_lagu[k].nama_lagu[l]
#define LAGU_ALBUM_ID(L, i, j, k) (L).penyanyi[i].album_penyanyi[j].album_lagu[k].album_id
/*Melihat Daftar lagu yang dimiliki oleh penyanyi tertentu (LIST)*/
// Berfungsi untuk memutar lagu (PLAY)

/*  Akses Elemen Album  */
#define ALBUM_NAMA(A, i, j, k) (A).penyanyi[i].album_penyanyi[j].nama_album[k]
#define ALBUM_LAGU_LENGTH(A, i, j) (A).penyanyi[i].album_penyanyi[j].lagu_length
#define ALBUM_PENYANYI_ID(A, i, j) (A).penyanyi[i].album_penyanyi[j].penyanyi_id
/* Struktur Data Penyanyi yang memiliki Album (yang memiliki Lagu) [List Statis] */

/* ### Akses Elemen Penyanyi ### */
#define PENYANYI_NAMA(S, i, j) (S).penyanyi[i].nama_penyanyi[j]
#define PENYANYI_ALBUM_LENGTH(S, i) (S).penyanyi[i].album_length

/* Akses Elemen ListPenyanyi */
#define LIST_PENYANYI_ID(LS, i) (LS).penyanyi[i]
#define LIST_PENYANYI_LENGTH(LS) (LS).penyanyi_length

/* Akses Elemen pada Playlist*/
#define LIST_PLAYLIST_ID(LP, i) (LP).(*playlist + i)
#define LIST_PLAYLIST_SIZE(LP) (LP).playlistSize
// Berfungsi untuk Menambah Playlist  (PLAY)


/* STRUKTUR DATA */
/*  Indeks lagu [0..lagu_length] merupakan key dari map album ke lagu dengan
    Nilai variabel nama_lagu merupakan value dari map Album -> Lagu */
typedef struct {
    Title nama_lagu[MaxEl];
    int album_id;
} Lagu;

typedef struct {
    Title nama_album[MaxEl]; // Maksimal Panjang judul album 100 char
    Lagu album_lagu[MaxEl/5]; // Banyak Lagu dalam album sebanyak 20 
    int lagu_length; 
    int penyanyi_id;
} Album;

typedef struct {
    Title nama_penyanyi[MaxEl]; // Panjang nama penyanyi dibatasi 100 char
    Album album_penyanyi[MaxEl/10]; // banyak album yang dimiliki artis dibatasi 10 album
    int album_length;
} Penyanyi;

/* Struktur Data List Penyanyi (yang memiliki Album yang memiliki Lagu) [List Statis] */
typedef struct {
    Penyanyi penyanyi[MaxEl/20];
    int penyanyi_length;
} ListPenyanyi;

/* Struktur Data Playlist yang memiliki Lagu [List Berkait] */
/*  Setiap list sebagai pointer menuju masing-masing playlist memiliki:
    1) playlist_nama dan 2) list (pointer) */
typedef struct tPlaylist* Address;
typedef struct tPlaylist {
    Lagu lagu_playlist;
    Address next;
} LaguPlaylist; // Berfungsi untuk memutar lagu pada Playlist (PLAY)

// Meninjau lagu yang terdapat pada playlist
typedef struct {
    Title playlist_nama[MaxEl];
    Address list;
} NamaPlaylist; // Meninjau nama playlist (List Playlist)

/* Struktur Data List Playlist yang memiliki Playlist (yang memiliki Lagu) [List Dinamis] */
/* playlistSize pertama kali diinisialisasi dengan nilai (MaxEl/20) */
typedef struct {
    NamaPlaylist* playlist;
    size_t playlistSize;
} ListPlaylist;
/* ### Struktur Data ListPlaylist ### */
typedef struct {
    Lagu lagu_queue[MaxEl];
    int idxHead;
    int idxTail;
} QueueLagu;

// Data Struct yang digunakan untuk antrian pada  queue lagu (Queue lagu & PLAY)

typedef struct {
    Lagu hist_lagu[MaxEl];
    int idxTop;
    int count;
} HistoriLagu;

// Data Struct yang digunakan untuk menampung history lagu pada stack pada SONGS (Previous & Next)

#endif
