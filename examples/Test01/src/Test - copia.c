/* =============================================================================
   Test
   v1.0 (29 Enero 2016)
   Description:

============================================================================= */

#include "../include/newTypes.h"
//#include "../include/VDP_TMS9918.h"
#include "../include/memory.h"
#include "../include/textmode.h"
#include "../include/msxsystemvars.h"
#include "../include/msxBIOS.h"


#define  HALT __asm halt __endasm   //wait for the next interrupt



void test_SC0();
void test_SC1();

byte inkey();
void WAIT(uint cicles);


// constants  ------------------------------------------------------------------


const char text01[] = "Test C textmode library";
const char text02[] = "v1 (27/Ene/2016)";



// Functions -------------------------------------------------------------------


//
void main(void)
{
    
  test_SC0();
  
  test_SC1();
  

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



/* =============================================================================
One character input (waiting)
============================================================================= */
byte inkey(){
__asm   
   call CHGET
   ld   L,A
__endasm;
}




// Generates a pause in the execution of n interruptions.
// PAL: 50=1second. ; NTSC: 60=1second. 
void WAIT(uint cicles)
{
  uint i;
  for(i=0;i<cicles;i++) HALT;
  return;
}



// TEST ###############################################################
void test_SC0()
{
  int  intvalue=12345;
  byte bytevalue=127;
  
  COLOR(LIGHT_GREEN,DARK_GREEN,DARK_GREEN);      
  SCREEN0();
  WIDTH(40);
  
  LOCATE(0,0);
  PRINT(text01);
  LOCATE(0,1);
  PRINT(text02);
  LOCATE(31,23);
  
  PRINT("SCREEN 0"); 
  LOCATE(0,6);
  PRINT(">Test PRINT function");
  LOCATE(0,7);
  PRINT(">Test PRINT function with newline Esc\n Line 2.\n Line 3. Last line.");
  
  LOCATE(0,10);
  PRINT(">Test PrintNumber function:");
  PrintNumber(2400);
  
  LOCATE(0,11);
  PRINT(">Test PrintNumber (int):");
  PrintNumber(intvalue);
  
  LOCATE(0,12);
  PRINT(">Test PrintNumber (byte):");
  PrintNumber(bytevalue);
   
  LOCATE(10,18);
  PRINT("Press a key to exit");
  inkey();
  
  CLS();
  LOCATE(0,7);
  PRINT(">Test CLS function");
  
  LOCATE(10,18);
  PRINT("Press a key to exit");
  inkey();
 
  return;
}



// TEST ###############################################################
void test_SC1()
{
  int  intvalue=31416;
  byte bytevalue=255;
  
  COLOR(BLACK,GRAY,DARK_BLUE);      
  SCREEN1();
  WIDTH(32);  
  
  LOCATE(0,0);
  PRINT(text01);
  LOCATE(0,1);
  PRINT(text02);
  
  LOCATE(23,23);
  PRINT("SCREEN 1"); 
  LOCATE(0,6);
  PRINT(">Test PRINT func");
  LOCATE(0,7);
  PRINT(">Test PRINT func newline\n Line 2.\n Line 3. Last line.");
  
  LOCATE(0,10);
  PRINT(">Test PrintNumber function:");
  PrintNumber(6400);
  
  LOCATE(0,11);
  PRINT(">Test PrintNumber (int):");
  PrintNumber(intvalue);
  
  LOCATE(0,12);
  PRINT(">Test PrintNumber (byte):");
  PrintNumber(bytevalue);
    
  LOCATE(4,18);
  PRINT("Press a key to exit");
  inkey();
  
  CLS();
  LOCATE(0,7);
  PRINT(">Test CLS function");
  
  LOCATE(4,18);
  PRINT("Press a key to exit");
  inkey();
 
  return;
}
