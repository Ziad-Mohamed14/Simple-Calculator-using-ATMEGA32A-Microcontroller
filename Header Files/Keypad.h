/*
 * Keypad.h
 *
 * Created: 8/12/2024 12:39:34 PM
 *  Author: Ziad Mohamed
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>        // Include AVR input/output library for I/O operations
#include <util/delay.h>    // Include delay utility for timing functions

// Define the port, pin, and data direction register for the keypad
#define KEYPAD_PORT     PORTA
#define KEYPAD_PIN      PINA
#define KEYPAD_DDR      DDRA

// Define masks for rows and columns of the keypad
#define KEYPAD_ROW_MASK 0x0F    // Mask for rows (lower 4 bits)
#define KEYPAD_COL_MASK 0xF0    // Mask for columns (upper 4 bits)

// Define the keypad layout in a 4x4 matrix (This array is not consistent)
char keypad[4][4] = {
	{'1', '2', '3', '/'},
	{'4', '5', '6', '*'},
	{'7', '8', '9', '-'},
	{'*', '0', '=', '+'}
};

// Function to read the pressed key on the keypad
char readKeypad()
{
	while(1)
	{
		for (int col = 0; col < 4; col++)
		{
			KEYPAD_DDR = KEYPAD_COL_MASK;
			KEYPAD_PORT = ~(1 << (col + 4));
			
			for (int row = 0; row < 4; row++)
			{
				if (!(KEYPAD_PIN & (1 << row)))
				{
					_delay_ms(50); // Simple debounce delay
					while (!(KEYPAD_PIN & (1 << row))); // Wait until the key is released
					_delay_ms(50);  // Additional debounce delay
					return keypad[row][col];
				}
			}
		}
	}
	return 0;
}

//Function to scan the keypad and return the pressed key
char keypad_scan()
{
	char key = readKeypad();  // Read the pressed key
	if (key != 0)
	{
		// Display the pressed key on the LCD (assuming LCD_DISPLAY_CHAR is defined elsewhere)
		LCD_DISPLAY_CHAR(key);
		_delay_ms(2);
	}
	
	return key;  // Return the pressed key
}
#endif /* KEYPAD_H_ */
