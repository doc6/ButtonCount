/*
 * ButtonCount.c
 *
 *	Reads two push buttons as inputs
 *	one to count up in binary which is
 *	displayed in binary on leds, and
 *	the other to reset the counting
 *	back to 0.
 *
 *  Created on: 27/07/2016
 *      Author: doc2
 */
#include <avr/io.h>
#include <util/delay.h>


/*
 * delay_ms(delay_in_ms)
 *
 * Delay the specified number of milliseconds.
 *
 * _delay_ms uses a floating point datatype if you call
 * that function in many places in your code then it becomes
 * very fat. An integer is enough for us.
 *
 */
void delay_ms(unsigned int xms)
{
	while (xms) {
		_delay_ms(0.96);
		xms--;
	}
}


/*
 * init_ports()
 *
 * Initialise the ports to be used
 */
void init_ports(void)
{
	/* Make bits 0 and 1 of PORTB inputs and bits 2 to 6 outputs*/
	DDRB = 0x3C & 0x03F;
	PORTB = 0;
}



/*
 * illuminate_leds(leds)
 *
 * Illuminate the six LEDs connected to bits 0 to 6
 * of Port B according to input leds.
 */
void illuminate_leds(int leds)
{
	leds = leds << 2;
	PORTB = leds & 0x3C;
}


int main(void)
{

	 int count;
	/* Initialise I/O Ports for use. */
	init_ports();

	// reset count to 0.
	void reset(void)
	{
		count = 0;
	}

	reset();


	/* Do forever... */
	/* Shifts two bits of the DDRB register to the left
	 *  to put the inputs from the buttons into
	 *  the output port location and illuminates the leds accordingly.
	 */
	while (1)
	{
		//reset button
		if((PINB & 0x3) == 0x2)		// button 1 press
		{
			reset();
		}


		if((PINB & 0x3) == 0x1)	// button 2 press
		{
				if(count < 0x3F)	// increment counting and reset when all leds are lit
				{
					count += 1;		// increment
				}
				else
				{
					reset();		// reset count to 0
				}

			while((PINB & 0x3) == 0x1 || (PINB & 0x3) == 0x0)	// wait until switch released.
			{
				delay_ms(25);			// delay to account for switch bounce
			}
		}

		illuminate_leds(count);
	}

	/* Cannot get here */
	return 0;
}



