*	Author: lab
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

enum SM1_STATES { SM1_SMStart,SM1_Begin, SM1_LED1, WAIT1, SM1_LED2, WAIT2, SM1_LED3, WAIT3, SM1_LED4,WAIT4, SM1_LED5, WAIT5, SM1_LED6, WAIT6,SM1_LED01,WAIT01, SM1_LED23, WAIT23, SM1_LED45, WAIT45} SM1_STATE;
void LED_Reset(){

        // unsigned char led = 0x00;
	unsigned char button = 0x00;

	button = ~PINA & 0x01; // button is connected to A0


	switch(SM1_STATE){

	case SM1_SMStart:
		SM1_STATE = SM1_Begin;
		break;

	case SM1_Begin:
		 if(button){
                    SM1_STATE = SM1_LED1;
                }
                else{
                    SM1_STATE = SM1_Begin;
                }
		break;

	case SM1_LED1:
                if(button){
                    SM1_STATE = SM1_LED1;
                }
                else{
                    SM1_STATE = WAIT1;
                }
		break;

	case WAIT1:
                if(button){
                    SM1_STATE = SM1_LED2;
                }
                else{
                    SM1_STATE = WAIT1;
                }
		break;

	case SM1_LED2:
                if(button){
                    SM1_STATE = SM1_LED2;
                }
                else{
                    SM1_STATE = WAIT2;
                }
                break;

        case WAIT2:
                if(button){
                    SM1_STATE = SM1_LED3;
                }
                else{
                    SM1_STATE = WAIT2;
                }
                break;

	case SM1_LED3:
                if(button){
                    SM1_STATE = SM1_LED3;
                }
                else{
                    SM1_STATE = WAIT3;
                }
                break;

        case WAIT3:
                if(button){
                    SM1_STATE = SM1_LED4;
                }
                else{
                    SM1_STATE = WAIT3;
                }
                break;

	case SM1_LED4:
                if(button){
                    SM1_STATE = SM1_LED4;
                }
                else{
                    SM1_STATE = WAIT4;
                }
                break;

        case WAIT4:
                if(button){
                    SM1_STATE = SM1_LED5;
                }
                else{
                    SM1_STATE = WAIT4;
                }
                break;

	case SM1_LED5:
                if(button){
                    SM1_STATE = SM1_LED5;
                }
                else{
                    SM1_STATE = WAIT5;
                }
                break;

        case WAIT5:
                if(button){
                    SM1_STATE = SM1_LED6;
                }
                else{
                    SM1_STATE = WAIT5;
                }
                break;

	case SM1_LED6:
                if(button){
                    SM1_STATE = SM1_LED6;
                }
                else{
                    SM1_STATE = WAIT6;
                }
                break;

        case WAIT6:
                if(button){
                    SM1_STATE = SM1_LED01;
                }
                else{
                    SM1_STATE = WAIT6;
                }
                break;

	case SM1_LED01:
                if(button){
                    SM1_STATE = SM1_LED01;
                }
                else{
                    SM1_STATE = WAIT01;
                }
                break;

        case WAIT01:
                if(button){
                    SM1_STATE = SM1_LED23;
                }
                else{
                    SM1_STATE = WAIT01;
                }
                break;

	case SM1_LED23:
                if(button){
                    SM1_STATE = SM1_LED23;
                }
                else{
                    SM1_STATE = WAIT23;
                }
                break;

	case WAIT23:
                if(button){
                    SM1_STATE = SM1_LED45;
                }
                else{
                    SM1_STATE = WAIT23;
                }
                break;

	case SM1_LED45:
                if(button){
                    SM1_STATE = SM1_LED45;
                }
                else{
                    SM1_STATE = WAIT45;
                }
                break;

        case WAIT45:
                if(button){
                    SM1_STATE = SM1_Begin;
                }
                else{
                    SM1_STATE = WAIT45;
                }
                break;


	default:
		SM1_STATE = SM1_SMStart;
		break;
 }

	switch(SM1_STATE){

	case SM1_SMStart:
	break;

	case SM1_Begin:
	PORTB = 0x00;
        break;

	case SM1_LED1:
	PORTB = 0x01;
	break;

	case WAIT1:
	break;

	case SM1_LED2:
        PORTB = 0x02;
        break;

	case WAIT2:
        break;

	case SM1_LED3:
	PORTB = 0x04;
	break;

	case WAIT3:
        break;

	case SM1_LED4:
	PORTB = 0x08;
	break;

	case WAIT4:
        break;

	case SM1_LED5:
	PORTB = 0x10;
	break;

	case WAIT5:
        break;

	case SM1_LED6:
	PORTB = 0x20;
	break;

	case WAIT6:
        break;

	case SM1_LED01:
        PORTB = 0x03;
        break;

	case WAIT01:
        break;

        case SM1_LED23:
        PORTB = 0x0C;
        break;

	case WAIT23:
        break;

        case SM1_LED45:
        PORTB = 0x30;
        break;

	case WAIT45:
        break;

	default:
	PORTB = 0x00;
	break;
}

}

int main(void) {
    /* Insert DDR and PORT initializations */
       	DDRA = 0x00; PORTA = 0xFF; //input
	DDRB = 0xFF; PORTB = 0x00; //output

    /* Insert your solution below */
    while (1) {

	LED_Reset();

    }
    return 1;
}
