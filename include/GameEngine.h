#pragma once

#include <LiquidCrystal_I2C.h>
#include <ezBuzzer.h>

class LcdController;

#define COUNTDOWN_MINUTES 12

struct GameTime {
    int hours;
    int minutes;
    int seconds;
};

class GameEngine {
public:
    GameEngine();
    void startGame();
    void processKeyInput(char key);
    void updateGameState(LcdController &lcdController);
    GameTime getRemainingGameTime();
    bool isGameActive();

private:
    struct GameState {
        bool gameActive;
        unsigned long gameStartTime;
    };

    GameState gameState;
    unsigned long lastUpdate;

    unsigned long getRemainingTime();
};