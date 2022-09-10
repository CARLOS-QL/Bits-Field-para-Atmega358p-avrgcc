# Bits Field for ATMEGA328p with *AVR-GCC*

El siguiente repositorio muestra una de las formas para manipular los
GPIO del microcontrolador *ATMEGA328p* en *AVR-GCC* facilmente, como si estuviesemos usando el compilador XC8 de la familia **pic's**

## Como Utilizar la librería

1. Pegar la librería *DEF_ATMEGA328.h* donde este el archivo *main.c*

2. Incluir la librería en el archivo main.c con  `#include "DEF_ATMEGA328P.h"`


## Ejemplo
```c
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
```

Video con la expliación en [Youtube](https://www.youtube.com/watch?v=cz7zLhab1U4&t=162s)

