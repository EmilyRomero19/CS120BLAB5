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

enum SM1_STATES { SM1_SMStart, SM1_INIT1, SM1_ADD1, SM1_MINUS1, SM1_ADD, SM1_MINUS, SM1_RESET } SM1_STATE;
void Tick_Reset() {	

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
