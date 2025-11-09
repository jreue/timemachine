#include <Arduino.h>

#include "hardware_config.h"
#include "GameEngine.h"
#include "DateController.h"
#include "LcdController.h"
#include "KeypadController.h"
#include "BuzzerController.h"

LcdController lcdController;
KeypadController keypadController;
DateController dateController;
BuzzerController buzzerController;

GameEngine gameEngine(dateController, lcdController, keypadController, buzzerController);

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  
  lcdController.begin();
  keypadController.begin();
  buzzerController.begin();
  dateController.begin();
  
  gameEngine.initialize();
}

void loop() {
  gameEngine.loop();
}
