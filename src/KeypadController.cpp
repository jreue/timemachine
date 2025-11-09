#include "KeypadController.h"

byte KeypadController::rowPins[KEYPAD_ROW_COUNT] = {KEYPAD_R1_PIN, KEYPAD_R2_PIN, KEYPAD_R3_PIN,
                                                    KEYPAD_R4_PIN};
byte KeypadController::colPins[KEYPAD_COL_COUNT] = {KEYPAD_C1_PIN, KEYPAD_C2_PIN, KEYPAD_C3_PIN};

char KeypadController::keyValues[KEYPAD_ROW_COUNT][KEYPAD_COL_COUNT] = {
    {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}, {'*', '0', '#'}};

// ============================================================================
// Public Methods
// ============================================================================
KeypadController::KeypadController()
    : keypad(makeKeymap(keyValues), rowPins, colPins, KEYPAD_ROW_COUNT, KEYPAD_COL_COUNT) {
}

void KeypadController::begin() {
}

char KeypadController::getKey() {
  return keypad.getKey();
}