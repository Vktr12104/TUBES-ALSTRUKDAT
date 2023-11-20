#include "Source/ADT/ADT_Mesin-Kata/mesinkata.h"
#include "Source/ADT/ADT_MesinKarakter/mesinkarakter.h"
#include "Source/ADT/ADT_Map/map.h"
#include "Source/ADT/ADT_List/liststatis.h"
#include "Source/command/start.h"
#include "Source/ADT/ADT_Set/set.h"
#include "Source/command/list.h"
#include "Source/ADT/boolean.h"
#include "Source/console.h"
#include <stdio.h>
status current;
int main(){
    
    char namaFile[] = "text.txt";
    ListPenyanyi listmusisi3;
    QueueLagu Q;
    CCreateQueue(&Q);
    HistoriLagu HS;
    CreateHist(&HS);
    SetLagu lagu2;
    MapAlbum m2;
    boolean quit = false;
    boolean start = false;
    while(!quit){
        printf(">> ");
        STARTCOMMAND();
        if(StrComp(currentCommand.TabWord, "START")){
            STARTREAD(&listmusisi3,&lagu2,&m2,namaFile);
            start = true; // untuk menandakan sudah pernah distart
        }
        else if (StrComp(currentCommand.TabWord,"LIST DEFAULT")){
            if(start == true){
                listdefault(listmusisi3,lagu2,m2);
            }
            else{
                printf("Command tidak bisa dieksekusi!\n");

            }
        }else if(StrComp(currentCommand.TabWord,"QUEUE SONG")){
            QueSong(listmusisi3,m2,lagu2,&Q);
        }else if(StrComp(currentCommand.TabWord,"QUEUE PLAYLIST")){
            
        }else if(StrComp(currentCommand.TabWord,"QUEUE SWAP")){
            QueSwap(&Q);
        }else if(StrComp(currentCommand.TabWord,"QUEUE REMOVE")){
            QueMove(&Q);
        }else if(StrComp(currentCommand.TabWord,"QUEUE CLEAR")){
            QueClear(&Q);
        }else if(StrComp(currentCommand.TabWord,"PLAYLIST CREATE")){

        }else if(StrComp(currentCommand.TabWord,"SONG NEXT")){
            SongNext(&HS,&Q);
        }else if(StrComp(currentCommand.TabWord,"SONG PREVIOUS")){
            SongPrev(&HS,&Q);
        }
    }
    //DisplayListPenyanyi(listmusisi3);
    //DisplaySetLagu(lagu2,5);
    //displayMapAlbum(m2,0);
    //displayMapAlbum(m2,1);
    //listdefault(listmusisi3,lagu2,m2);





    return 0;
    
    

    
}