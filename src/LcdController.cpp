#include "LcdController.h"

// ============================================================================
// Public Methods
// ============================================================================
LcdController::LcdController() : lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS) {
}

void LcdController::begin() {
  lcd.init();
  lcd.backlight();
}

void LcdController::loop() {
}

void LcdController::printLine(const String& text, uint8_t col, uint8_t row) {
  lcd.setCursor(col, row);
  lcd.print(text);
}

void LcdController::printGameTime(struct GameTime remainingTime, uint8_t col, uint8_t row) {
  lcd.setCursor(col, row);

  if (remainingTime.hours < 10)
    lcd.print("0");
  lcd.print(remainingTime.hours);
  lcd.print(":");
  if (remainingTime.minutes < 10)
    lcd.print("0");
  lcd.print(remainingTime.minutes);
  lcd.print(":");
  if (remainingTime.seconds < 10)
    lcd.print("0");
  lcd.print(remainingTime.seconds);
}