#include <avr/io.h>
#include <avr/interrupt.h>

int timev=0;

int main (void){
	
	
	while(1){
		DDRB=0X01;
		TCCR0A=(1<<WGM01);
		sei();
		TIMSK0=(1<<OCIE0A);
		TCCR0B=(1<<CS02)|(1<<CS00);
	}
}
ISR(TIMER0_COMPA_vect){
	timev++;
	if(timev>100){
		PORTB ^=(1<<PORTB0);
		timev=0;
	}
}
