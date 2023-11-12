#include "Source/ADT/ADT_Mesin-Kata/mesinkata.h"
#include "Source/ADT/ADT_MesinKarakter/mesinkarakter.h"
#include "Source/ADT/ADT_Map/map.h"
#include "Source/ADT/ADT_List/liststatis.h"
#include "Source/start.h"
#include "Source/ADT/ADT_MesinKalimat/mesinkalimat.h"

#include <stdio.h>

int main(){
    char namaFile[] = "text.txt";
    ListPenyanyi listmusisi2 = MakeListPenyanyi();
    STARTREAD(&listmusisi2,namaFile);
    DisplayListPenyanyi(listmusisi2);

    


    return 0;
    
    

    
}