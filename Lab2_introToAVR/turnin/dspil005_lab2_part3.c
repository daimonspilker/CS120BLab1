/*	Author: Daimon Spilker
 *      Partner(s) Name: none
 *	Discussion Section: 022
 *	Assignment: Lab #2  Exercise #3
 *	Exercise Description: Port A's pins 3 to 0, each connect to a parking space sensor, 1 meaning a car is parked in the space, of a four-space parking lot. Write a program that outputs in binary on port C the number of available spaces (Hint: declare a variable "unsigned char cntavail;" you can assign a number to a port as follows: PORTC = cntavail;).
 *	NEW! Extend the previous program to still write the available spaces number, but only to PC3..PC0, and to set PC7 to 1 if the lot is full.
 *
 *	I acknowledge all content contained herein, excluding template or example code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include <simAVRHeader.h>
#endif	

int main(void){
	DDRA = 0x00; 
	DDRB = 0xFF;  
	PORTA = 0xFF;
	PORTC = 0x00;

        unsigned char tempD = 0x00;
        unsigned char tempC = 0x00;
	unsigned char tempB = 0x00;
	unsigned char tempA = 0x00;
	unsigned char cntavail = 0x00;

	while(1){
		tempA = PINA & 0x01;
		tempB = PINB & 0x02;
		tempB = tempB >> 1;
		tempC = PINC & 0x04;
		tempC = tempC >> 2;
		tempD = PIND & 0x08;
		tempD = tempD >> 3;
		
		cntavail = tempA + tempB + tempC + tempD;

		if (cntavail == 0x00){ 
			PORTC = 0x80 | cntavail; 
		} else{
			PORTC = cntavail; 
		}	
		
	}

	return 0;
}

