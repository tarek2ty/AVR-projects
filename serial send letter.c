#define "avr/io.h"

 int main(){
	 usart_init();
	 while(1){
		 usart_send('G');
		 return 0;
	 }
 }
 
 void usart_init (void){ //initialize USART
	 UCSRB = (1<<TXEN); // =0x08; enable USART transmitter Tx... =0x10; for Rx
	 UCSRC = (1<<UCZ1) | (1<<UCZ0) | (1<<URSEL); // =0x06; asynchronous mode, 8-bit character, no parity, one stop bit 
	 UBRR = 0x33; //baud-rate=9600 for XTAL=8MHz
 }
 
 void usart_send (unsigned char x){ //send x
	 while(!(UCSRA&(1<<UDRE)); //make sure UDR is empty by monitoring UDRE. If UDRE=1, CONTINUE.
	 UDR=x; //fill UDR register with x
 }