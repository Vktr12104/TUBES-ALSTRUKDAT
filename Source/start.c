#include "start.h"

void STARTREAD(ListPenyanyi * LP, SetLagu *lagu2,MapAlbum *m2,char NamaFile []){
  startWFile("text.txt");
  //MapAlbum mapAl;
  Word NamaPenyanyi;
  Word NamaAlbum;
  Word NamaLagu;
  int panjg;
  CreateMapAlbum(&*m2);

  CreateEmptySetLagu(&*lagu2);
  *LP = MakeListPenyanyi();
  //CreateMapAlbum(&mapAl);
  


  
  int loop = wordToInt(currentWord);
  int album,lagu;
  int number =1;
  int idalbum=1;
  printf("\nJumlah Penyanyi: %d\n", loop);
  for (int i = 0; i < loop; i++){
    ADVSATUKATA();
    album = currentWord.TabWord[0] - 48;   
    ADVKALIMAT();  
    displayWord(currentWord);
    printf("\n");
    InsertLast(&*LP, currentWord);
    for (int j = 0; j < album; j++){
      ADVSATUKATA();
      lagu = currentWord.TabWord[0] - 48;

      ADVKALIMAT();
      displayWord(currentWord);
      printf("\n");
      InsertMapAlbum(&*m2,i,currentWord);
      //AddAlbum(LP, CLine);
      //NamaAlbum = NamaAlbumNow(LP);
      for (int k = 0; k < lagu; k++)
      {
        ADVKALIMAT();
        displayWord(currentWord);
        printf("\n");
        InsertSetLagu(&*lagu2,currentWord,number);
        //AddLagu(LP, CLine);    
      }
      number++;
    }
    idalbum++;
  }
  // printf("panjang album : %d\n",panjg);
}

// int main(){
//   STARTREAD();
// }
// gcc ./map/map.c ./mesin/mesinkalimat.c ./mesin/mesinkata.c ./mesin/mesinkarakter.c start.h start.c main.c -o main
