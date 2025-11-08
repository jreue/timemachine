#include <Arduino.h>
#include <DIYables_4Digit7Segment_74HC595.h> 
#include <LiquidCrystal_I2C.h>
#include <ezBuzzer.h>

#include "hardware_config.h"
#include "GameEngine.h"
#include "DateController.h"
#include "LcdController.h"
#include "KeypadController.h"

LcdController lcdController(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);
GameEngine gameEngine;
KeypadController keypadController;

DateController dateController(D1_SCLK_PIN, D1_RCLK_PIN, D1_DIO_PIN,
                              D2_SCLK_PIN, D2_RCLK_PIN, D2_DIO_PIN);

ezBuzzer buzzer(BUZZER_PIN);

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  
  lcdController.begin();
  keypadController.begin();
  
  dateController.begin();
  dateController.showDate(12, 25, 1975);
}

void loop() {
  dateController.loop();
  buzzer.loop();
  
  char key = keypadController.getKey();
  if (key) {
    gameEngine.processKeyInput(key);
  }

  gameEngine.updateGameState(lcdController);
}
