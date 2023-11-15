#include <stdio.h>
<<<<<<< Updated upstream
#include "start.h"

void STARTREAD(ListPenyanyi * LP, ListLagu *lagu2,char NamaFile []){
=======
#include "ADT/ADT_MesinKarakter/mesinkarakter.h"
#include "ADT/ADT_Mesin-Kata/mesinkata.h"
#include "ADT/ADT_Map/map.h"
#include "start.h"

void STARTREAD(ListPenyanyi * LP, char NamaFile []){
>>>>>>> Stashed changes
  startWFile("text.txt");

  Word NamaPenyanyi;
  Word NamaAlbum;
  Word NamaLagu;
<<<<<<< Updated upstream
  int panjg;

  CreateEmptyListLagu(&*lagu2);
  *LP = MakeListPenyanyi();
  


  
  int loop = wordToInt(currentWord);
  int album,lagu;
  int number =0;
=======
  ListPenyanyi listmusisi;


  int loop = wordToInt(currentWord);
  int album,lagu;
>>>>>>> Stashed changes
  printf("\nJumlah Penyanyi: %d\n", loop);
  for (int i = 0; i < loop; i++){
    ADVSATUKATA();
    album = currentWord.TabWord[0] - 48;   
    ADVKALIMAT();  
    displayWord(currentWord);
<<<<<<< Updated upstream
    InsertLast(&*LP, currentWord);
=======
    InsertLast(&listmusisi, currentWord);
>>>>>>> Stashed changes
    for (int j = 0; j < album; j++){
      ADVSATUKATA();
      lagu = currentWord.TabWord[0] - 48;

      ADVKALIMAT();
      displayWord(currentWord);
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
      //AddAlbum(LP, CLine);
      //NamaAlbum = NamaAlbumNow(LP);
      for (int k = 0; k < lagu; k++)
      {
        ADVKALIMAT();
        displayWord(currentWord);
<<<<<<< Updated upstream
        panjg = currentWord.Length;
        printf("panjang lagu : %d\n",panjg);
        InsertListLagu(&*lagu2,currentWord,number);
=======
>>>>>>> Stashed changes
        //AddLagu(LP, CLine);    
      }
      number++;
    }
  }
<<<<<<< Updated upstream
  // printf("panjang album : %d\n",panjg);
=======
>>>>>>> Stashed changes
}

// int main(){
//   STARTREAD();
// }
// gcc ./map/map.c ./mesin/mesinkalimat.c ./mesin/mesinkata.c ./mesin/mesinkarakter.c start.h start.c main.c -o main