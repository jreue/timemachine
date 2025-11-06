#include "LcdController.h"

void printGameTime(GameTime remainingTime, uint8_t col, uint8_t row, LiquidCrystal_I2C &lcd) {
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