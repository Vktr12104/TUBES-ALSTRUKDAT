#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord; // Deklarasi currentWord
Word currentCommand;

void IgnoreBlanks(){ 
    while (currentChar==BLANK || currentChar==ENTER){
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(){
    START();
    IgnoreBlanks();
    if(currentChar==BLANK){
        EndWord=true;
    }else{
        EndWord=false;
        ADVWORD();
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
void ADVWORD(){
    IgnoreBlanks () ;
    if (currentChar == MARK && !EndWord) {
        EndWord = true ;
    }else {
        CopyWord() ;
        IgnoreBlanks();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord(){
    int i=0;
    while ((currentChar!=MARK) && (currentChar!=BLANK) &&(currentChar != ENTER)){
        if (i<NMax){
            currentWord.TabWord[i] = currentChar ;
            i++;
        }ADV();
    }currentWord.Length = i;
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void startWFile(char *file){
    finish=false; 
    StartFile(file);
    copywFile();
}
/* I.S. : currentChar dalam file sembarang
   F.S. : Finish = true;
          atau Finish = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void copywFile(){
    int i=0; 
    while(currentChar!=ENTER && !finish){
        currentWord.TabWord[i]=currentChar;
        i++;
        advFile();
    }if (i>NMax){
        currentWord.Length = NMax;
    }else{
        currentWord.Length = i;
    }
}
/* I.S. : currentChar sembarang
   F.S. : currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void igBlankFile(){
    while(currentChar==BLANK){
        advFile();
    }
}
/* Mengabaikan satu atau beberapa BLANK pada file
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK */

void advNewlineFile(){
    Word EMPTY = {"", 0};
    currentWord=EMPTY;
    if(currentChar == ENTER){
        EndWord = false;
        advFile();
        copywFile();
    }
}
/* I.S. : currentChar sembarang
   F.S. : currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */


void advNewline(){
    Word EMPTY = {"", 0};
    currentWord = EMPTY;
    if(currentChar == ENTER){
        advFile();
        copywFile();
    }
}
/* I.S. : currentChar sembarang
   F.S. : currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTCOMMAND () {
    START();
    IgnoreBlanks();
    if (currentChar == ENTER) {
        EndWord = true;
    } else {
        EndWord = false;
        ADVCOMMAND();
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
void ADVCOMMAND () {
    IgnoreDots();
    if (currentChar == ENTER && !EndWord) {
        EndWord = true;
    } else {
        CopyCommand();
        IgnoreDots();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyCommand () {
    int i;
    i = 0;
    while ((currentChar != BLANK) && (currentChar != ENTER)) {
        if (i < NMax) {
            currentCommand.TabWord[i] = currentChar;
            i++;
        }
        advTerminal();
    }
    currentCommand.Length = i;
}
void IgnoreDots() {
    while (currentChar == BLANK || currentChar == '.') {
         advTerminal();
    }
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
boolean isWordEqual(Word a, Word b) { 
    boolean cek=true;
    if (a.Length!=b.Length){
        return false;
    }else {
        for (int i=0;i<a.Length;i++){
            if (a.TabWord[i]!=b.TabWord[i]){
                cek=false;
            }
        }return cek;
    }
}
/* Mengembalikan true jika kata a dan b sama */
char* wordToString(Word word)
{
    char *str = (char *)malloc(sizeof(char) * word.Length);
    for (int i = 0; i < word.Length; i++)
    {
        str[i] = word.TabWord[i];
        if (i == word.Length - 1)
        {
            str[i + 1] = '\0';
        }
    }
    return str;
}
void displayWord(Word w)
{
    int i;
    for(i = 0; i<w.Length;i++){
        printf("%c", w.TabWord[i]);
    }
    printf("\n");
}
/* Menampilkan kata  w */

int wordToInt(Word word) {
    int num, i;
    
    num = 0;

    for (i = 0; i < word.Length; i++)
    {
        num = num * 10 + (word.TabWord[i] - '0');
    }
    return num;
}
int stringLength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

boolean StrComp(char *str,char *str2){ 
    boolean cek=true;
    if (stringLength(str)!= stringLength(str2)){
        return false;
    }else{
        for (int i=0;i<stringLength(str);i++){
            if(str[i]!=str2[i]){
                cek=false;
            }
        }
    }return cek;
}