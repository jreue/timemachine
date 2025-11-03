#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "timemachine.h"

// Pin definitions
const int LED_PIN = 13;        // Built-in LED on Arduino Uno

// LCD setup (address, columns, rows)
LiquidCrystal_I2C lcd(0x27, 20, 4);  // Try 0x27 first, common address



// Global variables
unsigned long lastBlinkTime = 0;
const unsigned long blinkInterval = 5000;  // 5 seconds in milliseconds
unsigned long lastTimeUpdate = 0;
const unsigned long timeUpdateInterval = 1000;  // Update time every second
unsigned long startTime = 0;  // Time when Arduino started (in seconds since boot)

void setup() {
  Serial.begin(9600);
  Serial.println("Arduino Uno Timemachine Project Started!");
  
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  
  // Center "The Time Machine" on 20-character display
  // Text is 16 characters, so (20-16)/2 = 2 spaces from left
  lcd.setCursor(2, 0);  // Column 2, Row 0 (centered)
  lcd.print("The Time Machine");
  
  // Configure pins
  pinMode(LED_PIN, OUTPUT);
  
  // Initial LED state
  digitalWrite(LED_PIN, LOW);
  
  // Initialize time tracking
  startTime = millis() / 1000;  // Convert to seconds
  
  Serial.println("Setup complete. LCD initialized. Ready to run main loop.");
}

void loop() {
  unsigned long currentTime = millis();
  
  // Check if it's time to blink the LED (every 5 seconds)
  if (currentTime - lastBlinkTime >= blinkInterval) {
    // Use the library function to blink once
    int pattern[] = {1, 0};  // ON, then OFF
    blinkPattern(LED_PIN, pattern, 2, 250);  // 250ms for each state (0.5s total blink)
    
    // Update last blink time
    lastBlinkTime = currentTime;
  }
  
  // Update time display every second
  if (currentTime - lastTimeUpdate >= timeUpdateInterval) {
    updateLCDTimeDisplay(lcd, startTime);
    lastTimeUpdate = currentTime;
  }
}


