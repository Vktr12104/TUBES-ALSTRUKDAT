#include <stdio.h>
#include "playlist.h"
#include "../ADT/struc.h"


void playlist_create (ListPlaylist *input1){
    printf ("Masukkan nama playlist yang ingin dibuat : \n");
    STARTCOMMAND();
    input1.playlistSize++;
    input1.playlist[input1.playlistSize].playlist_nama=currentCommand;
    input1.playlist[input1.playlistSize].list=Nil;
}
void playlist_add (ListPlaylist *input) {
    ListPenyanyi PLPenyanyi;
    printf("Daftar Penyanyi :\n");
    for (int i = 0;i<PLPlaylist.NEff;i++){
        printf("%d. %s\n",i+1,PLPenyanyi.A[i]);
    }
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTCOMMAND();
    char comm1 = wordToString(currentCommand);
}
/*/
    Penyanyi pilihan_penyanyi;
    for (int i = 0;i<PLPenyanyi.penyanyi_length;i++){
        if (StrComp(comm1,PLPenyanyi.penyanyi_list[i].nama_penyanyi)){
            pilihan_penyanyi = PLPenyanyi.penyanyi_list[i];
            break;
        } 
    }
    printf("Daftar Album :\n");
    for (int i = 0;i<pilihan_penyanyi.album_length;i++){
        printf("%d. %s\n", i+1, pilihan_penyanyi.album_penyanyi[i].nama_album);
    }


    printf("Masukkan Judul Album yang dipilih : ");
    STARTCOMMAND();
    char comm2 = wordToString(currentCommand);

    Album pilihan_album;
    for (int i = 0;i<pilihan_penyanyi.album_length;i++){
        if (StrComp(comm2,pilihan_penyanyi.album_penyanyi[i].nama_album)){
            pilihan_album = pilihan_penyanyi.album_penyanyi[i];
            break;
        }
    }
    printf("Daftar Lagu :\n");
    for (int i =0;i<pilihan_album.lagu_length;i++){
        printf("%d. %s",i+1,pilihan_album.album_lagu[i].nama_lagu);
    }

    printf("Masukkan Judul Lagu yang dipilih : ");
    STARTCOMMAND();
    char comm3 = wordToString(currentCommand);

    Lagu pilihan_lagu;
    for (int i = 0;i<pilihan_album.lagu_length;i++){
        if (StrComp(comm3,pilihan_album.album_lagu[i].nama_lagu)){
            pilihan_lagu = pilihan_album.album_lagu[i];
            break;
        }
    }


    printf("Daftar playlist pengguna:\n"); 
    for (int i = 0; i < input1.playlistSize; i++){
        printf("%d. %s\n", i+1,input1.playlist[i].playlist_nama);
    }


    printf("Masukkan Playlist yang dipilih : ");
    STARTCOMMAND();
    char comm4 = wordToString(currentCommand);


    NamaPlaylist masuk;
    for (int i = 0;i<input1.playlistSize;i++){
        if (StrComp(comm4,input1.playlist[i].playlist_nama)){
            input1.playlist[i].playlist_user[isi_playlist+1].lagu_playlist=comm3;
            input1.playlist[i].playlist_user[isi_playlist+1].album_playlist=comm2;
            input1.playlist[i].playlist_user[isi_playlist+1].Penyanyi_playlist=comm1;
            break;
        }
    }
}


void playlist_swap
void playlist remove
void playlist delete

typedef struct {
    Word lagu_playlist;
    Title album_playlist[MaxEL];
    Title Penyanyi_playlist[MaxEl];
} isi_playlist;

typedef struct {
    Title playlist_nama[MaxEl];
    isi_playlist playlist_user[MaxEl];
    int isi_playlist;
} NamaPlaylist; // Meninjau nama playlist (List Playlist)

typedef struct {
    NamaPlaylist* playlist;
    size_t playlistSize;
} ListPlaylist;








typedef struct {
    Penyanyi penyanyi_list[MaxEl];
    int penyanyi_length;
} ListPenyanyi;