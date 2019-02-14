#define F_CPU    1000000L
#include <avr/io.h>
#include <avr/delay.h>


int main(void){
     DDRB = 0x01;
     PORTB = 0x02;
       


     while(1){
if (!(PINB & 0x02)){
PORTB |= 0x01;

}
else{
PORTB &= 0xFE;
}


               }
}





