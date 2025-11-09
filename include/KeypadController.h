#pragma once

#include <Arduino.h>
#include <Keypad.h>

#include "hardware_config.h"

class KeypadController {
  public:
    KeypadController();
    void begin();
    char getKey();

  private:
    Keypad keypad;
    static byte rowPins[KEYPAD_ROW_COUNT];
    static byte colPins[KEYPAD_COL_COUNT];
    static char keyValues[KEYPAD_ROW_COUNT][KEYPAD_COL_COUNT];
};