#include "DateController.h"

DateController::DateController(uint8_t sclk1, uint8_t rclk1, uint8_t dio1,
                               uint8_t sclk2, uint8_t rclk2, uint8_t dio2)
  : display1(sclk1, rclk1, dio1),
    display2(sclk2, rclk2, dio2) {}

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