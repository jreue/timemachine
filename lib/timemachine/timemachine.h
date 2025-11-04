// Include guard to prevent multiple inclusions
#ifndef TIMEMACHINE_H
#define TIMEMACHINE_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <DIYables_4Digit7Segment_74HC595.h>

/**
 * Timemachine Utility Library
 * Custom functions for the Arduino Uno Timemachine project
 */

// Function declarations
bool debounceButton(int pin, bool& lastState, unsigned long& lastDebounceTime, unsigned long debounceDelay = 50);

void updateLCDTimeDisplay(LiquidCrystal_I2C& lcd, unsigned long startTime);
void setDate(DIYables_4Digit7Segment_74HC595& display1, DIYables_4Digit7Segment_74HC595& display2, int month, int day, int year);
bool nonBlockingBlink(int pin, unsigned long& previousMillis, unsigned long interval = 500);
void testAllDates(DIYables_4Digit7Segment_74HC595& display1, DIYables_4Digit7Segment_74HC595& display2, unsigned long interval = 2000);

#endif // TIMEMACHINE_H