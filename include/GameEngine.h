#pragma once

#include <LiquidCrystal_I2C.h>
#include <ezBuzzer.h>

class LcdController;
class DateController;
class BuzzerController;

#define COUNTDOWN_MINUTES 12

struct GameTime {
    int hours;
    int minutes;
    int seconds;
};

class GameEngine {
public:
    GameEngine(DateController &dateController, LcdController &lcdController, BuzzerController &buzzerController);
    void initialize();
    void startGame();
    void processKeyInput(char key);
    void updateGameState();
    GameTime getRemainingGameTime();
    bool isGameActive();

private:
    struct GameState {
        bool gameActive;
        unsigned long gameStartTime;
    };

    GameState gameState;
    unsigned long lastUpdate;
    
    DateController &dateController;
    LcdController &lcdController;
    BuzzerController &buzzerController;

    unsigned long getRemainingTime();
};