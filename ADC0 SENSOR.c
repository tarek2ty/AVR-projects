//this reads an analog temperature from a sensor LM34
//and turns it into digital (ADC0)

// (1) LM34 is connected to ADC0
// (2) 10-bit output is devided by 4 to get real temperature.
// (3) to divide by 4, we choose left justified and red ADCH only.

#define "avr/io.h"

int main(void){
	DDRB=0xFF;
	DDRC=0;
	ADCSRA=0x87;
	ADMUX=0xE0; // 	Vref=2.56V, ADC0 singl-ended, left justified
	
	while(1){
		ADCSRA |= (1<<ADSC);
		while((ADCSRA &(ADIF))==0);
		PORTB=ADCH;
	}
}