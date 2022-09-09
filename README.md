# Bits Field for Atmega328p with *avr-gcc*

El siguiente repositorio muestra una de las formas para manipular los
GPIO del microcontrolador *ATMEGA328p* facilmente, como si estuviesemos usando el compilador XC8 de la familia **pic's**

## Como usarlo

1. Entras a la carpeta *src* y seleccionas el archivo 
*DEF_ATMEGA328.h*.

2. Presionas el boton *Raw* y lo guardas con la extensión .h

3. Mueves el archivo a tu carpeta donde este el archivo *main.c*

4. En el archivo main.c lo incluyes con  `#include "DEF_ATMEGA328P.h"`


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

Tambien puedes ver el video en [Youtube](https://www.youtube.com/watch?v=cz7zLhab1U4&t=162s)
