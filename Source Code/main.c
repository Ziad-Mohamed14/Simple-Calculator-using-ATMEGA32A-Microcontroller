/*
 * Simple Calculator.c
 *
 * Created: 8/12/2024 12:38:05 PM
 * Author : Ziad Mohamed
 */ 

#include <avr/io.h>
#include "LCD.h"
#include "Keypad.h"
#define F_CPU 1000000UL

int main(void)
{
	LCD_init();
	LCD_clear(); // Clear the LCD
	
	// Initialize the operands, operation, and key
	int firstOperand = 0;
	int secondOperand = 0;
	U8 operation;
	U8 key;
	
	while(1)
	{
		LCD_clear();
		LCD_display_string("Enter 1st No:");
		LCD_second_line(); // Move the cursor to the second line
		_delay_ms(500);
		
		firstOperand = 0;
		while(1)
		{
			key = keypad_scan(); // Scan for the first operand
			if(key >= '0' && key <= '9') // Check if it is a digit
			{
				firstOperand = (firstOperand * 10) + (key - '0'); // Multi-digit number
			}
			else if (key == '=') // If '=' is pressed, move to the next step without displaying it
			{
				break; // Exit the loop after completing the first operand
			}
		}

		LCD_clear();
		
		LCD_display_string("Enter Op:");
		LCD_second_line();
		_delay_ms(500);
		
		while(1)
		{
			key = keypad_scan();
			operation = key;  // Store the operation
			_delay_ms(500);
			break; // Exit the loop after storing the operation
		}
		
		LCD_clear();
		LCD_display_string("Enter 2nd No:");
		LCD_second_line();
		_delay_ms(500);
		
		secondOperand = 0;
		while(1)
		{
			key = keypad_scan();
			if(key >= '0' && key <= '9')
			{
				secondOperand = (secondOperand * 10) + (key - '0');
			}
			else if (key == '=') // If '=' is pressed, move to the next step without displaying it
			{
				break; // Exit the loop after completing the first operand
			}
		}
		
		float result = 0.0;
		switch(operation)
		{
			case '+':
			result = (float)firstOperand + (float)secondOperand;
			break;
			
			case '-':
			result = (float)firstOperand - (float)secondOperand;
			break;
			
			case '*':
			result = (float)firstOperand * (float)secondOperand;
			break;
			
			case '/':
			if(secondOperand != 0)
			{
				result = (float)firstOperand / (float)secondOperand;
			}
			else
			{
				LCD_clear();
				LCD_display_string("Error: Div 0");
				_delay_ms(1000);
				continue;
			}
			break;
			
			default:
			LCD_clear();
			LCD_display_string("Invalid Op");
			_delay_ms(1000);
			continue;
		}
		
		LCD_clear();
		LCD_display_string("Result: ");
		LCD_second_line();
		LCD_display_float(result); // Use floating-point display function
		_delay_ms(2000);
	}
}
