/*
 * CAMPOS_BITS.c
 *
 * Created: 23/10/2019 10:23:55
 * Author : carlo
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "DEF_ATMEGA328P.h"

int main(void)
{
	DDRCbits.DDRC0 = 1;
	DDRBbits.DDRB5 = 1;
	DDRDbits.DDRD3 = 1;
	
	PORTCbits.PC0_ = 0;
	PORTBbits.PB5_ = 0;		//Inicia en bajo
	PORTDbits.PD3_ = 0;
	
    /* Replace with your application code */
    while (1) 
    {
		PORTCbits.PC0_ = 1;
		_delay_ms(1000);
		PORTCbits.PC0_ = 0;
		PORTBbits.PB5_ = 1;
		_delay_ms(1000);
		PORTBbits.PB5_ = 0;
		PORTDbits.PD3_ = 1;
		_delay_ms(1000);
		PORTDbits.PD3_ = 0;	
    }
}

