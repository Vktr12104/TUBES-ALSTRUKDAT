#include "Source/ADT/ADT_Mesin-Kata/mesinkata.h"
#include "Source/ADT/ADT_MesinKarakter/mesinkarakter.h"
// #include "Source/ADT/ADT_Map/map.h"
#include "Source/ADT/ADT_List/liststatis.h"
#include "Source/start.h"
#include "Source/ADT/ADT_Set/set.h"
#include "Source/command/list.h"
#include <stdio.h>

int main(){
    char namaFile[] = "text.txt";
    ListPenyanyi listmusisi3;
    SetLagu lagu2;
    STARTREAD(&listmusisi3,&lagu2,namaFile);
    DisplayListPenyanyi(listmusisi3);
    DisplaySetLagu(lagu2,4);
    listdefault(listmusisi3,lagu2);

    


    return 0;
    
    

    
}