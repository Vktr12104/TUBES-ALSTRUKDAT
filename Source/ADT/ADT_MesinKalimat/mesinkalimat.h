#ifndef __LINEMACHINE_H__
#define __LINEMACHINE_H__

#include "../boolean.h"
#include "../ADT_MesinKarakter/mesinkarakter.h"
#include "../ADT_Mesin-Kata/mesinkata.h"

#define NMaks 450
#define LineNew '\n'
#define MARK2 '\0'

typedef struct {
  char TabLine[NMaks+1];
  int Length;
} Kalimat;

/* State Mesin Kalimat */
extern boolean AkhirKalimat;
extern Kalimat ComLine;
extern Kalimat Input;

void IgnoreSemiColon() ;

void IgnoreLineNew();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void Ignoreblanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void SalinKalimat();

void SalinSatuKata();

void SalinRecordLoad() ;

void SalinInput() ;

void STARTKALIMATFILE(char NamaFile[]);

void StartInput () ;

void ADVKALIMAT();
void ADVSATUKATA();
void ADVRecord() ;
void ADVCommand() ;



boolean isKalimatEqual(Kalimat K1, Kalimat K2);
boolean isInputEqual (Kalimat Input, char * kata) ;


void ResetKalimat();
void ResetIn() ;

int length(char * S) ;
#endif
