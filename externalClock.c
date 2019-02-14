#include <avr/io.h>

int main(void){
	
	DDRB=0xFF;
	
	
	while(1){
		TCNT0=0; //initial value of timer0 for a toggle every 70us
		TCCR0B=0x05;  //timer0 mode is normal, prescaler 1/8
		while((TIFR0 &(1<<TOV0))==0); //wait till TOV0=1
		TCCR0B=0;   //Turn off timer0
		TIFR0=0x1; //clear TOV0
		
		PORTB++;
		
		
		
	}
}
