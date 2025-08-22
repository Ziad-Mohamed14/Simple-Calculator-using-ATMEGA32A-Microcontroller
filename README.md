
# AVR Simple Calculator (LCD + Keypad)

This project implements a simple calculator system on an AVR microcontroller, integrating a 16x2 LCD for display and a 4x4 matrix keypad for input. The calculator supports basic arithmetic operations such as addition, subtraction, multiplication, and division, with real-time input handling and result display.

The system demonstrates embedded C programming with modular header files for LCD and Keypad interfacing, showcasing structured design for small-scale embedded applications.

## Features

Core functionalities of the Simple Calculator:
- LCD Display Support
  - Character and string display
  - Integer and floating-point number display
  - Cursor control and line management
  - Clear screen functionality
- Keypad Input Handling
  - 4x4 matrix keypad scanning with debounce
  - Support for multi-digit numbers
  - Detection of arithmetic operators (`+`, `-`, `*`, `/`)
  - `=` key to confirm input and compute result
- Arithmetic Operations
  - Addition, subtraction, multiplication, and division
  - Floating-point result display with two decimal precision
  - Division-by-zero error handling


## Getting Started

To compile and run this project on an AVR microcontroller (e.g., ATmega16/32), ensure you have:
  - AVR Toolchain (AVR-GCC, AVRDUDE)
  - Atmel Studio or VS Code with PlatformIO / Makefile setup
  - Proteus / SimulIDE (optional, for simulation)
  - A microcontroller board and supporting hardware:
    - 16x2 LCD (HD44780 compatible)
    - 4x4 Keypad
    - AVR MCU (ATmega16/32 recommended)

**1. Simulation (Optional)**

If testing in Proteus:
  - Connect the LCD data pins to `PORTD`.
  - Connect control pins (`RS → PC0`, `RW → PC1`, `E → PC2`).
  - Connect keypad rows/columns to `PORTA`.
  - Load the compiled `.hex` file into the ATmega32 model.

## User Flow

- Enter First Number → Press digits on keypad → Press `=` to confirm.
- Enter Operation → Press operator (`+`, `-`, `*`, `/`).
- Enter Second Number → Press digits → Press `=` to confirm.
- Result Display → LCD shows computed result.
- If invalid operator → `"Invalid Op"` is shown.
- If division by zero → `"Error: Div 0"` is shown.

## Design Files

- `LCD.h`: LCD driver (initialization, command/data handling, string/number/float display).
- `Keypad.h`: 4x4 keypad driver (scanning, debounce, key return).
- `main.c`: Main program integrating LCD and keypad for calculator operations.

## Block Diagram

![AVR Simple Calculator (LCD + Keypad)]([https://github.com/Ziad-Mohamed14/Simple-Calculator-using-ATMEGA32A-Microcontroller/blob/main/Simple_Calculator.png])

This diagram reflects the high-level system connection of the AVR microcontroller with the LCD (for output) and Keypad (for input), showing data/control signals mapped to `PORTC`, `PORTD`, and `PORTA`.

