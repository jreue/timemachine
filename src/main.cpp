#include <Arduino.h>
#include "timemachine.h"

// Pin definitions
const int LED_PIN = 13;        // Built-in LED on Arduino Uno

// Global variables
unsigned long lastBlinkTime = 0;
const unsigned long blinkInterval = 5000;  // 5 seconds in milliseconds

void setup() {
  Serial.begin(9600);
  Serial.println("Arduino Uno Timemachine Project Started!");
  
  // Configure pins
  pinMode(LED_PIN, OUTPUT);
  
  // Initial LED state
  digitalWrite(LED_PIN, LOW);
  
  Serial.println("Setup complete. Ready to run main loop.");
}

void loop() {
  // Check if it's time to blink the LED (every 5 seconds)
  unsigned long currentTime = millis();
  
  if (currentTime - lastBlinkTime >= blinkInterval) {
    // Use the library function to blink once
    int pattern[] = {1, 0};  // ON, then OFF
    blinkPattern(LED_PIN, pattern, 2, 250);  // 250ms for each state (0.5s total blink)
    
    // Update last blink time
    lastBlinkTime = currentTime;
  }
}

