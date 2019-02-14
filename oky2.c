#define F_CPU    1000000L
#include <avr/io.h>
#include <avr/delay.h>

int main(void){
     DDRC = 0x01;
     PORTC = 0;
       


     while(1){
PORTC=0x6D;
_delay_ms(1000);
PORTC=0;
_delay_ms(1000);



               }
}
