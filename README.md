# String BASICs SDCC Library (fR3eL project)

<table>
<tr><td>Architecture</td><td>MSX</td></tr>
<tr><td>Format</td><td>C Object (SDCC .rel)</td></tr>
<tr><td>Programming language</td><td>C and Z80 assembler</td></tr>
<tr><td>Compiler</td><td>SDCC v4.4 or newer</td></tr>
</table>

---

## Description

Library with basic functions for the managing C Strings (array of characters) and functions similar to those of the MSX BASIC.

**Warning:** To optimize resources, it only accepts strings with a maximum length of 255 characters, except for the __StrCopy__ and __StrConcatenate__ functions.
If you need to work with larger strings, you can change the input values of type __char__ to __unsigned int__.

Remember that if you don't find the functions you need, you can use the C String standard library.

You can access the documentation here with [`How to use the library`](docs/HOWTO.md).

In the source code [`examples/`](examples/), you can find applications for testing and learning purposes.

This project is an Open Source library. 
You can add part or all of this code in your application development or include it in other libraries/engines.

Use them for developing MSX applications using Small Device C Compiler [`SDCC`](http://sdcc.sourceforge.net/).

This library is part of the [MSX fR3eL Project](https://github.com/mvac7/SDCC_MSX_fR3eL).

Enjoy it!

<br/>

---

## History of versions
- v1.2 (12/ 1/2025) Update to SDCC (4.1.12) Z80 calling conventions
- v1.1 (20/12/2023) Rename some functions and remove SPACE
- v1.0 (24/07/2018)< First version 


<br/>

---

## Requirements

- [Small Device C Compiler (SDCC) v4.4](http://sdcc.sourceforge.net/)
- [Hex2bin v2.5](http://hex2bin.sourceforge.net/)



## Functions

### Functions similar to some functions from C String standard library

| Function | Description |
| :---     | :---        |
| char **StrLength**(char* source) | Returns the length of a string |
| **StrCopy**(char* target, char* source) | Copy the source string on the target string |
| **StrConcatenate**(char* target, char* source) | Appends a copy of the source string to the target string |
| boolean **StrCompare**(char* string1, char* string2) | Compare two strings |

<br/>

### Functions similar to MSX BASIC instructions:

| Function | Description |
| :---     | :---        |
| **LEFT**(char* target, char* source, char length) | Returns a section of the source string with the given length. |
| **RIGHT**(char* target, char* source, char rightLength) | Returns a section to the right of the source string with the given length. |
| **MID**(char* target, char* source, char leftPos, char length) | Returns a section of the source string from the given position and length. |
| char **INSTR**(char* source, char asciicode, char offset) | Find the first occurrence of a character in the given string. |
| **STRING**(char* target, char length, char asciicode) | Generates a string, composed with same char. |


