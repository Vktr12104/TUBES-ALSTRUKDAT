#include <stdio.h>
#include "mesinkalimat.h"

boolean AkhirKalimat;
Kalimat ComLine;
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

void IgnoreLineNew()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == LineNew)
    {
        ADV();
    }
}

void SalinKalimat() {
    ResetKalimat(); 
    int i = 0;
    while ((currentChar != MARK) && (currentChar != LineNew) && (currentChar != EOF))
    {
        ComLine.TabLine[i] = currentChar;

        i+= 1;
        ADV();
    }
    ComLine.Length = i;
}

void SalinSatuKata() {
    ResetKalimat();  
    int i = 0 ;
    while ((currentChar != BLANK) && (currentChar != MARK))
    {
        ComLine.TabLine[i] = currentChar;
        i += 1;
        ADV();
    }
    ComLine.Length = i;
}

void SalinRecordLoad() {
    ResetKalimat() ;
    int x = 0 ;
    while ((currentChar != ';') && (currentChar != LineNew)) {
        ComLine.TabLine[x] = currentChar ;
        x ++ ;
        ADV();
    }
    ComLine.Length = x ;
}

void SalinInput() {
    ResetIn() ;
    int x = 0 ;
    while ((currentChar != LineNew) && (currentChar != MARK) && (currentChar != EOF)) {
        Input.TabLine[x] = currentChar ;
        x++ ;
        ADV() ;
    }
    Input.Length = x ;
}

void STARTKALIMATFILE(char NamaFile[]) {
    STARTFILE(NamaFile);
    IgnoreLineNew();
    if (currentChar == MARK2) {
        AkhirKalimat = true;
    } else {
        AkhirKalimat = false;
        SalinKalimat();
    }
}

void StartInput() {
    START() ;
    if (currentChar == ';') {
        AkhirKalimat = true ;
    } else {AkhirKalimat = false ;  SalinInput() ;}
}

void ADVKALIMAT(){
    IgnoreLineNew();
    Ignoreblanks();
    if (currentChar == MARK2) {
        AkhirKalimat = true;
    } else {
        AkhirKalimat = false;
        SalinKalimat();
    }
}

void ADVSATUKATA() {
    Ignoreblanks();
    IgnoreLineNew();
    if (currentChar == BLANK) {
        AkhirKalimat = true;
    } else {
        AkhirKalimat = false;
        SalinSatuKata();
    }
}

void ADVRecord() {
    Ignoreblanks() ; IgnoreLineNew() ; IgnoreSemiColon();
    if (currentChar == ';' || currentChar == '\n') {
        AkhirKalimat = true ;
    } else {
        AkhirKalimat = false ;
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
    for (int i = 0; i < sizeof(ComLine.TabLine); i++) {
        ComLine.TabLine[i] = '\0';
        ComLine.Length = 0;
    }
}