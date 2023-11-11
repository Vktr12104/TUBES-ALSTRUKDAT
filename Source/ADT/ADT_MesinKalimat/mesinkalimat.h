#ifndef __LINEMACHINE_H__
#define __LINEMACHINE_H__

#include "boolean.h"
#include "../ADT_MesinKarakter/mesinkarakter.h"
#include "../ADT_Mesin-Kata/mesinkata.h"

#define NMaks 450
#define NEWLINE '\n'
#define MARK2 '\0'

typedef struct {
  char TabLine[NMaks+1];
  int Length;
} Kalimat;

/* State Mesin Kalimat */
extern boolean EndKalimat;
extern Kalimat CLine;
extern Kalimat Input;

void IgnoreSemiColon() ;
void IgnoreNewline();
void Ignoreblanks();

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
