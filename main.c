#include "Source/ADT/ADT_Mesin-Kata/mesinkata.h"
#include "Source/ADT/ADT_MesinKarakter/mesinkarakter.h"
#include "Source/ADT/ADT_Map/map.h"
#include "Source/ADT/ADT_List/liststatis.h"
#include "Source/ADT/ADT_List/listdinamis.h"
#include "Source/command/start.h"
#include "Source/ADT/ADT_Set/set.h"
#include "Source/command/list.h"
#include "Source/command/playlist.h"
#include "Source/ADT/boolean.h"
#include "Source/console.h"
#include "Source/command/welcome.h"
#include "Source/command/play.h"
#include <stdio.h>
status current;
int main() {
    
    char namaFile[] = "text.txt";
    ListPenyanyi listmusisi3;
    ListDinamik DaftarPlaylist;
    QueueLagu Q;
    CCreateQueue(&Q);
    HistoriLagu HS;
    CreateHist(&HS);
    SetLagu lagu2;
    MapAlbum m2;
    boolean start = false;
    boolean quit = false;
    NotPlaying();
    NotPlayingPlaylist();
    welcome();

    while (!quit) {
        printf(">> ");
        STARTCOMMAND(); 
        if (StrComp(currentCommand.TabWord, "START")) {
            STARTREAD(&listmusisi3, &lagu2, &m2, &DaftarPlaylist, namaFile);
            start = true;
            quit=true;
        } else if (StrComp(currentCommand.TabWord, "LOAD")) {
            // Tambahkan implementasi untuk perintah "LOAD" jika diperlukan
        } else {
            invalidCommand(&currentCommand);
        }
    }
    quit=false;
    while (!quit) {
        printf(">> ");
        STARTCOMMAND();

        if (StrComp(currentCommand.TabWord, "LIST DEFAULT")) {
            if (start == true) {
                listdefault(listmusisi3, lagu2, m2);
            } else {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }else if (StrComp(currentCommand.TabWord, "PLAY PLAYLIST")) {
            playPlaylist(DaftarPlaylist,&Q,&HS);
        } 
        else if (StrComp(currentCommand.TabWord, "LIST PLAYLIST")) {
            listplaylist(DaftarPlaylist);
        } else if (StrComp(currentCommand.TabWord, "QUEUE SONG")) {
            QueSong(listmusisi3, m2, lagu2, &Q);
        } else if (StrComp(currentCommand.TabWord, "QUEUE PLAYLIST")) {
            // ... (tambahkan implementasi untuk QUEUE PLAYLIST)
        } else if (StrComp(currentCommand.TabWord, "QUEUE SWAP")) {
            QueSwap(&Q);
        } else if (StrComp(currentCommand.TabWord, "QUEUE REMOVE")) {
            QueMove(&Q);
        } else if (StrComp(currentCommand.TabWord, "QUEUE CLEAR")) {
            QueClear(&Q);
        } else if (StrComp(currentCommand.TabWord, "PLAYLIST CREATE")) {
            CreatePlayList(&DaftarPlaylist);
        } else if (StrComp(currentCommand.TabWord, "PLAYLIST ADD SONG")) {
            PLAYLISTADDSONG(listmusisi3, m2, lagu2, &DaftarPlaylist);
        } else if (StrComp(currentCommand.TabWord, "PLAYLIST ADD ALBUM")) {
            PLAYLISTADDALBUM(listmusisi3, m2, lagu2, &DaftarPlaylist);
        } else if (StrComp(currentCommand.TabWord, "SONG NEXT")) {
            SongNext(&HS, &Q);
        } else if (StrComp(currentCommand.TabWord, "SONG PREVIOUS")) {
            SongPrev(&HS, &Q);
        } else if (StrComp(currentCommand.TabWord, "SAVE")) {
            save(listmusisi3, m2, lagu2);
        } else if (StrComp(currentCommand.TabWord, "QUIT")) {
            QUIT(listmusisi3, m2, lagu2);
            quit = true;
        } else if (StrComp(currentCommand.TabWord, "HELP")) {
            help(start);
        }
        else if (StrComp(currentCommand.TabWord, "STATUS")) {
            statuscurrent(Q);
        }
    }

    return 0;
}
