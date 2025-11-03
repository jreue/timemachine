#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "timemachine.h"
#include <Keypad.h>

// Pin definitions
const int LED_PIN = 13;        // Built-in LED on Arduino Uno

// LCD setup (address, columns, rows)
LiquidCrystal_I2C lcd(0x27, 20, 4);  // Try 0x27 first, common address

#include <DIYables_4Digit7Segment_74HC595.h> // DIYables_4Digit7Segment_74HC595 library

// Display Module 1 on Digital Pins 11, 12, 13
#define D1_DIO   11   // The Arduino pin connected to DIO
#define D1_RCLK  12   // The Arduino pin connected to RCLK
#define D1_SCLK  13  // The Arduino pin connected to SCLK

// Display Module 2 on Analog Pins A0, A1, A2
#define D2_DIO   A0  // The Arduino pin connected to DIO  
#define D2_RCLK  A1  // The Arduino pin connected to RCLK
#define D2_SCLK  A2  // The Arduino pin connected to SCLK

DIYables_4Digit7Segment_74HC595 display1(D1_SCLK, D1_RCLK, D1_DIO);
DIYables_4Digit7Segment_74HC595 display2(D2_SCLK, D2_RCLK, D2_DIO);

/// Keypad setup
const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 3; //three columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte pin_rows[ROW_NUM] = {4, 5, 6, 7}; 
byte pin_column[COLUMN_NUM] = {8, 9, 10};

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );


void setup() {
  Serial.begin(9600);
  Serial.println("Arduino Uno Timemachine Project Started!");
  
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  
  // Center "The Time Machine" on 20-character display
  // Text is 16 characters, so (20-16)/2 = 2 spaces from left
  lcd.setCursor(2, 0);  // Column 2, Row 0 (centered)
  lcd.print("The Time Machine");
  
  display1.printFloat(12.25, 2, false); 
  display2.printInt(1975, false); 

  // Configure pins
  pinMode(LED_PIN, OUTPUT);
  
  // Initial LED state
  digitalWrite(LED_PIN, LOW);
  
  
  Serial.println("Setup complete. LCD initialized. Ready to run main loop.");
}

void loop() {
  char key = keypad.getKey();

  if (key){
    Serial.println(key);
  }
  

  // The above 1 second look is affecting the multiplexing timing - be aware
  display1.loop();
  display2.loop();
}


