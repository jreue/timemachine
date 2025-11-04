#ifndef TESTING_H
#define TESTING_H

#include <Arduino.h>
#include <DIYables_4Digit7Segment_74HC595.h>

/**
 * Testing and Verification Library
 * Functions for testing and validating timemachine functionality
 */

// Date display testing functions
void testAllDates(DIYables_4Digit7Segment_74HC595& display1, DIYables_4Digit7Segment_74HC595& display2, unsigned long interval = 2000);

#endif // TESTING_H