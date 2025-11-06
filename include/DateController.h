#ifndef DATECONTROLLER_H
#define DATECONTROLLER_H

#include <Arduino.h>
#include <DIYables_4Digit7Segment_74HC595.h>

void testAllDates(DIYables_4Digit7Segment_74HC595& display1, DIYables_4Digit7Segment_74HC595& display2, unsigned long interval = 2000);
void set7SegmentDate(DIYables_4Digit7Segment_74HC595& display1, DIYables_4Digit7Segment_74HC595& display2, int month, int day, int year);

#endif // DATECONTROLLER_H