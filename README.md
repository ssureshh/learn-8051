# Learning micro-controllers from scratch series, Part-1, The 8051
## Table of content
- [Introduction]()
- [My setup, the bare minimum]()
- [MacOS Setup]()
- [Linux Setup]()
- Programs/Experiments/Tests
	- [0 - C program blink test]()
	- [1 - Assembly test]()


## Introduction
- Goal is to build a complete project with the 8051
- Most probably will try to code the project in assembly, apart from C programming
- Will use the SDCC compile suite. All the codes written in this repo is compiled, assembled and linked with the SDCC suite.

## MacOS Setup
- Download the SDCC compile package for MacOS
- Unzip the downloaded package
- add the sdcc/bin folder to path
- Make sure AvrDude is installed

```bash
# this allows to run apps from unidentified developers such as the sdcc compiler
$ sudo spctl --master-disable
$ tar xvf sdcc-xyz.tar.bz2
$ export PATH=$PATH:<path-to-dir>sdcc/bin
$ brew install avrdude
```
- Write a simple C code to tes
```c
#include <8051.h>
void delay(void);
void main(void){
    while(1){
        P1_0 = 1; //turn on the pin
        delay();
        P1_0 = 0; // turn off the pin
        delay();
    }
}
// delay definition
void delay(void){
    int i,j;
    for(i=0;i<0xff;i++) //outer loop 0-255
         for(j=0;j<0xff;j++); // inner loop 0-255
}
```
- Compile with SDCC compiler
```bash
$ sdcc blink.c
$ ls 
total 280
-rw-r--r--  1 suresh  staff   8.1K Mar 25 21:54 blink.asm
-rw-r--r--  1 suresh  staff   789B Mar 25 21:53 blink.c
-rw-r--r--  1 suresh  staff   452B Mar 25 21:54 blink.ihx
-rw-r--r--  1 suresh  staff   275B Mar 25 21:54 blink.lk
-rw-r--r--  1 suresh  staff    23K Mar 25 21:54 blink.lst
-rw-r--r--  1 suresh  staff    17K Mar 25 21:54 blink.map
-rw-r--r--  1 suresh  staff   1.1K Mar 25 21:54 blink.mem
-rw-r--r--  1 suresh  staff   3.5K Mar 25 21:54 blink.rel
-rw-r--r--  1 suresh  staff    23K Mar 25 21:54 blink.rst
-rw-r--r--  1 suresh  staff    38K Mar 25 21:54 blink.sym
```
- Flash with avrdude
```bash
$ avrdude -c stk500v1 -P /dev/tty.usbmodem14201 -b 19200 -C +8051-52-avrdude.conf -p AT89S52 -e -U flash:w:blink.ihx:i
```
