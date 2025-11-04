#include <Arduino.h>
#include <DIYables_4Digit7Segment_74HC595.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <ezBuzzer.h>
#include "timemachine.h"

// LCD setup - I2C Pins
#define LCD_ADDRESS 0x27
#define LCD_COLUMNS 20
#define LCD_ROWS 4

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

// 7-Segment Display 1 - Digital Pins
#define D1_DIO_PIN   11
#define D1_RCLK_PIN  12
#define D1_SCLK_PIN  13

// 7-Segment Display 2 - Analog Pins
#define D2_DIO_PIN   A0
#define D2_RCLK_PIN  A1
#define D2_SCLK_PIN  A2

DIYables_4Digit7Segment_74HC595 display1(D1_SCLK_PIN, D1_RCLK_PIN, D1_DIO_PIN);
DIYables_4Digit7Segment_74HC595 display2(D2_SCLK_PIN, D2_RCLK_PIN, D2_DIO_PIN);

/// Keypad setup
#define KEYPAD_R1_PIN 4
#define KEYPAD_R2_PIN 5
#define KEYPAD_R3_PIN 6
#define KEYPAD_R4_PIN 7
#define KEYPAD_C1_PIN 8
#define KEYPAD_C2_PIN 9
#define KEYPAD_C3_PIN 10

#define KEYPAD_ROW_COUNT 4
#define KEYPAD_COL_COUNT 3

 byte rowPins[KEYPAD_ROW_COUNT] = {KEYPAD_R1_PIN, KEYPAD_R2_PIN, KEYPAD_R3_PIN, KEYPAD_R4_PIN}; 
 byte colPins[KEYPAD_COL_COUNT] = {KEYPAD_C1_PIN, KEYPAD_C2_PIN, KEYPAD_C3_PIN};

char keyValues[KEYPAD_ROW_COUNT][KEYPAD_COL_COUNT] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

Keypad keypad = Keypad( makeKeymap(keyValues), rowPins, colPins, KEYPAD_ROW_COUNT, KEYPAD_COL_COUNT );

// Piezo Buzzer Setup
#define BUZZER_PIN 3
ezBuzzer buzzer(BUZZER_PIN);

void setup() {
  Serial.begin(9600);
  Serial.println("Timemachine Project Started!");
  
  // Initialize LCD
  lcd.init();
  lcd.backlight();

  // Display welcome message
  lcd.setCursor(2, 0);  
  lcd.print("The Time Machine");

  // Set initial date
  setDate(display1, display2, 12, 25, 1975);

  Serial.println("Setup complete. Ready to run main loop.");
}

void loop() {
  display1.loop();
  display2.loop();
  buzzer.loop();
  
  char key = keypad.getKey();
  if (key){
    Serial.println(key);
    buzzer.beep(100);
  }
}
