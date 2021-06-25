/*	Author: Mark Vincent
 *  Partner(s) Name: 
 *	Lab Section: A01
 *	Assignment: Lab #2  Exercise #4
 *	Exercise Description: We have a boat with 3 sensors on Ports A, B and C,
 *	each measuring weight from 0 to 255 kg. Port D will handle our output, with
 *	PD0 being 1 if the total weight is > 140kg, PD1 being 1 if the difference
 *	between weight values A and C > 80kg, with PD7 - PD2 representing an
 *	approximation of the total weight on the boat.
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
   	// Ports
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTC = 0xFF; // Configure port B's 8 pins as inputs
   	DDRC = 0x00; PORTA = 0xFF; // Configure port C's 8 pins as inputs
	DDRD = 0xFF; PORTC = 0x00; // Configure port D's 8 pins as outputs

    // Variables
    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    unsigned char tmpC = 0x00;
    unsigned char tmpD = 0x00;

    unsigned short totalWeight = 0x0000;
    unsigned char  weightDiff  = 0x00;
    unsigned char  totalWeightMask = 0x00;

    /* Insert your solution below */
    while (1) {
        // Reads inputs
        tmpA = PINA & 0xFF;
        tmpB = PINB & 0xFF;
        tmpC = PINC & 0xFF;

        // Calculates totalWeight
        totalWeight = tmpA + tmpB + tmpC;

        // Checks if totalWeight is > 140kg
        if (totalWeight > 0x008C) {
            // sets PD0 to 1.
            tmpD = tmpD | 0x0001;
        } else {
            // sets PD0 to 0.
            tmpD = tmpD & 0xFFFE;
        }

        // Calculates weightDiff
        if (tmpA > tmpC) {
            weightDiff = tmpA - tmpC;
        } else if (tmpA < tmpC) {
            weightDiff = tmpC - tmpA;
        } else {
            // Must be 0
            weightDiff = 0x00;
        }
        
        // Checks if weightDiff is > 80kg
        if (weightDiff > 80) {
            // Sets PD1 to 1.
            tmpD = tmpD | 0x02;
        } else {
            // Sets PD1 to 0.
            tmpD = tmpD & 0xFD;
        }
        
        // Sets PD7 - PD2 to a rounded version of the total weight, maintaining
        // the values of PD1 and PD0 from the previous steps above.
        totalWeightMask = (totalWeight >> 2) & 0xFC;
        tmpD = totalWeightMask | tmpD;

        // Writes tmpD to PORTD
        PORTD = tmpD;

        // Resets tmpD to 0x00
        tmpD = 0x00;
    }

    return 1;
}
