#include "Source/ADT/ADT_Mesin-Kata/mesinkata.h"
#include "Source/ADT/ADT_MesinKarakter/mesinkarakter.h"
// #include "Source/ADT/ADT_Map/map.h"
#include "Source/ADT/ADT_List/liststatis.h"
#include "Source/command/start.h"
#include "Source/ADT/ADT_Set/set.h"
#include "Source/command/list.h"
#include <stdio.h>

int main(){
    char namaFile[] = "text.txt";
    ListPenyanyi listmusisi3;
    SetLagu lagu2;
    MapAlbum m2;
    ListPlaylist listlagu3;
    STARTREAD(&listmusisi3,&lagu2,&m2,namaFile);
    DisplayListPenyanyi(listmusisi3);
    DisplaySetLagu(lagu2,5);
    listdefault(listmusisi3,lagu2,m2);
    listplaylist(listlagu3);
    //displayMapAlbum(m2);
    


    return 0;
    
    

    
}