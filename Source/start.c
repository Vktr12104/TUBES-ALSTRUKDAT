#include <stdio.h>
#include "start.h"

void STARTREAD(ListPenyanyi * LP, ListLagu *lagu2,char NamaFile []){
  startWFile("text.txt");

  Word NamaPenyanyi;
  Word NamaAlbum;
  Word NamaLagu;
  int panjg;

  CreateEmptyListLagu(&*lagu2);
  *LP = MakeListPenyanyi();
  


  
  int loop = wordToInt(currentWord);
  int album,lagu;
  int number =0;
  printf("\nJumlah Penyanyi: %d\n", loop);
  for (int i = 0; i < loop; i++){
    ADVSATUKATA();
    album = currentWord.TabWord[0] - 48;   
    ADVKALIMAT();  
    displayWord(currentWord);
    InsertLast(&*LP, currentWord);
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
        InsertListLagu(&*lagu2,currentWord,number);
        //AddLagu(LP, CLine);    
      }
      number++;
    }
  }
  // printf("panjang album : %d\n",panjg);
}

// int main(){
//   STARTREAD();
// }
// gcc ./map/map.c ./mesin/mesinkalimat.c ./mesin/mesinkata.c ./mesin/mesinkarakter.c start.h start.c main.c -o main
