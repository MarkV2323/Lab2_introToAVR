/*	Author: Mark Vincent
 *  Partner(s) Name: 
 *	Lab Section: A01
 *	Assignment: Lab #2  Exercise #3
 *	Exercise Description: For this exercise, we use pin A3 - A0 as parking
 *	checkers, and are suppose to output the number of available spaces on Port
 *  C. We need to extend that program from exercise #2 to also only write those
 *  open spaces to PC3 - PC0 and write 1 to PC7 if the lot is full.
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {

	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs,
                               // initialize to 0s.

    unsigned char tmpA0 = 0x00;     // Temp to hold A0 info.
    unsigned char tmpA1 = 0x00;     // Temp to hold A1 info.
    unsigned char tmpA2 = 0x00;     // Temp to hold A2 info.
    unsigned char tmpA3 = 0x00;     // Temp to hold A3 info.

    unsigned char cntavail = 0x04;  // The current amount of available spaces.

    /* Insert your solution below */
    while (1) {
        // Reads input from A, A3 - A0
        tmpA0 = PINA & 0x01;
        tmpA1 = PINA & 0x02;
        tmpA2 = PINA & 0x04;
        tmpA3 = PINA & 0x08;

        // Figures out remaining spaces
        if (tmpA0 == 0x01) {
            cntavail = cntavail - 1;
        }
        if (tmpA1 == 0x02) {
            cntavail = cntavail - 1;
        }
        if (tmpA2 == 0x04) {
            cntavail = cntavail - 1;
        }
        if (tmpA3 == 0x08) {
            cntavail = cntavail - 1;
        }
        
        // Checks if parking lot is full, if so, writes 1 to PC7.
        if (cntavail == 0) {
            cntavail = (cntavail & 0x0F) | 0x80;
        }

        // Writes cntavail to PORTC and resets it back to 0.
        PORTC = cntavail;
        cntavail = 0x04;
    }
    return 1;
}
