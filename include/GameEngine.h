#pragma once

#include <Arduino.h>

class LcdController;
class DateController;
class KeypadController;
class BuzzerController;

#define COUNTDOWN_MINUTES 12

struct GameTime {
    int hours;
    int minutes;
    int seconds;
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
    void updateGameState();
    void displayCurrentCode();
    void displayCurrentClues();
    void clearCurrentCode();
    GameTime getRemainingGameTime();
    bool isGameActive();
    unsigned long getRemainingTime();
    int getRemainingTimePercentage();

    void handleClearCode();
    void handleCodeSubmission();
    void handleCodeEntry(char key);
};