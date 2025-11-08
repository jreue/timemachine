#include <Arduino.h>
#include <DIYables_4Digit7Segment_74HC595.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <ezBuzzer.h>

#include "hardware_config.h"
#include "GameEngine.h"
#include "DateController.h"

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

DateController dateController(D1_SCLK_PIN, D1_RCLK_PIN, D1_DIO_PIN,
                              D2_SCLK_PIN, D2_RCLK_PIN, D2_DIO_PIN);

byte rowPins[KEYPAD_ROW_COUNT] = {KEYPAD_R1_PIN, KEYPAD_R2_PIN, KEYPAD_R3_PIN, KEYPAD_R4_PIN}; 
byte colPins[KEYPAD_COL_COUNT] = {KEYPAD_C1_PIN, KEYPAD_C2_PIN, KEYPAD_C3_PIN};

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
  
  // Init Hardware
  lcd.init();
  lcd.backlight();
  
  // Display welcome message
  lcd.setCursor(0, 0);  
  lcd.print("Time Machine v1.24");
  
  lcd.setCursor(0, 2);
  lcd.print("Status: Offline");

  dateController.begin();
  dateController.showDate(12, 25, 1975);

  initializeGame();
}

void loop() {
  dateController.loop();
  buzzer.loop();
  
  char key = keypad.getKey();
  if (key) {
    processKeyInput(key, lcd, buzzer);
  }

  updateGameState(lcd);
}
