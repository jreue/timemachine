#include "testing.h"
#include "timemachine.h"

/**
 * Test function to cycle through all months with single and double digit days
 * Call this in loop() to automatically test all date format permutations
 * @param display1 - Reference to first 7-segment display (month/day)
 * @param display2 - Reference to second 7-segment display (year)  
 * @param interval - Time between test cases in milliseconds
 */
void testAllDates(DIYables_4Digit7Segment_74HC595& display1, DIYables_4Digit7Segment_74HC595& display2, unsigned long interval) {
  static unsigned long lastUpdate = 0;
  static int currentMonth = 1;
  static bool useSingleDigitDay = true;
  static int testYear = 2025;
  
  if (millis() - lastUpdate >= interval) {
    lastUpdate = millis();
    
    int testDay = useSingleDigitDay ? 5 : 25;  // Single digit: 5th, Double digit: 25th
    
    // Display current test case
    set7SegmentDate(display1, display2, currentMonth, testDay, testYear);
    
    // Print to serial for verification
    Serial.print("Testing: Month=");
    Serial.print(currentMonth);
    Serial.print(", Day=");
    Serial.print(testDay);
    Serial.print(" -> Display should show: ");
    if (currentMonth < 10) Serial.print("0");
    Serial.print(currentMonth);
    Serial.print(".");
    if (testDay < 10) Serial.print("0");
    Serial.print(testDay);
    Serial.print(" / ");
    Serial.println(testYear);
    
    // Advance to next test case
    if (useSingleDigitDay) {
      useSingleDigitDay = false;  // Next: try double digit day for same month
    } else {
      useSingleDigitDay = true;   // Next: single digit day for next month
      currentMonth++;
      if (currentMonth > 12) {
        currentMonth = 1;  // Restart from January
      }
    }
  }
}