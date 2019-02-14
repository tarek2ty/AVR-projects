#include "avr/io.h"
#include "avr/interrupt.h"

int main(void){
	DDRC=0x04; 
	PORTD=0x02;      //Pull-up
	GICR=(1<<INT0); //Enable external interrupt INT0
	sei();         //Enable interrupts
	
	while(1){
		
	}
}
ISR(INT0_vect){
	PORTC ^= 0x04;
}
