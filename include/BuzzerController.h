#pragma once

#include <Arduino.h>
#include <ezBuzzer.h>
#include "hardware_config.h"

class BuzzerController {
public:
    BuzzerController();
    void begin();
    void loop();
    
    void playSuccess();
    void playFailure();
    void playWarning();
    void playVictory();
    void beep(int duration = 100);

private:
    ezBuzzer buzzer;
};
