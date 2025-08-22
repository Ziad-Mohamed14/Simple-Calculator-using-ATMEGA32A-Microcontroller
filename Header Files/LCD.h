/*
 * LCD.h
 *
 * Created: 8/12/2024 12:38:26 PM
 *  Author: Ziad Mohamed
 */ 


#ifndef LCD_H_
#define LCD_H_

#include <avr/delay.h>
#include <stdio.h>
#include <stdlib.h>

#define LCD_DATA_PORT PORTD
#define LCD_CTRL_PORT PORTC
#define RS_PIN PC0
#define RW_PIN PC1
#define E_PIN PC2

typedef unsigned char U8;

void LCD_command(U8 cmnd);
void LCD_data(U8 data);
void LCD_display_string(const U8 *str);
void LCD_DISPLAY_CHAR(const U8 *id);
void LCD_display_float(float num);
void LCD_display_number(int num);
void LCD_clear();
void LCD_second_line();

void LCD_init(){
	DDRD = 0xFF; //DATA PORT = OUTPUT
	DDRC |= (1<<RS_PIN) | (1<<RW_PIN) | (1<<E_PIN); //CONTROL PORT = OUTPUT
	_delay_ms(20); //LCD POWER ON DELAY
	
	LCD_command(0x38); //2 Lines, 5x7 Matrix
	LCD_command(0x0E); //Display ON, Cursor ON
	LCD_command(0x01); //Clear display
	_delay_ms(2);
}

void LCD_command(U8 cmnd){
	LCD_DATA_PORT = cmnd; //Send command to the data port
	LCD_CTRL_PORT &= ~(1<<RS_PIN); //RS = 0 for command
	LCD_CTRL_PORT &= ~(1<<RW_PIN); //RW = 0 for write
	LCD_CTRL_PORT |= (1<<E_PIN); //Enable High
	_delay_ms(1);
	
	LCD_CTRL_PORT &= ~(1<<E_PIN); //Enable Low
	_delay_ms(1);
}

void LCD_data(U8 data){
	LCD_DATA_PORT = data; //Send data to the data port
	LCD_CTRL_PORT |= (1<<RS_PIN); //RS = 1 for command
	LCD_CTRL_PORT &= ~(1<<RW_PIN); //RW = 0 for write
	LCD_CTRL_PORT |= (1<<E_PIN); //Enable High
	_delay_ms(1);
	
	LCD_CTRL_PORT &= ~(1<<E_PIN); //Enable Low
	_delay_ms(1);
}

void LCD_display_string(const U8 *str){
	for (U8 i = 0; str[i] != '\0'; i++){
		LCD_data(str[i]);
		_delay_ms(100);
	}
}

void LCD_DISPLAY_CHAR(const U8 *id){
	LCD_data(id);
}


void LCD_display_float(float num) {
	char buffer[16];
	dtostrf(num, 0, 2, buffer); // Convert float to string with specified width and precision
	buffer[15] = '\0'; // Ensure null-termination
	LCD_display_string((U8 *)buffer); // Display string on LCD
}



void LCD_display_number(int num){
	char buffer[16];
	itoa(num, buffer, 10); // Convert number to string
	LCD_display_string((U8 *)buffer); // Display string representation of number
}

void LCD_clear(){
	LCD_command(0x01);
	_delay_ms(2);
}

void LCD_second_line(){
	LCD_command(0xC0);
	_delay_ms(2);
}

#endif /* LCD_H_ */
