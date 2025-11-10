#pragma once

#include <LiquidCrystal_I2C.h>

#include "GameEngine.h"
#include "hardware_config.h"

class LcdController {
  public:
    LcdController();

    void begin();
    void loop();
    void printLine(const String& text, uint8_t col, uint8_t row);
    void printGameTime(struct GameTime remainingTime, uint8_t col, uint8_t row);
    void clearScreen();
    void clearRow(uint8_t row);
    void clearRows(uint8_t fromRow, uint8_t toRow);

  private:
    LiquidCrystal_I2C lcd;
};