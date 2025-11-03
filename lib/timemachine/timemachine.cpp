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