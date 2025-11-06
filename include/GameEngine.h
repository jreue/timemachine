#pragma once

#include <LiquidCrystal_I2C.h>
#include <ezBuzzer.h>

// Total game time in minutes
#define COUNTDOWN_MINUTES 12

// Structure to hold elapsed game hours, minutes, seconds
struct GameTime {
    int hours;
    int minutes;
    int seconds;
};


/**
 * Game state management structure
 */
struct GameState {
    bool gameActive;                        // true = game running, false = game over
    unsigned long gameStartTime;            // millis() when game started
};

extern GameState gameState;

void initializeGame();
void startGame();
void processKeyInput(char key, LiquidCrystal_I2C &lcd, ezBuzzer &buzzer);
void updateGameState(LiquidCrystal_I2C &lcd);
GameTime getRemainingGameTime();