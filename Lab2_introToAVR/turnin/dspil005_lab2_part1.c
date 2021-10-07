/*	Author: Daimon Spilker
 *      Partner(s) Name: none
 *	Discussion Section: 022
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: Garage open at night-- A garage door sensor connects to PA0 (1 means door open), and a light sensor connects to PA1 (1 means light is sensed). Write a program that illuminates an LED connected to PB0 (1 means illuminate) if the garage door is open at night. PA0 = garage door sensor (input), PA1 = light sensor (input), PB0 = LED (output).
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
	PORTB = 0x00;

	unsigned char tempB = 0x00;
	unsigned char tempA = 0x00;

	while(1){
		tempA = PINA & 0x01;
		tempB = PINB & 0x02;
		
		if ((tempA == 0x01) && (tempB == 0x00)){ 
			tempB = 0x01; 
		} else{
			tempB = 0x00; 
		}	
		
		PORTB = tempB;	
	}

	return 1;
}

