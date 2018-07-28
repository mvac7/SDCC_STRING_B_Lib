# SDCC String BASICs Functions Library (object type)

Version: 1.0

Date: 24/07/2018

Author: mvac7/303bcn

Architecture: MSX

Format: C Object (SDCC .rel)

Programming language: C

WEB:
 
mail: mvac7303b@gmail.com


History of versions:
- v1.0 (24/07/2018)< First version 



## 1. Introduction

This project is an Open Source library with basic functions for the treatment 
of arrays of characters and functions similar to those of the MSX BASIC.

For reasons of optimization, they work with 8-bit types (char) so the strings 
can only have up to 256 characters. If you need to work with larger strings, 
you can change the variables of type [char] to [unsigned int].
  
Use them for developing MSX applications using Small Device C Compiler (SDCC).

Includes an application for test and learning purposes.



## 2. Acknowledgments
  
Thanks for Info & help, to:

* Avelino Herrera > http://msx.atlantes.org/index_es.html
* Nerlaska > http://albertodehoyonebot.blogspot.com.es
* Fubu > http://www.gamerachan.org/fubu/
* Marq/Lieves!Tuore > http://www.kameli.net/lt/
* Sapphire/Z80ST > http://z80st.auic.es/
* Pentacour > http://pentacour.com/
* JamQue/TPM > http://www.thepetsmode.com/
* Andrear > http://andrear.altervista.org/home/msxsoftware.php
* Konamiman > https://www.konamiman.com
* MSX Assembly Page > http://map.grauw.nl/resources/msxbios.php
* Portar MSX Tech Doc > http://nocash.emubase.de/portar.htm
* MSX Resource Center > http://www.msx.org/
* Karoshi MSX Community > http://karoshi.auic.es/
* BlueMSX >> http://www.bluemsx.com/
* OpenMSX >> http://openmsx.sourceforge.net/
* Meisei  >> ?



## 3. Requirements

* Small Device C Compiler (SDCC) v3.6 http://sdcc.sourceforge.net/
* Hex2bin v2.2 http://hex2bin.sourceforge.net/ 



## 4. Functions

* strlen(char* source)=char - Returns the length of a string
* strcpy(char* target, char* source) - Copy the source string on the target string
* strcat(char* target, char* source) - Appends a copy of the source string to the target string
* strcmp(char* string1, char* string2)=boolean - Compare two strings 
* LEFT(char* target, char* source, char length) - Returns a section of the source string with the given length. Similar as MSX BASIC instruction LEFT$ 
* RIGHT(char* target, char* source, char rightLength) - Returns a section to the right of the source string with the given length. Similar as MSX BASIC instruction RIGHT$
* MID(char* target, char* source, char leftPos, char length) - Returns a section of the source string from the given position and length. Similar as MSX BASIC instruction MID$
* INSTR(char* source, char asciicode, char offset)=char - Find the first occurrence of a character in the given string. Similar as MSX BASIC instruction INSTR 
* STRING(char* target, char length, char asciicode) - Generates a string, composed with same char. Similar as MSX BASIC instruction STRING$
* SPACE(char* target, char length) - Generates a string composed with spaces. Similar as MSX BASIC instruction SPACE$ 

