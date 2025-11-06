#ifndef HARDWARE_CONFIG_H
#define HARDWARE_CONFIG_H

// ====================
// 20x4 LCD Display (I2C)
// ====================
#define LCD_ADDRESS 0x27
#define LCD_COLUMNS 20
#define LCD_ROWS 4

// ====================
// 4-Digit 7-Segment Display
// ====================
// Display Module 1 MM.DD - (Digital Pins)
#define D1_DIO_PIN   11
#define D1_RCLK_PIN  12
#define D1_SCLK_PIN  13

// Display Module 2 YYYY - (Analog Pins)
#define D2_DIO_PIN   A0
#define D2_RCLK_PIN  A1
#define D2_SCLK_PIN  A2

// ====================
// 4x3 Matrix Membrane Keypad
// ====================
#define KEYPAD_R1_PIN 4
#define KEYPAD_R2_PIN 5
#define KEYPAD_R3_PIN 6
#define KEYPAD_R4_PIN 7

#define KEYPAD_C1_PIN 8
#define KEYPAD_C2_PIN 9
#define KEYPAD_C3_PIN 10

#define KEYPAD_COL_COUNT 3
#define KEYPAD_ROW_COUNT 4

// ====================
// Piezo Buzzer
// ====================
#define BUZZER_PIN 3

// ====================
// General System Configuration
// ====================
#define SERIAL_BAUD_RATE 9600

#endif // HARDWARE_CONFIG_H