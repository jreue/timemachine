#include <Arduino.h>

#include "hardware_config.h"
#include "GameEngine.h"
#include "DateController.h"
#include "LcdController.h"
#include "KeypadController.h"
#include "BuzzerController.h"

LcdController lcdController;
GameEngine gameEngine;
KeypadController keypadController;
DateController dateController;
BuzzerController buzzerController;

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  
  lcdController.begin();
  keypadController.begin();
  buzzerController.begin();
  
  dateController.begin();
  dateController.showDate(12, 25, 1975);
}

void loop() {
  dateController.loop();
  buzzerController.loop();
  
  char key = keypadController.getKey();
  if (key) {
    gameEngine.processKeyInput(key);
  }

  gameEngine.updateGameState(lcdController);
}
