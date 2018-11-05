/// Author:        Andrew Enriquez, 
// Net ID:         andrewenriquez, 
// Date:           10/24/2018
// Assignment:     Lab 4
//----------------------------------------------------------------------//

#include "timer.h"
#include "adc.h"

/* Initialize timer 0, you should not turn the timer on here.
* You will need to use CTC mode
*/
void initTimer0(){
  // Set the mode to be CTC
 /* TCCR0A |= (1 << WGM01);
  TCCR0A &= ~(1 << WGM00);
  TCCR0B &= ~(1 << WGM02);
  */ 

 // ^^ what is the difference between this and down???

  // Set the mode to be CTC
  TCCR0A |= (1 << WGM00);
    
}

/* Initialize timer 0, you should not turn the timer on here. You will need to
* use CTC mode
*/
void initTimer1(){
  //This is CTC mode for timer 1.
    TCCR1A &= ~(1 << WGM11 | 1 << WGM10 | 1 << WGM13);
    TCCR1B |= (1 << WGM12);
    TCCR1B |= (1 << CS11) | (1<<CS10);
    OCR1A = 250;
    TCCR1A |= (1 << COM1B0); //Toggle OC1A on compare match
     

  // Set the mode to be CTC for timer0
  /*
  TCCR0A |= (1 << WGM01);
  TCCR0A &= ~(1 << WGM00);
  TCCR0B &= ~(1 << WGM02);
*/
}

/* This delays the program an amount specified by unsigned int delay.
* Use timer 0. Keep in mind that you need to choose your prescalar wisely
* such that your timer is precise to 1 millisecond and can be used for 125
* 100 milliseconds
*/
void delayMs(unsigned int delay){

    OCR0A = delay * 250;

  // Make sure the appropriate flag is down
  TIFR0 |= (1 << OCF0A);

  // Clear the timer
  TCNT0 = 0;

  // turn on the timer by setting the pre-scaler to 8.
  //TCCR0B |= (1 << CS01);
  
  // turn on timer by setting the pre-scaler to 64.
  TCCR0B |= (1 << CS01) | (1 << CS00);

  for (unsigned int i; i <= delay; i++) {
     
     // while the flag is down, do not do anything.
  while(!(TIFR0 & (1 << OCF0A)));
  
  TIFR0 |= (1 << OCF0A); //set flag back up

  }
  
  // Turn the clock back off
  TCCR0B &= ~(1 << CS02 | 1 << CS01 | 1 << CS00);
}



/* This delays the program an amount specified by unsigned int delay.
*/
void delayUs(unsigned int delay){

    delay = 2*delay; //needed
  OCR1AH = (0xff & (delay >> 8)); //first 8 bits set to high
  OCR1AL = (0xff & (delay)); //last 8 bits set to low
  

  // clear the timer
  TCNT1 = 0;

  // calculate the TOP value and assign it to OCR1A
    TIFR1 |= (1 << OCF1A);


  // Turn on the timer
  TCCR1B |= (1 << CS11);
                
  // Do nothing while the OCF0A flag is not up
  while(!(TIFR1 & (1 << OCF1A)));
  
  //Timer/Counter1, Output Compare B Match Flag
  TIMSK1 |= (1 << OCF1A);
  

  // Turn off the timer
  TCCR1B &= ~(1 << CS12 | 1 << CS11 | 1 << CS10);
}
