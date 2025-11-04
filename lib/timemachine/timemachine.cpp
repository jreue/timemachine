#include "timemachine.h"

/**
 * Update LCD countdown timer display in bottom right corner
 * @param lcd - Reference to LCD object
 * @param startTime - Start time in milliseconds when countdown began
 * @param countdownMinutes - Number of minutes for countdown timer
 */
void updateLCDCountdown(LiquidCrystal_I2C& lcd, unsigned long startTime, int countdownMinutes) {
  // Calculate total countdown time in seconds
  unsigned long totalCountdownSeconds = countdownMinutes * 60;
  
  // Calculate elapsed time since start
  unsigned long elapsedSeconds = (millis() - startTime) / 1000;
  
  // Calculate remaining time (countdown)
  long remainingSeconds = totalCountdownSeconds - elapsedSeconds;
  
  // Handle countdown completion (show 00:00:00 when done)
  if (remainingSeconds <= 0) {
    remainingSeconds = 0;
  }
  
  // Calculate hours, minutes, seconds from remaining time
  int hours = remainingSeconds / 3600;
  int minutes = (remainingSeconds / 60) % 60;
  int seconds = remainingSeconds % 60;
  
  // Position cursor in bottom right corner (row 3, starting from column 11)
  // Format: HH:MM:SS (8 characters, so start at column 20-8=12, but 0-indexed so 11)
  lcd.setCursor(11, 3);
  
  // Print countdown time with leading zeros
  if (hours < 10) lcd.print("0");
  lcd.print(hours);
  lcd.print(":");
  if (minutes < 10) lcd.print("0");
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) lcd.print("0");
  lcd.print(seconds);
}


void set7SegmentDate(DIYables_4Digit7Segment_74HC595& display1, DIYables_4Digit7Segment_74HC595& display2, int month, int day, int year) {
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


