#include "timemachine.h"

/**
 * Blink LED in a custom pattern
 * @param pin - LED pin number
 * @param pattern - Array of on/off durations (1 = on, 0 = off)
 * @param patternLength - Number of elements in pattern
 * @param delayMs - Base delay for each pattern element
 */
void blinkPattern(int pin, int* pattern, int patternLength, int delayMs) {
  for (int i = 0; i < patternLength; i++) {
    if (pattern[i] == 1) {
      digitalWrite(pin, HIGH);
    } else {
      digitalWrite(pin, LOW);
    }
    delay(delayMs);
  }
  digitalWrite(pin, LOW); // Ensure LED is off at the end
}

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
 * Print float value with specified decimal places
 * @param value - Float value to print
 * @param decimals - Number of decimal places
 */
void serialPrintFloat(float value, int decimals) {
  Serial.print(value, decimals);
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