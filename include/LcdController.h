#pragma once

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "GameEngine.h"
#include "hardware_config.h"

class LcdController {
public:
    LcdController();

    void begin();
    void loop();
    void printGameTime(struct GameTime remainingTime, uint8_t col, uint8_t row);

private:
    LiquidCrystal_I2C lcd;
};