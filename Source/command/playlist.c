#include <stdio.h>
#include "playlist.h"
#include "../ADT/struc.h"
#include "../ADT/ADT_LinkedList/listb.h"

void CreatePlayList(ListPlaylist input1) {
    printf("Masukkan nama playlist yang ingin dibuat : \n");
    STARTCOMMAND();  
    
    input1.playlist[input1.playlistSize].isi = 0;

        for (int i = 0; i < currentCommand.Length && currentCommand.TabWord[i] != '\0'; ++i) {
            input1.playlist[input1.playlistSize].playlist_nama[i] = currentCommand.TabWord[i];
        }
        input1.playlist[input1.playlistSize].playlist_nama[currentCommand.Length] = '\0';
        input1.playlistSize++;
    
}

void playlist_add (ListPlaylist *input) {
    ListPenyanyi PLPenyanyi;
    printf("Daftar Penyanyi :\n");
    for (int i = 0;i<PLPenyanyi.;i++){
        printf("%d. %s\n",i+1,PLPenyanyi.penyanyi_list[i].nama_penyanyi);
    }
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTCOMMAND();
    char comm1 = wordToString(currentCommand);

}

void MoveLagu(ListPlaylist lp) {
    STARTCOMMAND();
    int x = wordToInt(currentCommand);
    STARTCOMMAND();
    int y = wordToInt(currentCommand);

    if (x >= lp.playlistSize || x < 0) {
        printf("Tidak ada playlist dengan ID %d.", x);
    } else {
        address p= First(lp.playlist[x]->playlist_user);
        int sum = 0;
        if (lp.playlist->isi== Nil) {
            printf("Playlist %s kosong.", lp.playlist[x].playlist_nama);
        } else {
            while (sum != y && p != Nil) {
                sum++;
                p = Next(p);
            }
            if (sum == y) {
                DelP(&lp.playlist[x].playlist_user, Info(p)); 
                printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari playlist \"%s\"!", p->info.lagu_playlist, p->info.Penyanyi_playlist, lp.playlist[x].playlist_nama);
            } else {
                printf("Tidak ada lagu dengan urutan %d di playlist %s!", y, lp.playlist[x].playlist_nama);
            }
        }
    }
}
void MoveLagu(ListPlaylist *lp){

}


/*
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
*/
