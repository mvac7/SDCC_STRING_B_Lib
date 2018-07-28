/* =============================================================================
   SDCC String BASICs Functions Library (object type)
   Version: 1.0
   Date: 24/07/2018
   Author: mvac7/303bcn
   Architecture: MSX
   Format: C Object (SDCC .rel)
   Programming language: C
   WEB: 
   mail: mvac7303b@gmail.com

   Description:
     Basic functions for the treatment of arrays of characters and 
     functions similar to those of the MSX BASIC.
   
   History of versions:
   - v1.0 (24/07/2018)< current version 
============================================================================= */


//https://en.wikibooks.org/wiki/C_Programming/String_manipulation


#include "../include/stringB.h"



/* =============================================================================
 strlen

 Function : Returns the length of a string 
 Input    : [char*] string       
 Output   : [char] length 
============================================================================= */
char strlen(char* source)
{
  char length = 0;
  while(*(source++)) length++;
  return length;
} 



/* =============================================================================
 strcpy

 Function : Copy the source string on the target string. 
 Input    : [char*] target string
            [char*] source string        
 Output   : -  
============================================================================= */
void strcpy(char* target, char* source) 
{
    while (*target++ = *source++);
}



/* =============================================================================
 strcat

 Function : Appends a copy of the source string to the target string. 
 Input    : [char*] target string
            [char*] source string          
 Output   : -  
============================================================================= */
void strcat(char* target, char* source) 
{
    while( *target ) target++;        /* find end of dst */
    while( *target++ = *source++ ) ;  /* Copy src to end of dst */
}



/* =============================================================================
 strcmp

 Function : Compare two strings 
 Input    : [char*] first string
            [char*] second string         
 Output   : [boolean] result  
============================================================================= */
boolean strcmp(char* string1, char* string2)
{
  char index = 0;

  while (string1[index]!='\0' && string2[index]!='\0' && string1[index] == string2[index]) index++;

  if (string1[index]!='\0' || string2[index]!='\0') return false;

  return true;
}



/* =============================================================================
 LEFT

 Function : Returns a section of the source string with the given length
            Similar as MSX BASIC instruction LEFT$ 
 Input    : [char*] target string
            [char*] source string
            [char] length        
 Output   : -  
============================================================================= */
void LEFT(char* target, char* source, char length)
{
  if (strlen(source)<length) return;              //size check
  while (length-->0) *target++ = *source++;  //copy
  *target = '\0';
}



/* =============================================================================
 RIGHT

 Function : Returns a section to the right of the source string with the given 
            length.
            Similar as MSX BASIC instruction RIGHT$  
 Input    : [char*] target string
            [char*] source string
            [char] length         
 Output   : -  
============================================================================= */
void RIGHT(char* target, char* source, char rightLength)
{
  char i;
  char pos;
  char sourceLength = strlen(source);
  
  if (sourceLength<rightLength) return; //size check
  pos=sourceLength-rightLength;
  
  for (i=0;i<pos;i++) source++;   //positioning
  while (*target++ = *source++); //copy
  *target = '\0';
}



/* =============================================================================
 MID

 Function : Returns a section of the source string from the given position and 
            length
            Similar as MSX BASIC instruction MID$  
 Input    : [char*] target string
            [char*] source string
            [char] position
            [char] length        
 Output   : -  
============================================================================= */
void MID(char* target, char* source, char leftPos, char length)
{
  char i;

  char sourceLength = strlen(source);
  if (sourceLength<leftPos) return; //size check
  if (length>(sourceLength-leftPos)) length=sourceLength-leftPos;

  for (i=0;i<leftPos;i++) source++;   //positioning
  for (i=0;i<length;i++) *target++ = *source++;  //copy
  *target = '\0';
}



/* =============================================================================
 INSTR

 Function : Find the first occurrence of a character in the given string
            Similar as MSX BASIC instruction INSTR  
 Input    : [char*] source string
            [char] ascii code
            [char] offset        
 Output   : [char] position  
============================================================================= */
char INSTR(char* source, char asciicode, char offset)
{
  char counter;
  for (counter=0;counter<offset;counter++) source++;   //positioning
  while(*source)
  {
    counter++;
    if(*source++==asciicode) break;
  } 
  return counter;
}



/* =============================================================================
 STRING

 Function : Generates a string composed with same char
            Similar as MSX BASIC instruction STRING$  
 Input    : [char*] target string
            [char] length
            [char] asciicode        
 Output   : -  
============================================================================= */
void STRING(char* target, char length, char asciicode) 
{
  while (length-->0) *target++ = asciicode;
  *target = '\0';
}



/* =============================================================================
 SPACE

 Function : Generates a string composed with spaces
            Similar as MSX BASIC instruction SPACE$ 
 Input    : [char*] target string
            [char] length        
 Output   : -  
============================================================================= */
void SPACE(char* target, char length) 
{
  STRING(target, length, 32); 
}
