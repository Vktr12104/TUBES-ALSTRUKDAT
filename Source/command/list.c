#include <stdio.h>
#include "list.h"
#include "../ADT/struc.h"
#include "../ADT/ADT_Mesin-Kata/mesinkata.h"

void listdefault(ListPenyanyi input){
    printf("Daftar Penyanyi :\n");
    for (int i = 0;i<input.penyanyi_length;i++){
        printf("%d. %s\n",i+1,input.penyanyi[i].nama_penyanyi);
    }
    printf("Ingin melihat album yang ada?(Y/N) ");
    STARTCOMMAND();
    if (currentCommand.Tabword[0]=='Y'){
        printf("Pilih penyanyi untuk melihat album mereka: \n");
        STARTCOMMAND();
        char *comm = wordToString(currentCommand);
        Penyanyi thealbum;
        // note : bisa langsung for kalo mark semicolon = currentCommand g ada semicolon
        for (int i = 0;i<input.penyanyi_length;i++){
            if (StrComp(comm,input.penyanyi[i].nama_penyanyi)){
                thealbum = input.penyanyi[i];
                break;
                } 
        }
        for (int i = 0;i<thealbum.album_length;i++){
            printf("%d. %s\n", i+1, thealbum.album_penyanyi[i].nama_album);
        }
        printf("Ingin melihat lagu yang ada?(Y/N) ");
        STARTCOMMAND();
        if (currentCommand.Tabword[0]=='Y'){
            printf("Pilih album untuk melihat lagu yang ada di album: \n");
            STARTCOMMAND();
            char *comm = wordToString(currentCommand);
            Album get;
            for (int i = 0;i<thealbum.album_length;i++){
                if (StrComp(comm,thealbum.album_penyanyi[i].nama_album)){
                    get = thealbum.album_penyanyi[i];
                    break;
                }
            }
            for (int i =0;i<get.album_length;i++){
                printf("%d. %s",i+1,get.album_lagu[i].nama_lagu);
            }
        }
    }
}

void listplaylist(ListPlaylist input){
    printf("Daftar playlist yang kamu miliki:\n"); 
    if (input.playlistSize == 0){
        printf("Kamu tidak memiliki playlist.\n");
    }
    else{
        for (int i = 0; i < input.playlistSize; i++)
        {
            printf("%d. %s\n", i+1,input.playlist[i].playlist_nama);
        }
        
    }

}