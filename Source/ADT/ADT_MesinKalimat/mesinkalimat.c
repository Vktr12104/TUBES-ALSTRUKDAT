#include <stdio.h>
#include "mesinkalimat.h"

boolean EndKalimat;
Kalimat CLine;
Kalimat Input;
Kalimat Command;

void IgnoreSemiColon() 
{
    while (currentChar == ';') {
        ADV() ;
    }
}

void Ignoreblanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void IgnoreNewline()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == NEWLINE)
    {
        ADV();
    }
}

void SalinKalimat() {
    ResetKalimat(); 
    int i = 0;
    while ((currentChar != MARK) && (currentChar != NEWLINE) && (currentChar != EOF))
    {
        CLine.TabLine[i] = currentChar;

        i+= 1;
        ADV();
    }
    CLine.Length = i;
}

void SalinSatuKata() {
    ResetKalimat();  
    int i = 0 ;
    while ((currentChar != BLANK) && (currentChar != MARK))
    {
        CLine.TabLine[i] = currentChar;
        i += 1;
        ADV();
    }
    CLine.Length = i;
}

void SalinRecordLoad() {
    ResetKalimat() ;
    int x = 0 ;
    while ((currentChar != ';') && (currentChar != NEWLINE)) {
        CLine.TabLine[x] = currentChar ;
        x ++ ;
        ADV();
    }
    CLine.Length = x ;
}

void SalinInput() {
    ResetIn() ;
    int x = 0 ;
    while ((currentChar != NEWLINE) && (currentChar != MARK) && (currentChar != EOF)) {
        Input.TabLine[x] = currentChar ;
        x++ ;
        ADV() ;
    }
    Input.Length = x ;
}

void STARTKALIMATFILE(char NamaFile[]) {
    STARTFILE(NamaFile);
    IgnoreNewline();
    if (currentChar == MARK2) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimat();
    }
}

void StartInput() {
    START() ;
    if (currentChar == ';') {
        EndKalimat = true ;
    } else {EndKalimat = false ;  SalinInput() ;}
}

void ADVKALIMAT(){
    IgnoreNewline();
    Ignoreblanks();
    if (currentChar == MARK2) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimat();
    }
}

void ADVSATUKATA() {
    Ignoreblanks();
    IgnoreNewline();
    if (currentChar == BLANK) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinSatuKata();
    }
}

void ADVRecord() {
    Ignoreblanks() ; IgnoreNewline() ; IgnoreSemiColon();
    if (currentChar == ';' || currentChar == '\n') {
        EndKalimat = true ;
    } else {
        EndKalimat = false ;
        SalinRecordLoad() ;
    }
}



boolean isKalimatEqual(Kalimat K1, Kalimat K2) 
{   
    boolean equal = true;
    if (K1.Length == K2.Length)
    {
        int i = 0;
        while (i < K1.Length && equal)
        {
            if (K1.TabLine[i] != K2.TabLine[i])
            {
                equal = false;
            }
            else
            {
                i++;
            }
        }
        return equal;
    }
    else
    {
        return false;
    }
}

boolean isInputEqual(Kalimat Input, char * kata) {
    boolean eq = true ;
    if (Input.Length == length(kata) ) {
        int i = 0 ;
        while (eq && i < Input.Length) {
            if (Input.TabLine[i] != kata[i]) {
                eq = false ;
            } else { i++ ;}
        } return eq;
    } else {
        return false ;
    }
}


int length (char * S) {
    int i = 0 ;
    while (S[i] != '\0') {
        i++ ;
    } return i ;
}

void ResetIn() {
    for (int x = 0 ; x < sizeof(Input.TabLine) ; x++) {
        Input.TabLine[x] = '\0' ;
        Input.Length = 0 ;
    }
}

void ResetKalimat() {
    for (int i = 0; i < sizeof(CLine.TabLine); i++) {
        CLine.TabLine[i] = '\0';
        CLine.Length = 0;
    }
}