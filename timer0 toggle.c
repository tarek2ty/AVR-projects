#include <avr/io.h>

int main(void){
	
	DDRB=0x01;
	
	
	while(1){
		TCNT0=186; //initial value of timer0 for a toggle every 70us
		TCCR0=2;  //timer0 mode is normal, prescaler 1/8
		while((TIFR &(1<<TOV0))==0); //wait till TOV0=1
		TCCR0=0;   //Turn off timer0
		TIFR=0x1; //clear TOV0
		
		PORTB=PORTB ^ 0x01; //toggle PB0
		
		
		
	}
}