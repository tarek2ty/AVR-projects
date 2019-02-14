#define "avr/io.h"
// this receives a letter and if the letter is small, it sends is back capital.

 int main(){
	 UCSRB = (1<<RXEN);
	 UCSRC = 0x06; //asynchronous mode, 8-bit character, no parity, one stop bit 
	 UBRR = 0x33; //baud-rate=9600 for XTAL=8MHz
	 unsigned char ch;
	 while(1){
		 while(!(UCSRA & (1<<RXC)));
		 ch = UDR;
		 if ((ch>='a') && (ch<='z')){
			 ch += ('A'-'a');
			 while (!(UCSRA & (1<<UDRE)));
			 UDR=ch; 
		 }
		 return 0;
	 }
 }