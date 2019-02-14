#define "avr/io.h"

 int main(){
	 DDRB=0xFF;
	 usart_init();
	 while(1){
		 while(!(UCSRA&(1<<RXC)); //make sure UDR is FULL by monitoring RXC. If RXC=1, CONTINUE.
		 PORTB=UDR;
		 return 0;
	 }
 }
 
 void usart_init (void){ //initialize USART
	 UCSRB = (1<<RXEN); //=0x10; for Rx
	 UCSRC = (1<<UCZ1) | (1<<UCZ0) | (1<<URSEL); // =0x06; asynchronous mode, 8-bit character, no parity, one stop bit 
	 UBRR = 0x33; //baud-rate=9600 for XTAL=8MHz
 }
 
