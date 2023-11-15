#include "Source/ADT/ADT_Mesin-Kata/mesinkata.h"
#include "Source/ADT/ADT_MesinKarakter/mesinkarakter.h"
#include "Source/ADT/ADT_Map/map.h"
#include "Source/ADT/ADT_List/liststatis.h"
#include "Source/start.h"
#include "Source/ADT/ADT_Set/set.h"

#include <stdio.h>

int main(){
    char namaFile[] = "text.txt";
    ListPenyanyi listmusisi3;
    ListLagu lagu2;
    STARTREAD(&listmusisi3,&lagu2,namaFile);
    DisplayListPenyanyi(listmusisi3);
    DisplayListLagu(lagu2,4);

    


    return 0;
    
    

    
}