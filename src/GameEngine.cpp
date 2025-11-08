#include "GameEngine.h"
#include "LcdController.h"
#include "DateController.h"
#include "BuzzerController.h"

GameEngine::GameEngine(DateController &dateController, LcdController &lcdController, BuzzerController &buzzerController) 
    : lastUpdate(0), 
      dateController(dateController),
      lcdController(lcdController),
      buzzerController(buzzerController) {
    gameState.gameActive = false;
    gameState.gameStartTime = 0;
}

void GameEngine::initialize() {
    dateController.showDate(12, 25, 1975);
}

void GameEngine::startGame() {
    gameState.gameActive = true;
    gameState.gameStartTime = millis();
}

void GameEngine::processKeyInput(char key) {
#ifdef DEBUG
    Serial.print("Key pressed: ");
    Serial.println(key);
#endif

    if (!gameState.gameActive) {
        if (key == '*') {
            startGame();
        } 
    } 
}

void GameEngine::updateGameState() {
    unsigned long now = millis();
 
    if (gameState.gameActive && (now - lastUpdate >= 1000)) {
        GameTime remainingTime = getRemainingGameTime();

        lcdController.printGameTime(remainingTime, 12, 3);

        lastUpdate = now;

        if (getRemainingTime() == 0) {
            gameState.gameActive = false;
        }
    }
}

bool GameEngine::isGameActive() {
    return gameState.gameActive;
}

unsigned long GameEngine::getRemainingTime() {
    if (!gameState.gameActive) {
        return 0;
    }
    
    unsigned long totalSeconds = (unsigned long)COUNTDOWN_MINUTES * 60;
    unsigned long elapsedSeconds = (millis() - gameState.gameStartTime) / 1000;
    
    if (elapsedSeconds >= totalSeconds) {
        return 0;
    }

    return (totalSeconds - elapsedSeconds);
}

GameTime GameEngine::getRemainingGameTime() {
    GameTime time = {0, 0, 0};
    
    unsigned long remainingSeconds = getRemainingTime();
    
    time.hours = remainingSeconds / 3600;
    remainingSeconds %= 3600;
    time.minutes = remainingSeconds / 60;
    time.seconds = remainingSeconds % 60;
    
    return time;
}