#include <Arduino.h>
#include <ezBuzzer.h>

#include "hardware_config.h"
#include "GameEngine.h"
#include "DateController.h"
#include "LcdController.h"
#include "KeypadController.h"

LcdController lcdController;
GameEngine gameEngine;
KeypadController keypadController;
DateController dateController;

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
