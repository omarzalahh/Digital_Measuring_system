/******************************************************************************
 *
 * File Name: main.c
 *
 * Description: Main application
 *
 * Author: Omar Salah
 *
 *******************************************************************************/

#include"std_types.h"
#include"lcd.h"
#include"Ultrasonic.h"
#include <avr/io.h> /* To use the SREG register */

int main()
{
	/*Variable to save distance in it*/
	uint16 distance;
	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);
	/*Enable LCD driver*/
	LCD_init();
	/*Enable Ultrasonic_driver*/
	Ultrasonic_init();
	while(1)
	{
		/*Enable Ultrasonic_driver*/
		Ultrasonic_init();
		/*
		 * move cursor to first location on lcd to print the message
		 */
		LCD_moveCursor(0,0);
		LCD_displayString("Distance= ");
		/*
		 * move cursor to print the distance
		 */
		LCD_moveCursor(0,10);
		/*
		 * read distance we want to display
		 */
		distance=Ultrasonic_readDistance();
		LCD_intgerToString(distance);
		LCD_displayString(" CM ");
	}


}
