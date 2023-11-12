#include <stdio.h>
#include "../ADT_Mesin-Kata/mesinkata.h"
#include "../ADT_MesinKarakter/mesinkarakter.h"
#include "../ADT_Map/map.h"
#include "start.h"

void STARTREAD(ListPenyanyi * LP, char NamaFile []){
  STARTKALIMATFILE("config.txt");

  Kalimat NamaPenyanyi;
  Kalimat NamaAlbum;
  Kalimat NamaLagu;

  int loop = ComLine.TabLine[0] - 48;
  printf("\nJumlah Penyanyi: %d\n", loop);
  for (int i = 0; i < loop; i++){
    ADVSATUKATA();
    int album = ComLine.TabLine[0] - 48;   
    ADVKALIMAT();  
    AddPenyanyi(LP, ComLine);
    for (int j = 0; j < album; j++){
      ADVSATUKATA();
      int lagu = ComLine.TabLine[0] - 48;

      ADVKALIMAT();

      AddAlbum(LP, ComLine);
      for (int k = 0; k < lagu; k++)
      {
        ADVKALIMAT();
        AddLagu(LP, ComLine);    
      }
    }

  }

}

// int main(){
//   STARTREAD();
// }
// gcc ./map/map.c ./mesin/mesinkalimat.c ./mesin/mesinkata.c ./mesin/mesinkarakter.c start.h start.c main.c -o main
