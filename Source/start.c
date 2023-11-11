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

  int loop = CLine.TabLine[0] - 48;
  printf("\nJumlah Penyanyi: %d\n", loop);
  for (int i = 0; i < loop; i++){
    ADVSATUKATA();
    int album = CLine.TabLine[0] - 48;   
    ADVKALIMAT();  
    AddPenyanyi(LP, CLine);
    for (int j = 0; j < album; j++){
      ADVSATUKATA();
      int lagu = CLine.TabLine[0] - 48;

      ADVKALIMAT();

      AddAlbum(LP, CLine);
      for (int k = 0; k < lagu; k++)
      {
        ADVKALIMAT();
        AddLagu(LP, CLine);    
      }
    }

  }

}

// int main(){
//   STARTREAD();
// }
// gcc ./map/map.c ./mesin/mesinkalimat.c ./mesin/mesinkata.c ./mesin/mesinkarakter.c start.h start.c main.c -o main
