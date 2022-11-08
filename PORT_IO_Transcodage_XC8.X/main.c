#include <stdio.h>
#include <stdlib.h>
//#include <pic18f45k22.h>
#include <config.h>         // Copy config.h to C:\Program Files (x86)\Microchip\xc8\v2.00\pic\include
#include <xc.h>

#define _XTAL_FREQ  8000000

            
const unsigned char Tab_7segments[10] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 
                                         0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
unsigned char X, Y;


void InitPORTS(void) {
    ANSELA = 0x00;      		// PORTA en mode numérique
    LATA = 0x00;
    PORTA = 0x00;
    TRISA = 0xFF;          		// Tout le PORTA en entrée
    
    ANSELD = 0x00;       		// PORTD en mode numérique
    LATD = 0x00;
    PORTD = 0x00;
    TRISD = 0x00;         		// Tout le PORTD en sortie
}

void main(void) {
    InitPORTS();
    while(1) {
       X = PORTA & 0b00001111;
 	  if (X <= 9) {
       	Y = Tab_7segments[X];	// Transcodage(X) ? Y
       	LATD = Y;
	  };
    };
}


