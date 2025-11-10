#include "BuzzerController.h"

// ============================================================================
// Public Methods
// ============================================================================
BuzzerController::BuzzerController() : buzzer(BUZZER_PIN) {
}

void BuzzerController::begin() {
}

void BuzzerController::loop() {
  buzzer.loop();
}

void BuzzerController::beep(int duration) {
  buzzer.beep(duration);
}

void BuzzerController::playSuccess() {
  int melody[] = {NOTE_C5, NOTE_E5, NOTE_G5};
  int noteDurations[] = {8, 8, 4};  // eighth, eighth, quarter note
  int length = sizeof(noteDurations) / sizeof(int);
  buzzer.playMelody(melody, noteDurations, length);
}

void BuzzerController::playFailure() {
  int melody[] = {NOTE_G5, NOTE_E5, NOTE_C5};
  int noteDurations[] = {8, 8, 4};  // eighth, eighth, quarter note
  int length = sizeof(noteDurations) / sizeof(int);
  buzzer.playMelody(melody, noteDurations, length);
}

void BuzzerController::playWarning() {
  int melody[] = {NOTE_A5, NOTE_A5};
  int noteDurations[] = {8, 8};  // two eighth notes
  int length = sizeof(noteDurations) / sizeof(int);
  buzzer.playMelody(melody, noteDurations, length);
}

void BuzzerController::playVictory() {
  int melody[] = {NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
  int noteDurations[] = {8, 8, 8, 8, 8, 8, 8, 4};  // scale up to high C
  int length = sizeof(noteDurations) / sizeof(int);
  buzzer.playMelody(melody, noteDurations, length);
}
