#include "timemachine.h"

/**
 * Debounce button input
 * @param pin - Button pin number
 * @param lastState - Reference to store last button state
 * @param lastDebounceTime - Reference to store last debounce time
 * @param debounceDelay - Debounce delay in milliseconds
 * @return True if button was pressed (stable state change)
 */
bool debounceButton(int pin, bool& lastState, unsigned long& lastDebounceTime, unsigned long debounceDelay) {
  bool currentState = digitalRead(pin);
  
  if (currentState != lastState) {
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (currentState != lastState) {
      lastState = currentState;
      return (currentState == LOW); // Return true for button press (assuming pullup)
    }
  }
  
  return false;
}


/**
 * Update LCD time display in bottom right corner
 * @param lcd - Reference to LCD object
 * @param startTime - Start time in seconds for elapsed time calculation
 */
void updateLCDTimeDisplay(LiquidCrystal_I2C& lcd, unsigned long startTime) {
  unsigned long totalSeconds = (millis() / 1000) - startTime;
  
  // Calculate hours, minutes, seconds from total seconds
  int hours = (totalSeconds / 3600) % 24;  // Keep within 24-hour format
  int minutes = (totalSeconds / 60) % 60;
  int seconds = totalSeconds % 60;
  
  // Position cursor in bottom right corner (row 3, starting from column 11)
  // Format: HH:MM:SS (8 characters, so start at column 20-8=12, but 0-indexed so 11)
  lcd.setCursor(11, 3);
  
  // Print time with leading zeros
  if (hours < 10) lcd.print("0");
  lcd.print(hours);
  lcd.print(":");
  if (minutes < 10) lcd.print("0");
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) lcd.print("0");
  lcd.print(seconds);
}


void setDate(DIYables_4Digit7Segment_74HC595& display1, DIYables_4Digit7Segment_74HC595& display2, int month, int day, int year) {
  // Clear display and manually set each digit to avoid floating point precision issues
  display1.clear();
  
  // Set month digits (positions 1 and 2)
  display1.setNumber(1, month / 10);   // Tens digit of month
  display1.setNumber(2, month % 10);   // Ones digit of month
  
  // Set decimal point between month and day
  display1.setDot(2);
  
  // Set day digits (positions 3 and 4) 
  display1.setNumber(3, day / 10);     // Tens digit of day
  display1.setNumber(4, day % 10);     // Ones digit of day
  
  display1.show();
  
  // Display year on display2 (YYYY)
  display2.printInt(year, false);
}

/**
 * Non-blocking LED blink function - safe to use with 7-segment displays
 * @param pin - LED pin number
 * @param previousMillis - Reference to store last blink time (must be static/global)
 * @param interval - Blink interval in milliseconds (default 500ms)
 * @return True when LED state changes
 */
bool nonBlockingBlink(int pin, unsigned long& previousMillis, unsigned long interval) {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    // Toggle LED state
    digitalWrite(pin, !digitalRead(pin));
    return true; // LED state changed
  }
  
  return false; // No change
}

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
    setDate(display1, display2, currentMonth, testDay, testYear);
    
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
