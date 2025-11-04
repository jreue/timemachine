#ifndef CONFIG_H
#define CONFIG_H

/**
 * Timemachine Project Configuration
 * All pin assignments and constants in one place
 */

// ====================
// LCD Configuration
// ====================
#define LCD_ADDRESS 0x27
#define LCD_COLUMNS 20
#define LCD_ROWS 4

// ====================
// 7-Segment Display Pins
// ====================
// Display Module 1 - Digital Pins
#define D1_DIO_PIN   11
#define D1_RCLK_PIN  12
#define D1_SCLK_PIN  13

// Display Module 2 - Analog Pins
#define D2_DIO_PIN   A0
#define D2_RCLK_PIN  A1
#define D2_SCLK_PIN  A2

// ====================
// Keypad Pin Configuration
// ====================
#define KEYPAD_R1_PIN 4
#define KEYPAD_R2_PIN 5
#define KEYPAD_R3_PIN 6
#define KEYPAD_R4_PIN 7

#define KEYPAD_C1_PIN 8
#define KEYPAD_C2_PIN 9
#define KEYPAD_C3_PIN 10

#define KEYPAD_ROW_COUNT 4
#define KEYPAD_COL_COUNT 3

// ====================
// Buzzer Configuration
// ====================
#define BUZZER_PIN 3

// ====================
// System Configuration
// ====================
#define SERIAL_BAUD_RATE 9600

#endif // CONFIG_H