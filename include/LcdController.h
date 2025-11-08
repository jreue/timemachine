#pragma once

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "GameEngine.h"

class LcdController {
public:
    LcdController(uint8_t lcd_Addr, uint8_t columns, uint8_t rows);

    void begin();
    void loop();
    void printGameTime(struct GameTime remainingTime, uint8_t col, uint8_t row);

private:
    LiquidCrystal_I2C lcd;
};