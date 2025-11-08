#include "DateController.h"

DateController::DateController()
  : display1(D1_SCLK_PIN, D1_RCLK_PIN, D1_DIO_PIN),
    display2(D2_SCLK_PIN, D2_RCLK_PIN, D2_DIO_PIN) {}

void DateController::begin() {
    display1.clear();
    display2.clear();
}

void DateController::loop(){
  display1.loop();
  display2.loop();
}

void DateController::showDate(int month, int day, int year) {
    display1.clear();

    display1.setNumber(1, month / 10);
    display1.setNumber(2, month % 10);
    display1.setDot(2);
    display1.setNumber(3, day / 10);
    display1.setNumber(4, day % 10);
    display1.show();

    display2.printInt(year, false);
}