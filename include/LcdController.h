#pragma once

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "GameEngine.h"

void printGameTime(struct GameTime remainingTime, uint8_t col, uint8_t row, LiquidCrystal_I2C &lcd);