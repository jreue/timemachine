#include "BuzzerController.h"

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
    int melody[] = {262, 330, 392};
    int noteDurations[] = {100, 100, 200};
    buzzer.playMelody(melody, noteDurations, 3);
}

void BuzzerController::playFailure() {
    int melody[] = {392, 330, 262};
    int noteDurations[] = {100, 100, 200};
    buzzer.playMelody(melody, noteDurations, 3);
}

void BuzzerController::playWarning() {
    int melody[] = {440, 440};
    int noteDurations[] = {100, 100};
    buzzer.playMelody(melody, noteDurations, 2);
}

void BuzzerController::playVictory() {
    int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};
    int noteDurations[] = {100, 100, 100, 100, 100, 100, 100, 200};
    buzzer.playMelody(melody, noteDurations, 8);
}
