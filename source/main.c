/*	Author: Mark Vincent II
 *  Partner(s) Name: NA
 *	Lab Section: A01
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: In this exercise we need to setup a garage door system based on the truth table provided in the lab manual.
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; // Configure port A's 8 pins as inputs
	PORTA = 0xFF;
    
	DDRB = 0xFF; // Configure port B's 8 pins as outputs
    PORTB = 0x00; // Initialize PORTB output to 0’s    

	unsigned char tmpA = 0x00; // Temporary varible to hold value of A
	unsigned char tmpB = 0x00; // Temporary varible to hold value of B

	/* Insert your solution below */
    while (1) {
    	tmpA = PINA & 0x03; // Masks input pins, A1 A0 into tmpA.

		// Begins checking tmpA to compute logic
		if (tmpA == 0x00) {
			// B0 should be 0
			tmpB = (tmpB & 0xFE) | 0x00; // does a mask of B besides B0, than sets B0 to 0. bbbb bbb0
		} else if (tmpA == 0x01) {
			// B0 should be 1
			tmpB = (tmpB & 0xFE) | 0x01; // does a mask of B besides B0, than sets B0 to 1. bbbb bbb1
		} else if (tmpA == 0x2) {
			// B0 should be 0
			tmpB = (tmpB & 0xFE) | 0x00; // does a mask of B besides B0, than sets B0 to 0. bbbb bbb0
		} else if (tmpA == 0x3) {
			// B0 should be 0
			tmpB = (tmpB & 0xFE) | 0x00; // does a mask of B besides B0, than sets B0 to 0. bbbb bbb0
		} else {
			// Some other input value not regonized, ignored.
		}

		// writes B
		PORTB = tmpB;
	}
 
	return 0;
}
