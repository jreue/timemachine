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

void updateLCDCountdown(LiquidCrystal_I2C& lcd, unsigned long startTime, int countdownMinutes);
void set7SegmentDate(DIYables_4Digit7Segment_74HC595& display1, DIYables_4Digit7Segment_74HC595& display2, int month, int day, int year);

#endif // TIMEMACHINE_H