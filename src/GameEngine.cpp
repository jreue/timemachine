#include "GameEngine.h"
#include "LcdController.h"

GameState gameState = {
    .gameActive = false,
    .gameStartTime = 0
};

void initializeGame() {
    gameState.gameActive = false;
    gameState.gameStartTime = 0;
}

void startGame() {
    gameState.gameActive = true;
    gameState.gameStartTime = millis();
}



void processKeyInput(char key) {
    Serial.println(key);

    if (!gameState.gameActive) {
        if (key == '*') {
            startGame();
        } 
    } 
}



void updateGameState(LcdController &lcdController) {
    static unsigned long lastUpdate = 0;
    unsigned long now = millis();
 
    if (gameState.gameActive && (now - lastUpdate >= 1000)) {
        GameTime remainingTime = getRemainingGameTime();

        lcdController.printGameTime(remainingTime, 12, 3);

        lastUpdate = now;
    }
}

/**
 * Get remaining time in seconds
 */
unsigned long getRemainingTime() {
    if (!gameState.gameActive) {
        return 0;
    }
    
    // Total game time in seconds
    unsigned long totalSeconds = (unsigned long)COUNTDOWN_MINUTES * 60;

    // Elapsed game time in seconds
    unsigned long elapsedSeconds = (millis() - gameState.gameStartTime)/1000;
    
    // If time is up, return 0
    if (elapsedSeconds >= totalSeconds) {
        return 0;
    }

    // Remaining game time in seconds
    return (totalSeconds - elapsedSeconds);
}

/**
 * Get remaining time as hours, minutes, seconds structure
 */
GameTime getRemainingGameTime() {
    GameTime time = {0, 0, 0};
    
    unsigned long remainingSeconds = getRemainingTime();
    
    time.hours = remainingSeconds / 3600;
    // Get the remaining seconds after extracting hours
    remainingSeconds %= 3600;
    time.minutes = remainingSeconds / 60;
    time.seconds = remainingSeconds % 60;
    
    return time;
}