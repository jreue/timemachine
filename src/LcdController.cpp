#include "LcdController.h"

LcdController::LcdController(uint8_t lcd_Addr, uint8_t columns, uint8_t rows)
    : lcd(lcd_Addr, columns, rows) {}

void LcdController::begin() {
    lcd.init();
    lcd.backlight();


    /// meh
    lcd.setCursor(0, 0);  
    lcd.print("Time Machine v1.24");
    
    lcd.setCursor(0, 2);
    lcd.print("Status: Offline");
}

void LcdController::loop() {
    // Add any necessary loop code here
}

void LcdController::printGameTime(struct GameTime remainingTime, uint8_t col, uint8_t row) {
    Serial.println(remainingTime.seconds);
    lcd.setCursor(col, row);

    if (remainingTime.hours < 10) lcd.print("0");
    lcd.print(remainingTime.hours);
    lcd.print(":");
    if (remainingTime.minutes < 10) lcd.print("0");
    lcd.print(remainingTime.minutes);
    lcd.print(":");
    if (remainingTime.seconds < 10) lcd.print("0");
    lcd.print(remainingTime.seconds);
}