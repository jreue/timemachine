// Include guard to prevent multiple inclusions
#ifndef TIMEMACHINE_H
#define TIMEMACHINE_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

/**
 * Timemachine Utility Library
 * Custom functions for the Arduino Uno Timemachine project
 */

// Function declarations
void blinkPattern(int pin, int* pattern, int patternLength, int delayMs = 200);
bool debounceButton(int pin, bool& lastState, unsigned long& lastDebounceTime, unsigned long debounceDelay = 50);
void serialPrintFloat(float value, int decimals = 2);
void updateLCDTimeDisplay(LiquidCrystal_I2C& lcd, unsigned long startTime);

#endif // TIMEMACHINE_H