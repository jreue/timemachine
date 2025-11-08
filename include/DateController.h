#pragma once
#include <Arduino.h>
#include <DIYables_4Digit7Segment_74HC595.h>

class DateController {
public:
    DateController(uint8_t sclk1, uint8_t rclk1, uint8_t dio1,
                   uint8_t sclk2, uint8_t rclk2, uint8_t dio2);

    void begin();
    void loop();
    void showDate(int month, int day, int year);

private:
    DIYables_4Digit7Segment_74HC595 display1;
    DIYables_4Digit7Segment_74HC595 display2;
};