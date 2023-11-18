#include <stdio.h>
#include "list.h"
#include "../ADT/struc.h"


void listdefault(ListPenyanyi input1, SetLagu input3 , MapAlbum input2){
    printf("Daftar Penyanyi :\n");
    DisplayListPenyanyi(input1);
    printf("Ingin melihat album yang ada?(Y/N) ");
    STARTCOMMAND();
    if (currentCommand.TabWord[0]=='Y'){
        printf("Pilih penyanyi untuk melihat album mereka: \n");
        STARTCOMMAND();
        Word kata = currentCommand;
        printf("Daftar album oleh ");
        displayWord(kata);
        printf(" : \n");
        int indexpenyanyi = albumtoidpenyanyi(input1,kata);
        displayMapAlbum(input2,indexpenyanyi);
        int idpenyanyi;
       /* for (int i = 0;i<=input1.NEff;i++){
            char* namap = wordToString(input1.A[i]);
            if (StrComp(comm,namap)){
                idpenyanyi = i+1;
                break;
            }
        }*/
        SetLagu thelagu;
        printf("Ingin melihat lagu yang ada?(Y/N) ");
        STARTCOMMAND();
        if (currentCommand.TabWord[0]=='Y'){
            printf("Pilih album untuk melihat lagu yang ada di album: \n");
            STARTCOMMAND();
            Word cur = currentCommand;
            int id = laguAlbumID(cur,input2);
            printf("Daftar lagu di ");
            displayWord(cur);
            printf(" :\n");
            DisplaySetLagu(input3,id);
            //DisplaySetLagu(input3,id);
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