/* =============================================================================
Test string_Basics Library
Version: 1.2 (12/01/2025)
Author: mvac7/303bcn
Architecture: MSX
Format: MSX 8K ROM
Programming language: C and Z80 assembler
Compiler: SDCC 4.4 or newer
 
History of versions:
- v1.2 (12/01/2025) update to SDCC (4.1.12) Z80 calling conventions
- v1.1 (26/07/2018)
- v1.0 (22/04/2016)     
============================================================================= */


#include "../include/newTypes.h"
#include "../include/msxBIOS.h"
#include "../include/msxSystemVariables.h"

#include "../include/memoryZ80.h"
#include "../include/textmode_MSX.h"
#include "../include/keyboard_MSX.h"

#include "../include/string_Basics.h"


#define  HALT __asm halt __endasm   //wait for the next interrupt



void test(void);


//void INPUT(char* string);
//void INPUTL(char* string, char length);


void WAIT(uint cicles);

void PrintBool(boolean bvalue);


// constants  ------------------------------------------------------------------


const char txtAppAbout[] = "Test string_Basics Library";
const char txtPressKey[] = "Press any key to continue";
//const char endChar[] = "\xdd";




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



/*void INPUT(char* string)
{
  INPUTL(string,32);
}*/



/*void INPUTL(char* string, char length)
{
  //char string[16];
  char aKey=0;
  char size=0;
  
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
//    if (aKey==29 && size>0)//left arrow
//    {            
//      size--;
//      bchput(29); //32
//      string[size]=32;
//    }
//    if (aKey==28 && size<length)//right arrow
//    {            
//      size++;
//      bchput(28);
//      string[size]=32;
//    }
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
}*/



// Generates a pause in the execution of n interruptions.
// PAL: 50=1second. ; NTSC: 60=1second. 
void WAIT(uint cicles)
{
  uint i;
  for(i=0;i<cicles;i++) HALT;
}



// TEST ###############################################################
void test(void)
{
  char text1[60];
  char text2[60];
  char string1[] = "Lorem ipsum dolor sit amet";
  char string2[] = ", consectetur adipiscing elit.";
  char result;
  boolean resbool;


//------------------------------------------------------------------------------ page 1  
  COLOR(LIGHT_GREEN,DARK_GREEN,DARK_GREEN);      
  SCREEN0();
  WIDTH(40);
  
  LOCATE(0,0);
  PRINT(txtAppAbout);

  PRINT("\n\ntext1=");  
  PRINT("\nstring1=");
  PRINT(string1);
  PRINT("\nstring2=");
  PRINT(string2); 
  
  //char StrLength(char* string1)
  PRINT("\n\n>Test StrLength(string1)");
  result=StrLength(string1);
  PRINT("\nResult=");  
  PrintNumber(result);
  
  //void StrCopy(char* target, char* source)
  PRINT("\n\n>Test StrCopy(text1,string1)");
  StrCopy(text1,string1);
  PRINT("\nResult>text1=");
  PRINT(text1);
  
  //void StrConcatenate(char* target, char* source)
  PRINT("\n\n>Test StrConcatenate(text1,string2)");  
  StrConcatenate(text1,string2);
  PRINT("\nResult>text1=");
  PRINT(text1);
  
  PRINT("\n\n>Test StrCompare(string1,string2)");  
  
  PRINT("\nStrCompare(\"turboR\",\"MSX3\")=");
  resbool = StrCompare("turboR","MSX3");	//must return false
  PrintBool(resbool);
  
  PRINT("\nStrCompare(\"TMS9918A\",\"tms9918a\")=");
  resbool = StrCompare("TMS9918A","tms9918a");	//must return false
  PrintBool(resbool);
  
  PRINT("\nStrCompare(\"1234567890\",\"1234\")=");
  resbool = StrCompare("1234567890","1234");	//must return false
  PrintBool(resbool);
  
  PRINT("\nStrCompare(\"EqU4L\",\"EqU4L\")=");
  resbool = StrCompare("EqU4L","EqU4L");	//must return true
  PrintBool(resbool);
  

  LOCATE(0,23);
  PRINT(txtPressKey);
  INKEY();
  
  
//------------------------------------------------------------------------------ page 2
  CLS();
  
  PRINT("text1=");
  PRINT(text1);  
  PRINT("\ntext2=");
  
  
  //void LEFT(char* target, char* source, char length)
  PRINT("\n\n>Test LEFT(target,source,length)");
  PRINT("\nLEFT(text2,text1,11)");  
  LEFT(text2,text1,11);  
  PRINT("\nResult>text2=");
  PRINT(text2);
  
  //void RIGHT(char* target, char* source, char rightLength)
  PRINT("\n\n>Test RIGHT(target,source,length)");
  PRINT("\nRIGHT(text2,text1,16)");  
  RIGHT(text2,text1,16);  
  PRINT("\nResult>text2=");
  PRINT(text2);
    
  //void MID(char* target, char* source, char leftPos, char length)
  PRINT("\n\n>Test MID(target,source,leftPos,length)");
  PRINT("\nMID(text2,text1,12,14)");  
  MID(text2,text1,12,14);  
  PRINT("\nResult>text2=");
  PRINT(text2);
  
  //char INSTR(char* target, char asciicode, char offset)
  PRINT("\n\n>Test INSTR(target,asciicode,offset)");
  PRINT("\nINSTR(text1,' ',0)");
  result=INSTR(text1,' ',0);
  PRINT("\nResult=");  
  PrintNumber(result);
  PRINT("\nINSTR(text1,32,7)");
  result=INSTR(text1,32,7);
  PRINT("\nResult=");  
  PrintNumber(result);


  LOCATE(00,23);
  PRINT(txtPressKey);
  INKEY();
  
//------------------------------------------------------------------------------ page 3
  CLS();
    
  //void STRING(char* target, char length, char asciicode) 
  PRINT(">Test STRING(target,length,asciicode)");
  PRINT("\nSTRING(text1,20,'-')");  
  STRING(text1,20,'-');  
  PRINT("\nResult>text1=");
  PRINT(text1);
  
/* void SPACE(char* target, char length)
  PRINT("\n\n>Test SPACE(target,length)");
  PRINT("\nSPACE(text2,10)");  
  SPACE(text2,10);  
  PRINT("\nResult>text2=");
  PRINT(text2);
  PRINT("<");
*/  
  
  LOCATE(00,23);
  PRINT(txtPressKey);
  INKEY();
  
//------------------------------------------------------------------------------ end
  CLS();
  PRINT("END TEST");
  WAIT(120);
  
}



void PrintBool(boolean bvalue)
{
  if(bvalue==true) PRINT("true"); 
  else PRINT("false"); 	
}

