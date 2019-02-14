#include <avr/io.h>
#include <avr/interrupt.h> //call ineterrupts


int main (void){
	
	DDRB=0x20;
	
	TCNT0=0;
	TCCR0=0x04;
	TIMSK=(1<<TOIE0);
	sei();      //Enable interrupts at this point
	
	DDRC=0;
	DDRD=0xFF;
	
	
	while(1){
		PORTD=PINC;
	}
}

ISR(TIMER0_OVF_vect){ //Vector.....ISR for timer0 overflow
	TCNT0=0;
	PORTB ^= 0x02;
}