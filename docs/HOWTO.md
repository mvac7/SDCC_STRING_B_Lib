# How to use the String Basics SDCC Library

| Attention! |
| :---       |
| The following document has been written using an English translator.<br/>You can participate in the improvement of this document, transmitting your corrections or suggestions in the issues of this project or the main fR3eL project.<br/>Thanks for understanding. |

<br/>

## Index

- [1 Description](#1-Description)
- [2 Requirements](#2-Requirements)
- [3 Definitions](#3-Definitions)
	- [3.1 boolean type](#31-boolean-type)
- [4 Functions](#4-Functions)
	- [4.1 StrLength](#41-StrLength)
	- [4.2 StrCopy](#42-StrCopy)
	- [4.3 StrConcatenate](#43-StrConcatenate)
	- [4.4 StrCompare](#44-StrCompare)
	- [4.5 LEFT](#45-LEFT)
	- [4.6 RIGHT](#46-RIGHT)
	- [4.7 MID](#47-MID)
	- [4.8 INSTR](#48-INSTR)
	- [4.9 STRING](#49-STRING)
- [5 References](#5-References)

<br/>

---

## 1 Description

Library with basic functions for the managing C Strings (array of characters).

**Warning:** To optimize resources, it only accepts strings with a maximum length of 255 characters, except for the __StrCopy__ and __StrConcatenate__ functions.
If you need to work with larger strings, you can change the input values of type __char__ to __unsigned int__.

Remember that if you don't find the functions you need, you can use the C String standard library.

This project is an Open Source library. 
You can add part or all of this code in your application development or include it in other libraries/engines.

Use them for developing MSX applications using Small Device C Compiler [`SDCC`](http://sdcc.sourceforge.net/).

This library is part of the [MSX fR3eL Project](https://github.com/mvac7/SDCC_MSX_fR3eL).


<br/>

---

## 2 Requirements

- [Small Device C Compiler (SDCC) v4.4](http://sdcc.sourceforge.net/)
- [Hex2bin v2.5](http://hex2bin.sourceforge.net/)


<br/>

---

## 3 Definitions

### 3.1 boolean type

Label | Value
----- | -----
false | 0
true  | 1


<br/>

---

## 4 Functions

### 4.1 StrLength

<table>
<tr><th colspan=3 align="left">StrLength</th></tr>
<tr><td colspan=3>Returns the length of a string</td></tr>
<tr><th>Function</th><td colspan=2>char StrLength(char* source)</td></tr>
<tr><th>Input</th><td><pre>char*</pre></td><td>string</td></tr>
<tr><th>Output</th><td><pre>char</pre></td><td>length</td></tr>
<tr><th>Example:</th><td colspan=2><pre>
char result;
result=StrLength("Hello World!");	//result=12
</pre></td></tr>
</table>

<br/>

### 4.2 StrCopy

<table>
<tr><th colspan=3 align="left">StrCopy</th></tr>
<tr><td colspan=3>Copy the source string on the target string</td></tr>
<tr><th>Function</th><td colspan=2>StrCopy(char* target, char* source)</td></tr>
<tr><th rowspan=2>Input</th><td><pre>char*</pre></td><td>target string</td></tr>
<tr><td><pre>char*</pre></td><td>source string</td></tr>
<tr><th>Output</th><td colspan=2>--</td></tr>
<tr><th>Example:</th><td colspan=2><pre>
char text[60];
char string[] = "Lorem ipsum dolor sit amet";
StrCopy(text,string);
</pre></td></tr>
</table>

<br/>

### 4.3 StrConcatenate

<table>
<tr><th colspan=3 align="left">StrConcatenate</th></tr>
<tr><td colspan=3>Appends a copy of the source string to the target string</td></tr>
<tr><th>Function</th><td colspan=2>StrConcatenate(char* target, char* source)</td></tr>
<tr><th rowspan=2>Input</th><td><pre>char*</pre></td><td>target string</td></tr>
<tr><td><pre>char*</pre></td><td>source string</td></tr>
<tr><th>Output</th><td colspan=2>--</td></tr>
<tr><th>Example:</th><td colspan=2><pre>
char text[60];
char string[] = "Lorem ipsum dolor sit amet";
char testCat[] = ", consectetur adipiscing elit.";
StrCopy(text,string);
StrConcatenate(text,testCat);
</pre></td></tr>
</table>

<br/>

### 4.4 StrCompare

<table>
<tr><th colspan=3 align="left">StrCompare</th></tr>
<tr><td colspan=3>Compare two strings</td></tr>
<tr><th>Function</th><td colspan=2>boolean StrCompare(char* string1, char* string2)</td></tr>
<tr><th rowspan=2>Input</th><td><pre>char*</pre></td><td>first string</td></tr>
<tr><td><pre>char*</pre></td><td>second string</td></tr>
<tr><th>Output</th><td><pre>boolean</pre></td><td>result</td></tr>
<tr><th>Example:</th><td colspan=2><pre>
boolean result;
result = StrCompare("turboR","MSX3");		//must return false
result = StrCompare("TMS9918A","tms9918a");	//must return false
result = StrCompare("1234567890","1234");	//must return false
result = StrCompare("EqU4L","EqU4L");		//must return true
</pre></td></tr>
</table>

<br/>

### 4.5 LEFT

<table>
<tr><th colspan=3 align="left">LEFT</th></tr>
<tr><td colspan=3>Returns a section of the source string with the given length<br/>Similar as MSX BASIC instruction LEFT$</td></tr>
<tr><th>Function</th><td colspan=2>LEFT(char* target, char* source, char length)</td></tr>
<tr><th rowspan=3>Input</th><td><pre>char*</pre></td><td>target string</td></tr>
<tr><td><pre>char*</pre></td><td>source string</td></tr>
<tr><td><pre>char</pre></td><td>length</td></tr>
<tr><th>Output</th><td colspan=2>--</td></tr>
<tr><th>Example:</th><td colspan=2><pre>
char text[60];
char string1[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
LEFT(text,string1,11);	//text="Lorem ipsum"
</pre></td></tr>
</table>

<br/>

### 4.6 RIGHT

<table>
<tr><th colspan=3 align="left">RIGHT</th></tr>
<tr><td colspan=3>Returns a section to the right of the source string with the given length.<br/>Similar as MSX BASIC instruction RIGHT$</td></tr>
<tr><th>Function</th><td colspan=2>RIGHT(char* target, char* source, char length)</td></tr>
<tr><th rowspan=3>Input</th><td><pre>char*</pre></td><td>target string</td></tr>
<tr><td><pre>char*</pre></td><td>source string</td></tr>
<tr><td><pre>char</pre></td><td>length</td></tr>
<tr><th>Output</th><td colspan=2>--</td></tr>
<tr><th>Example:</th><td colspan=2><pre>
char text[60];
char string1[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
RIGHT(text,string1,16);	//text="adipiscing elit."
</pre></td></tr>
</table>

<br/>

### 4.7 MID

<table>
<tr><th colspan=3 align="left">MID</th></tr>
<tr><td colspan=3>Returns a section of the source string from the given position and length.<br/>Similar as MSX BASIC instruction MID$</td></tr>
<tr><th>Function</th><td colspan=2>MID(char* target, char* source, char leftPos, char length)</td></tr>
<tr><th rowspan=4>Input</th><td><pre>char*</pre></td><td>target string</td></tr>
<tr><td><pre>char*</pre></td><td>source string</td></tr>
<tr><td><pre>char</pre></td><td>position</td></tr>
<tr><td><pre>char</pre></td><td>length</td></tr>
<tr><th>Output</th><td colspan=2>--</td></tr>
<tr><th>Example:</th><td colspan=2><pre>
char text[60];
char string1[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
MID(text,string1,12,14);	//text="dolor sit amet"
</pre></td></tr>
</table>

<br/>

### 4.8 INSTR

<table>
<tr><th colspan=3 align="left">INSTR</th></tr>
<tr><td colspan=3>Find the first occurrence of a character in the given string.<br/>Similar as MSX BASIC instruction INSTR</td></tr>
<tr><th>Function</th><td colspan=2>char INSTR(char* source, char asciicode, char offset)</td></tr>
<tr><th rowspan=3>Input</th><td><pre>char*</pre></td><td>source string</td></tr>
<tr><td><pre>char</pre></td><td>ascii code</td></tr>
<tr><td><pre>char</pre></td><td>offset</td></tr>
<tr><th>Output</th><td><pre>char</pre></td><td>position</td></tr>
<tr><th>Example:</th><td colspan=2><pre>
char result;
char string1[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
result=INSTR(string1,' ',0);	//result=6
result=INSTR(string1,32,7);	//result=12
</pre></td></tr>
</table>

<br/>

### 4.9 STRING

<table>
<tr><th colspan=3 align="left">STRING</th></tr>
<tr><td colspan=3>Generates a string, composed with same char.<br/>Similar as MSX BASIC instruction STRING$</td></tr>
<tr><th>Function</th><td colspan=2>STRING(char* target, char length, char asciicode)</td></tr>
<tr><th rowspan=3>Input</th><td><pre>char*</pre></td><td>target string</td></tr>
<tr><td><pre>char</pre></td><td>length</td></tr>
<tr><td><pre>char</pre></td><td>asciicode</td></tr>
<tr><th>Output</th><td colspan=2>--</td></tr>
<tr><th>Example:</th><td colspan=2><pre>
char text[20];
STRING(text,20,'-');	//text="--------------------"
</pre></td></tr>
</table>

<br/>

---

## 5 References

- [C Programming](https://en.wikibooks.org/wiki/C_Programming) - [String manipulation](https://en.wikibooks.org/wiki/C_Programming/String_manipulation)


<br/>

---

![Creative Commons License](https://i.creativecommons.org/l/by-nc/4.0/88x31.png) 
<br/>This document is licensed under a [Creative Commons Attribution-NonCommercial 4.0 International License](http://creativecommons.org/licenses/by-nc/4.0/) - (by Wikibooks)