#pragma once

#include <Arduino.h>

class LcdController;
class DateController;
class KeypadController;
class BuzzerController;

#define COUNTDOWN_MINUTES 12
#define TOTAL_COUNTDOWN_SECONDS ((unsigned long)COUNTDOWN_MINUTES * 60)

struct GameTime {
    int hours;
    int minutes;
    int seconds;
    int percentage;
};

struct GameState {
    bool gameActive;
    unsigned long gameStartTime;
};

class GameEngine {
  public:
    GameEngine(DateController& dateController, LcdController& lcdController,
               KeypadController& keypadController, BuzzerController& buzzerController);
    void initialize();
    void loop();

  private:
    DateController& dateController;
    LcdController& lcdController;
    KeypadController& keypadController;
    BuzzerController& buzzerController;

    GameState gameState;
    String currentCode;

    unsigned long lastUpdate;

    void startGame();
    void processKeyInput(char key);

    void displayRemainingTime();
    void displayCurrentCode();
    void displayCurrentClues();
    void displayCurrentDate();

    void clearCurrentCode();

    bool isCodeValid();
    bool isGameActive();

    unsigned long getElapsedGameSeconds();

    GameTime getRemainingGameTime();
    unsigned long getRemainingGameSeconds();
    int getRemainingTimePercentage(unsigned long remainingSeconds);

    void handleClearCode();
    void handleCodeSubmission();
    void handleCodeEntry(char key);
};