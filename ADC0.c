#include "avr/io.h"

int main (void){
	DDRC=0;      // C output
	DDRB=0xFF;
	DDRD=0xFF;
	ADCSRA=0x87;   //ADC enable and clk/128
	ADMUX=0xC0;   //Vref=2.56v, ADC0 single ended input
	
	while(1){
		ADCSRA=(1<<ADSC); //stare conversion
		while((ADCSRA&(1<<ADIF))==0); //wait for ADIF to rise; conversion finish
		PORTD=ADCLL;
		PORTB=ADCH;
	}
	return 0;
}