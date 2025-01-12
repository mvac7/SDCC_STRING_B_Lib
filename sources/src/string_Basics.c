/* =============================================================================
String Basics Functions SDCC Library (fR3eL Project)
Version: 1.2 (12/1/2025)
Author: mvac7/303bcn
Architecture: MSX
Format: C object (SDCC .rel)
Programming language: C
Compiler: SDCC 4.4 or newer

fR3eL Project
https://github.com/mvac7/SDCC_MSX_fR3eL

Description:
	Selection of functions for managing C Strings (array of characters). 
	Includes functions similar to those of MSX BASIC.
	
	Remember that if you don't find the functions you need, 
	you can use the C String standard library.
 
	Warning: To optimize resources, it only accepts strings with a 
			 maximum length of 256 characters, except for the 
			 StrCopy and StrConcatenate functions.

History of versions:
- v1.2 (12/ 1/2025) Update to SDCC (4.1.12) Z80 calling conventions
- v1.1 (20/12/2023) Rename some functions and remove SPACE
- v1.0 (24/07/2018) first version
============================================================================= */



#include "../include/string_Basics.h"



/* =============================================================================
	StrLength (same as strlen)

	Function:	Returns the length of a string 
	Input:		[char*] string       
	Output:		[char] length 
============================================================================= */
char StrLength(char* source)
{
	char length = 0;
	while(*(source++)) length++;
	return length;
} 



/* =============================================================================
	StrCopy (same as strcpy)
	Function:	Copy the source string on the target string. 
	Input:		[char*] target string
				[char*] source string        
	Output:		-  
============================================================================= */
void StrCopy(char* target, char* source) 
{
    while ((*target++ = *source++) != '\0');
}



/* =============================================================================
	StrConcatenate (same as strcat)

	Function:	Concatenate a copy of the source string to the destination string.
				target = target + source 
	Input:		[char*] target string
				[char*] source string          
	Output:		-  
============================================================================= */
void StrConcatenate(char* target, char* source) 
{
    while( *target ) target++;        /* find end of target */
    while( *target++ = *source++ ) ;  /* Copy source to end of target */
}



/* =============================================================================
 StrCompare (same as strcmp)

 Function : Compare two strings
 Input    : [char*] first string
            [char*] second string         
 Output   : [boolean] result  
============================================================================= */
boolean StrCompare(char* string1, char* string2)
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
            [char]  length        
 Output   : -  
============================================================================= */
void LEFT(char* target, char* source, char length)
{
	if (StrLength(source)<length) return;              //size check
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
            [char]  length         
 Output   : -  
============================================================================= */
void RIGHT(char* target, char* source, char length)
{
	char i;
	char pos;
	char sourceLength = StrLength(source);

	if (sourceLength<length) return; //size check

	pos=sourceLength-length;

	for (i=0;i<pos;i++) source++;	//positioning
	while (*target++ = *source++);	//copy
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

  char sourceLength = StrLength(source);
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
            Similar as MSX BASIC instruction SPC$ 
 Input    : [char*] target string
            [char] length        
 Output   : -  
============================================================================= */
/*void SPACE(char* target, char length) 
{
  STRING(target, length, 32); 
}*/
