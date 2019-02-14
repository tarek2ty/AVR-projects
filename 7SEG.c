#include <avr/io.h>
#include <avr/delay.h>
#define F_CPU 1000000L

int main(void){
	DDRB=0xFF;
	PORTB=0;
	
	while(1){
		PORTB=0x3F;
		_delay_ms(1000);
		PORTB=0x06;
		_delay_ms(1000);
		PORTB=0x5B;
		_delay_ms(1000);
		PORTB=0x4F;
		_delay_ms(1000);
		PORTB=0x66;
		_delay_ms(1000);
		PORTB=0x6D;
		_delay_ms(1000);
		PORTB=0x7D;
		_delay_ms(1000);
		PORTB=0x70;
		_delay_ms(1000);
		PORTB=0x7F;
		_delay_ms(1000);
		PORTB=0x6F;
		_delay_ms(1000);
	}
}
