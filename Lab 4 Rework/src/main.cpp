// Date:
// Assignment:
//
// Description: This file contains a programmatic overall description of the
// program. It should never contain assignments to special function registers
// for the exception key one-line code such as checking the state of the pin.
//
// Requirements:
//----------------------------------------------------------------------//

#include <avr/io.h>
#include <Arduino.h>
#include "PWM.h"
#include "timer.h" 
#include "adc.h"

int main(){

initPWMTimer4();
initTimer1();
//initTimer0();
//delayUs(2000);
initADC();
sei();
Serial.begin(9600);
unsigned int result=0;
  while(1){
    
   //delayUs(10000);
   //delayMs(1000);
   result=ADCL;
   result+=((unsigned int)ADCH) << 8;
   Serial.println((float)result/1024.00 *5.12);
   //Serial.println("V");
  }

  return 0;
}

ISR(TIMER1_COMPB_vect){
  turnON();
}
