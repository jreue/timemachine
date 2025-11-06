// #include "utils.h"

// /**
//  * Debounce button input
//  * @param pin - Button pin number
//  * @param lastState - Reference to store last button state
//  * @param lastDebounceTime - Reference to store last debounce time
//  * @param debounceDelay - Debounce delay in milliseconds
//  * @return True if button was pressed (stable state change)
//  */
// bool debounceButton(int pin, bool& lastState, unsigned long& lastDebounceTime, unsigned long debounceDelay) {
//   bool currentState = digitalRead(pin);
  
//   if (currentState != lastState) {
//     lastDebounceTime = millis();
//   }
  
//   if ((millis() - lastDebounceTime) > debounceDelay) {
//     if (currentState != lastState) {
//       lastState = currentState;
//       return (currentState == LOW); // Return true for button press (assuming pullup)
//     }
//   }
  
//   return false;
// }

// /**
//  * Non-blocking LED blink function - safe to use with 7-segment displays
//  * @param pin - LED pin number
//  * @param previousMillis - Reference to store last blink time (must be static/global)
//  * @param interval - Blink interval in milliseconds (default 500ms)
//  * @return True when LED state changes
//  */
// bool nonBlockingBlink(int pin, unsigned long& previousMillis, unsigned long interval) {
//   unsigned long currentMillis = millis();
  
//   if (currentMillis - previousMillis >= interval) {
//     previousMillis = currentMillis;
    
//     // Toggle LED state
//     digitalWrite(pin, !digitalRead(pin));
//     return true; // LED state changed
//   }
  
//   return false; // No change
// }