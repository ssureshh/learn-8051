// include 8051 header file
#include <8051.h>


// initialize delay function
// for giving delay between blinks ;)
void delay(void);
 

// initialize and define main function
void main(void){
    // run infinite loop
    while(1){
        // for pin 1 of port 1 -> P1_0 port 1 pin 1 
        // we have 8 pins for each port 0-7
        
        P1_0 = 1; //turn on the pin
        // give delay
        delay();
        P1_0 = 0; // turn off the pin
        // give delay
        delay();
    }
}

// delay definition
void delay(void){
    // initialize variable
    int i,j;
    // run some code for some time
    // so that we get some delay
    // this code does not do any useful work :()

    for(i=0;i<0xee;i++) //outer loop 0-255
         for(j=0;j<0xff;j++); // inner loop 0-255
}
