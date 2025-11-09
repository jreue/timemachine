#include "GameEngine.h"

#include "BuzzerController.h"
#include "DateController.h"
#include "KeypadController.h"
#include "LcdController.h"

// ============================================================================
// Public Methods
// ============================================================================
GameEngine::GameEngine(DateController& dateController, LcdController& lcdController,
                       KeypadController& keypadController, BuzzerController& buzzerController)
    : dateController(dateController),
      lcdController(lcdController),
      keypadController(keypadController),
      buzzerController(buzzerController) {
  lastUpdate = 0;
  gameState.gameActive = false;
  gameState.gameStartTime = 0;
}

// Called when the game is turned on, but not yet started
void GameEngine::initialize() {
  lcdController.printLine("Time Machine v1.24", 0, 0);
  dateController.showDate(12, 25, 1975);
}

// Main game loop
void GameEngine::loop() {
  dateController.loop();
  lcdController.loop();
  buzzerController.loop();

  char key = keypadController.getKey();
  if (key) {
    processKeyInput(key);
  }

  updateGameState();
}

// ============================================================================
// Private Methods
// ============================================================================

// Officially starts the game
void GameEngine::startGame() {
  gameState.gameActive = true;
  gameState.gameStartTime = millis();
}

void GameEngine::processKeyInput(char key) {
  Serial.println(String("Key pressed: ") + key);
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