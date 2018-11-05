/// Author:        Rachael Seedenburg, 
// Net ID:         rtseeden, 
// Date:           10/28/2018
// Assignment:     Lab 4
//------------------------------------------------------------------//
// Description: This file implements the initialization of an external
// switch.
//----------------------------------------------------------------------//

#include "switch.h"
#include <avr/io.h>

/*
 * Initializes pull-up resistor on PB3 and sets it into input mode
 */
void initSwitchPB3(){
  // enable pin-change interrupts
  // enable interrupts on PB3
    DDRB &= ~(1<<DDB3);//setting PB3 as an input
    PORTB |= (1<< PORTB3);   


    PCICR |= (1<<PCIE0);//enabling pins 7-0 to be detected
    PCMSK0 |= (1<<PCINT3);//enabling interupts from PB3 to be detected
    
 
   
}