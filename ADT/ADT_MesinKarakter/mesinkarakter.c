#include<stdio.h>
#include<stdlib.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;
boolean finish;

static FILE *pita;
static int retval;

void START(){
    pita = stdin;
    ADV();
}

void ADV() {
    retval = fscanf(pita,"%c", &currentChar);
    EOP=currentChar==ENTER;
}

char GetCC() {
    return currentChar ;
}

boolean IsEOP() {
    return (currentChar == MARK) ;
}

void StartFile(char *str){
    finish = false;
    pita = fopen(str, "r");
    advFile();
}

void advFile() {
    retval = fscanf(pita,"%c", &currentChar);
    if(retval == EOF) {
        fclose(pita);
        finish = true;

    }
}
void advTerminal(){
    retval = fscanf(pita,"%c", &currentChar);
    EOP = (currentChar == ENTER);
}
