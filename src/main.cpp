#include <Arduino.h>
#include <DIYables_4Digit7Segment_74HC595.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <ezBuzzer.h>
#include "timemachine.h"
#include "config.h"

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);
DIYables_4Digit7Segment_74HC595 display1(D1_SCLK_PIN, D1_RCLK_PIN, D1_DIO_PIN);
DIYables_4Digit7Segment_74HC595 display2(D2_SCLK_PIN, D2_RCLK_PIN, D2_DIO_PIN);

const byte rowPins[KEYPAD_ROW_COUNT] = {KEYPAD_R1_PIN, KEYPAD_R2_PIN, KEYPAD_R3_PIN, KEYPAD_R4_PIN}; 
const byte colPins[KEYPAD_COL_COUNT] = {KEYPAD_C1_PIN, KEYPAD_C2_PIN, KEYPAD_C3_PIN};

char keyValues[KEYPAD_ROW_COUNT][KEYPAD_COL_COUNT] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

Keypad keypad = Keypad( makeKeymap(keyValues), rowPins, colPins, KEYPAD_ROW_COUNT, KEYPAD_COL_COUNT );
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
