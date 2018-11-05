#include "adc.h"
#include "timer.h"
//#include <avr/io.h>


void initADC()
{
    //set voltage reference and right shift
    ADMUX |= (1 << REFS0);

    //Right Adjust
    ADMUX &= ~(1 << ADLAR);

    //set free running
    //ADCSRB &= ~(1 << ADTS2 | 1<<ADTS1 | 1 << ADTS0);

    //set compare match B
    
    ADCSRB |= (1 << ADTS0); 
    ADCSRB &= ~(1 << ADTS1);
    ADCSRB |= (1<<ADTS2);

    //set Timer0 compare match A
    //ADCSRB |= (1<<ADTS1) | (1 << ADTS0); 
    
    //Enable Interupts
    ADCSRA |= (1 << ADIE);

    //turn on ADC 
    ADCSRA |= (1 << ADEN);

    // disable digital input
    DIDR0 |= (1 << ADC2D) | (1 << ADC1D) | (1 << ADC0D);

    //start conversion prescalar 128
    ADCSRA |= (1 << ADSC) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}