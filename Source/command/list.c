#include <stdio.h>
#include "list.h"
#include "../ADT/struc.h"


void listdefault(ListPenyanyi input1, SetLagu input3 /*, MapAlbum input2*/){
    printf("Daftar Penyanyi :\n");
    for (int i = 0;i<input1.NEff;i++){
        printf("%d. %s\n",i+1,input1.A[i]);
    }
    printf("Ingin melihat album yang ada?(Y/N) ");
    STARTCOMMAND();
    if (currentCommand.TabWord[0]=='Y'){
        printf("Pilih penyanyi untuk melihat album mereka: \n");
        STARTCOMMAND();
        char *comm = wordToString(currentCommand);
        // note : bisa langsung for kalo mark semicolon = currentCommand g ada semicolon
        // for (int i = 0;i<input.penyanyi_length;i++){
        //     if (StrComp(comm,input.penyanyi[i].nama_penyanyi)){
        //         thealbum = input.penyanyi[i];
        //         break;
        //         } 
        // }
        // for (int i = 0;i<thealbum.album_length;i++){
        //     printf("%d. %s\n", i+1, thealbum.album_penyanyi[i].nama_album);
        // }
        int idpenyanyi;
        for (int i = 0;i<=input1.NEff;i++){
            char* namap = wordToString(input1.A[i]);
            if (StrComp(comm,namap)){
                idpenyanyi = i+1;
                break;
            }
        }
        SetLagu thelagu;
        printf("Ingin melihat lagu yang ada?(Y/N) ");
        STARTCOMMAND();
        if (currentCommand.TabWord[0]=='Y'){
            printf("Pilih album untuk melihat lagu yang ada di album: \n");
            STARTCOMMAND();
            char *comm = wordToString(currentCommand);
            int idalbum = 1; 
            int id = 1;
            for (int i =0;i<input3.jumlah_lagu;i++){
                if (input3.A[i].album_id==idalbum){
                    Word lagu = input3.A[i].nama_lagu;
                    printf("%d. %s\n",id,lagu.TabWord);
                    id++;
                }
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