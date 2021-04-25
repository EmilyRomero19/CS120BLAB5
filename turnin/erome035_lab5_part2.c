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

enum SM1_STATES { SM1_SMStart, SM1_INIT1, SM1_T1, SM1_T2, SM1_T3, SM1_T4, SM1_RESET } SM1_STATE;
unsigned char hold = 0;
void Tick_Reset(){
	
	unsigned char button = 0x00;
	button = ~PINA & 0x01; // button is connected to A0
	
	switch(SM1_STATE){
			
	case SM1_SMStart:
		SM1_STATE = SM1_INIT1;
		break;
			
	case SM1_INIT1:
		if(button == 0x01){
			SM1_STATE = SM1_T2;
			hold = 1;
		}
		else if(button == 0x02){
			SM1_STATE = SM1_T4;
			hold = 1;
		}
		else if(button == 0x03){
			SM1_STATE = SM1_RESET;
		}
		else{
			SM1_STATE = SM1_INIT1;
		}
		break;
			
	case SM1_T2:
		if(button == 0x01){
			SM1_STATE = SM1_T2;
		}
		else if(button == 0x02 || button == 0x03){
			SM1_STATE = SM1_RESET;
		}
		else{
			SM1_STATE = SM1_T3;
		}
		break;
			
	case SM1_T3:
		if(button == 0x01){
			SM1_STATE = SM1_T2;
			hold = 1;
		}
		else if(button == 0x02){
			SM1_STATE = SM1_T4;
			hold = 1;
		}
		else if(button == 0x03){
			SM1_STATE = SM1_RESET;
		}
		else{
			SM1_STATE = SM1_T3;	
		}
		break;
			
	case SM1_T1:
		if(button == 0x01){
			SM1_STATE = SM1_T2;
			hold = 1;
		}
		else if(button == 0x02){
			SM1_STATE = SM1_T4;
			hold = 1;
		}
		else if(button == 0x03){
			SM1_STATE = SM1_RESET;
		}
		else{
			SM1_STATE = SM1_T1;	
		}
		break;
		
	case SM1_T4:
		if(button == 0x01 || button == 0x03){
			SM1_STATE = SM1_RESET;
		}
		else if(button == 0x02){
			SM1_STATE = SM1_T4;
		}
		else{
			SM1_STATE = SM1_T1;	
		}
		break;
	
	case SM1_RESET:	
		if(button == 0x01){
			SM1_STATE = SM1_T2;
			hold = 1;
		}
		else if(button == 0x02){
			SM1_STATE = SM1_T4;
			hold = 1;
		}
		else{
			SM1_STATE = SM1_RESET;	
		}
		break;	
			
	 default:
		SM1_STATE = SM1_SMStart;
		
        }
	
	switch(SM1_STATE){
			
	case SM1_SMStart:
	break;
	
	case SM1_INIT1:
	PORTC = 0x07;
	break;
			
	case SM1_T2:
	if (PINC < 9 && hold == 1){
	PORTC = PORTC + 1;
	hold = 0;
	}
	break;
			
	case SM1_T3:
	break;
	
	case SM1_T1:
	break;
		
	case SM1_T4:
	if (PINC > 0 && hold == 1){
	PORTC = PORTC - 1;
	hold = 0;
	}
	break;
			
	dafault:
	break;
			
	}
}

int main(void) {
    /* Insert DDR and PORT initializations */

	DDRA = 0x00; PORTA = 0xFF; //inputs
	DDRB = 0xFF; PORTB = 0x00; //outputs
	
    /* Insert your solution below */
    while (1) {
	Tick_Reset();
    }
    return 1;
}
