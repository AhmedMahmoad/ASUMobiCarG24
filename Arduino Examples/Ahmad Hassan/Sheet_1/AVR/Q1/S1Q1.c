#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/delay.h>

int main(void){

	DDRA = 0b00000001;
	while(1){
		PORTA = 0b00000001;
		_delay_ms(500);
		PORTA = 0b00000000;
		_delay_ms(1500);
	}
	return 0;
}
