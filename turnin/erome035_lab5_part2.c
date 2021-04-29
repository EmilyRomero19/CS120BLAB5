/*	Author: erome035
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum SM1_STATES {SM1_Start, SM1_Begin, SM1_Init, SM1_Inc, SM1_Dec, SM1_Reset} SM1_STATE;

void Tick_Inc_Dec_Reset(){
	
	unsigned char button1 = 0x00;
	unsigned char button2 = 0x00;
	
	button1 = ~PINA & 0x01; // button1 is connected to PA0
	button2 = ~PINA & 0x02; // button2 is connected to PA1
	
	switch(SM1_STATE){
	
	case SM1_Start:
	SM1_STATE = SM1_Begin;
	break;
	
	case SM1_Begin:
	SM1_STATE = SM1_Init;
	break;		
			
	case SM1_Init:
	if(button1 && !button2){
	SM1_STATE = SM1_Inc;
	}
	else if(!button1 && button2){
	SM1_STATE = SM1_Dec;
	}
	else if(button1 && button2){
	SM1_STATE = SM1_Reset;	
	}
	else{
	SM1_STATE = SM1_Init;
	}
	break;
			
	case SM1_Inc:
	if(button1 && !button2){
	SM1_STATE = SM1_Inc;
	}
	else{
	SM1_STATE = SM1_Init;
	}
	break;
			
	case SM1_Dec:
	if(!button1 && button2){
	SM1_STATE = SM1_Dec;
	}
	else{
	SM1_STATE = SM1_Init;
	}
	break; 
		
	case SM1_Reset:
	else if(button1 && button2){
	SM1_STATE = SM1_Reset;
	}
	else{
	SM1_STATE = SM1_Init;
	}
	break;
			
	default:
	SM1_STATE = SM1_Start;
	break;
	}
	
	switch(SM1_STATE){
			
	case SM1_Start: 
	break;
			
	case SM1_Begin:
	PORTC = 0x07;
	break;
		
	case SM1_Init:
	PORTC = PORTC;
	break;
			
	case SM1_Inc:
	if (PORTC < 0x09){
	PORTC = PORTC + 1;
	}
	break;
				
	case SM1_Dec:
	if (PORTC > 0x00){
	PORTC = PORTC - 1;
	}
	break;
			
	case SM1_Reset:
	PORTC = 0x00;
	break;
			
	default:
	PORTC = 0x07;
	break;
					
	}
			
}	

int main(void) {
    /* Insert DDR and PORT initializations */

	DDRA = 0x00; PORTA = 0xFF; //inputs
	DDRB = 0xFF; PORTB = 0x00; //outputs
	
    /* Insert your solution below */
    while (1) {
	Tick_Inc_Dec_Reset();
    }
    return 1;
}
