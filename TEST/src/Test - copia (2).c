/* =============================================================================
   SDCC String BASICs Lib Test
   Version: 1.1
   Date: 26/07/2018
   Author: mvac7/303bcn
   Architecture: MSX
   Format: C Object (SDCC .rel)
   Programming language: C
   WEB: 
   mail: mvac7303b@gmail.com

   Description:

     
   History of versions:
     - v1.1 (26/07/2018)<
     - v1.0 (22/04/2016)
     
============================================================================= */


#include "../include/newTypes.h"
#include "../include/msxsystemvars.h"
#include "../include/msxBIOS.h"

#include "../include/memory.h"
#include "../include/textmode.h"
#include "../include/keyboard.h"
//#include "../include/stringB.h"


#define  HALT __asm halt __endasm   //wait for the next interrupt



void test();

//void KILLBUFFER();
//byte INKEY();
void INPUT(char* string);
void INPUTL(char* string, byte length);


void WAIT(uint cicles);



// =============================================================================
char strlen(char* string);

void strcpy(char* target, char* source);

void strcat(char* target, char* source);

boolean strcmp(char* string1, char* string2);

void LEFT(char* target, char* source, char length);

void RIGHT(char* target, char* source, char rightLength);

void MID(char* target, char* source, char leftPos, char length);

char INSTR(char* target, char asciicode, char offset);

void STRING(char* target, char length, char asciicode);

void SPACE(char* target, char length);
// =============================================================================



// constants  ------------------------------------------------------------------


const char text01[] = "Test SDCC String B Lib";
const char text02[] = "v1.1 (26/07/2018)";

const char text03[] = "Press any key to continue";


// Functions -------------------------------------------------------------------


//
void main(void)
{
    
  test();
  

//EXIT MSXDOS
/*  screen(0);
    
__asm
 	ld b,4(ix)
	ld c,#0x62
	call 5 
__endasm;*/
//end EXIT

  return;
}



void INPUT(char* string)
{
  INPUTL(string,32);
}


void INPUTL(char* string, byte length)
{
  //char string[16];
  byte aKey=0;
  byte size=0;
  //byte length; // <--------------------------------------------------------- AJUSTAR o PARAMETRIZAR
  
  KillBuffer();
  
  //length = strlen(string);
  
  while(1)
  {
    aKey = INKEY();
    if (aKey==13) break;
  
    if (aKey==8 && size>0)//BS
    {
      size--;
      //bchput(8); //32
      bchput(127); //del
      string[size]=32; 
    }
    /*if (aKey==29 && size>0)//left arrow
    {            
      size--;
      bchput(29); //32
      string[size]=32;
    }
    if (aKey==28 && size<length)//right arrow
    {            
      size++;
      bchput(28);
      string[size]=32;
    }*/
    if(aKey>31 && aKey<123 && size<length)
    {
      //if (aKey>96) aKey-=32; //lowercase
      string[size]=aKey;
      bchput(aKey);
      size++;
    }  
  }
  string[size]=0; //END mark

  return;
}



// Generates a pause in the execution of n interruptions.
// PAL: 50=1second. ; NTSC: 60=1second. 
void WAIT(uint cicles)
{
  uint i;
  for(i=0;i<cicles;i++) HALT;
}



// TEST ###############################################################
void test()
{
  char text[60];
  char text2[60];
  char string[] = "Lorem ipsum dolor sit amet";
  char testCat[] = ", consectetur adipiscing elit.";
  char result;
  
  COLOR(LIGHT_GREEN,DARK_GREEN,DARK_GREEN);      
  SCREEN0();
  WIDTH(40);
  
  LOCATE(0,0);
  PRINT(text01);
  LOCATE(0,1);
  PRINT(text02);
  

  PRINT("\n\ntext=");  
  PRINT("\nstring=");
  PRINT(string);
  PRINT("\ntestCat=");
  PRINT(testCat); 
  
  PRINT("\n\n>Test strlen(string)");
  result=strlen(string);
  PRINT("\nResult=");  
  PrintNumber(result);
  
  PRINT("\n\n>Test strcpy(text,string)");
  strcpy(text,string);
  PRINT("\nResult>text=");
  PRINT(text);
  PRINT("<");
  
  PRINT("\n\n>Test strcat(text,testCat)");  
  strcat(text,testCat);
  PRINT("\nResult>text=");
  PRINT(text);
  PRINT("<");
  
/*  strcpy(text,string);
  
  PRINT("\n\n");
  PRINT(">Test strncat(text,string,11)");
  PRINT("\ntext=");
  PRINT(text);
  strncat(text,string,11);
  PRINT("\nResult=");
  PRINT(text);
  
  PRINT("\n\n");
  PRINT(">Test subString(text,string,12,5)");
  subString(text,string,12,5);
  PRINT("\nResult=");
  PRINT(text);*/
  
/*
  LOCATE(0,14);
  PRINT(">Test INPUT:");
  INPUT(text); 
  LOCATE(0,15);
  PRINT("INPUT Result:");
  PRINT(text);
  PRINT("<");
*/

  LOCATE(0,23);
  PRINT(text03);
  INKEY();
  
  
//------------------------------------------------------------------------------ page 2  
  
  CLS();
  
  PRINT("text=");
  PRINT(text);  
  PRINT("\ntext2=");
  
  
  //void LEFT(char* target, char* source, char length)
  PRINT("\n\n>Test LEFT(target,source,length)");
  PRINT("\nLEFT(text2,text,11)");  
  LEFT(text2,text,11);  
  PRINT("\nResult>text2=");
  PRINT(text2);
  PRINT("<");
  
  //void RIGHT(char* target, char* source, char rightLength)
  PRINT("\n\n>Test RIGHT(target,source,length)");
  PRINT("\nRIGHT(text2,text,16)");  
  RIGHT(text2,text,16);  
  PRINT("\nResult>text2=");
  PRINT(text2);
  PRINT("<");
  
  //void MID(char* target, char* source, char leftPos, char length)
  PRINT("\n\n>Test MID(target,source,leftPos,length)");
  PRINT("\nMID(text2,text,12,14)");  
  MID(text2,text,12,14);  
  PRINT("\nResult>text2=");
  PRINT(text2);
  PRINT("<");
  
  //char INSTR(char* target, char asciicode, char offset)
  PRINT("\n\n>Test INSTR(target,asciicode,offset)");
  PRINT("\nINSTR(text2,' ',0)");
  result=INSTR(text2,' ',0);
  PRINT("\nResult=");  
  PrintNumber(result);
  PRINT("\nINSTR(text2,'a',7)");
  result=INSTR(text2,'a',7);
  PRINT("\nResult=");  
  PrintNumber(result);


  LOCATE(00,23);
  PRINT(text03);
  INKEY();
//------------------------------------------------------------------------------ page 3 
  
  CLS();
    
  //void STRING(char* target, char length, char asciicode) 
  PRINT("\n\n>Test STRING(target,length,asciicode)");
  PRINT("\nSTRING(text2,20,'-')");  
  STRING(text2,20,'-');  
  PRINT("\nResult>text2=");
  PRINT(text2);
  PRINT("<");
  
  //void SPACE(char* target, char length)
  PRINT("\n\n>Test SPACE(target,length)");
  PRINT("\nSPACE(text2,10)");  
  SPACE(text2,10);  
  PRINT("\nResult>text2=");
  PRINT(text2);
  PRINT("<");
  
  
  LOCATE(00,23);
  PRINT(text03);
  INKEY();

}





// =============================================================================
// =============================================================================
// =============================================================================
// =============================================================================
char strlen(char* string)
{
  char length = 0;
  while(*(string++)) length++;
  return length;
} 



/* =============================================================================
strcpy                                
Description : Copies the C string pointed by source into the array pointed by 
              target, including the terminating null character. 
Input    : target (string)
           source (string)
Output   : -
Author   : -
============================================================================= */
void strcpy(char* target, char* source) 
{
    while (*target++ = *source++);
}




/* =============================================================================
strcat                                
Description : Appends a copy of the source string to the target string. 
Input    : target (string)
           source (string)
Output   : -
Author   : -
============================================================================= */
void strcat(char* target, char* source) 
{
    while( *target ) target++;        /* find end of dst */
    while( *target++ = *source++ ) ;       /* Copy src to end of dst */
}



boolean strcmp(char* string1, char* string2)
{
  char index = 0;

  while (string1[index]!='\0' && string2[index]!='\0' && string1[index] == string2[index]) index++;

  if (string1[index]!='\0' || string2[index]!='\0') return false;

  return true;
}



//Returns a string composed of the leftmost x characters of the string A$.
//LEFT$(char* string, char leftpos) = string
void LEFT(char* target, char* source, char length)
{
  if (strlen(source)<length) return;              //size check
  while (length-->0) *target++ = *source++;  //copy
  *target = '\0';
}



//Returns a string composed of the right x characters of the string A$.
//RIGHT$(string,rightpos) = string
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

/*
MID$(string,initpos[,length])= string 
= substring
*/
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


/*
Returns the position of the first occurrence of a B$ substring in A$ string, starting from an optional offset (x).
INSTR([x,] stringA,stringB) = int
= int strcmp(const char *s1, const char *s2)
= indexOf()
*/
char INSTR(char* target, char asciicode, char offset)
{
  char counter;
  for (counter=0;counter<offset;counter++) target++;   //positioning
  while(*target)
  {
    counter++;
    if(*target++==asciicode) break;
  } 
  return counter;
}


/*
Returns a string with same char
STRING$(char length, char asciicode) = string
STRING$(8,65)
*/
void STRING(char* target, char length, char asciicode) 
{
  while (length-->0) *target++ = asciicode;
  *target = '\0';
}

/*
Generates a string with a specified number of spaces
SPACE$(char length) = string
= STRING$(length,32)
*/
void SPACE(char* target, char length) 
{
  STRING(target, length, 32); 
}



