#include <stdio.h>
#include "ADT/ADT_MesinKarakter/mesinkarakter.h"
#include "ADT/ADT_Map/map.h"
#include "start.h"

void STARTREAD(ListPenyanyi * LP, char NamaFile []){
  startWFile("text.txt");

  Word NamaPenyanyi;
  Word NamaAlbum;
  Word NamaLagu;
  ListPenyanyi listmusisi;
  int panjg;


  int loop = wordToInt(currentWord);
  int album,lagu;
  printf("\nJumlah Penyanyi: %d\n", loop);
  for (int i = 0; i < loop; i++){
    ADVSATUKATA();
    album = currentWord.TabWord[0] - 48;   
    ADVKALIMAT();  
    displayWord(currentWord);
    InsertLast(&listmusisi, currentWord);
    for (int j = 0; j < album; j++){
      ADVSATUKATA();
      lagu = currentWord.TabWord[0] - 48;

      ADVKALIMAT();
      displayWord(currentWord);
      //AddAlbum(LP, CLine);
      //NamaAlbum = NamaAlbumNow(LP);
      for (int k = 0; k < lagu; k++)
      {
        ADVKALIMAT();
        displayWord(currentWord);
        panjg = currentWord.Length;
        printf("panjang lagu : %d\n",panjg);
        //AddLagu(LP, CLine);    
      }
    }
  }
  // printf("panjang album : %d\n",panjg);
}

// int main(){
//   STARTREAD();
// }
// gcc ./map/map.c ./mesin/mesinkalimat.c ./mesin/mesinkata.c ./mesin/mesinkarakter.c start.h start.c main.c -o main
