#include "GameEngine.h"

#include "BuzzerController.h"
#include "DateController.h"
#include "KeypadController.h"
#include "LcdController.h"
#include "PuzzleData.h"

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
  currentCode = "";
}

// Called when the game is turned on, but not yet started
void GameEngine::initialize() {
  lcdController.printLine("Time Machine v1.24", 1, 1);
  lcdController.printLine("Press # to start", 1, 3);
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
  currentCode = "";

  lcdController.clearScreen();
  displayCurrentClues();
  displayCurrentDate();
}

void GameEngine::processKeyInput(char key) {
  Serial.println(String("Key pressed: ") + key);

  if (!gameState.gameActive) {
    if (key == '#') {
      startGame();
    }
  } else {
    // Game is active - handle code entry
    if (key == '*') {
      handleClearCode();
    } else if (key == '#') {
      handleCodeSubmission();
    } else if (key >= '0' && key <= '9') {
      handleCodeEntry(key);
    }
  }
}

void GameEngine::handleClearCode() {
  clearCurrentCode();
}

void GameEngine::handleCodeSubmission() {
  Serial.println(String("Code submitted: ") + currentCode);

  if (isCodeValid()) {
    Serial.println("VALID");

    if (PuzzleData::hasNextPuzzle()) {
      PuzzleData::advanceToNextPuzzle();
      lcdController.clearRows(0, 2);
      displayCurrentClues();
      displayCurrentDate();
    } else {
      // All puzzles completed - victory!
      gameState.gameActive = false;
      lcdController.clearRows(0, 2);
      Serial.println("ALL PUZZLES COMPLETE!");
    }
  } else {
    Serial.println("INVALID");
  }

  clearCurrentCode();
}

void GameEngine::handleCodeEntry(char key) {
  // Only accept digits and max 4 characters
  if (currentCode.length() < 4) {
    currentCode += key;
    displayCurrentCode();
  }
}

void GameEngine::updateGameState() {
  unsigned long now = millis();

  if (gameState.gameActive && (now - lastUpdate >= 1000)) {
    GameTime remainingTime = getRemainingGameTime();
    lcdController.printGameTime(remainingTime, 12, 3);

    int percentageTime = getRemainingTimePercentage();
    String percentText = String(percentageTime) + "%   ";
    lcdController.printLine(percentText, 0, 3);

    lastUpdate = now;

    if (getRemainingTime() == 0) {
      gameState.gameActive = false;
    }
  }
}

void GameEngine::displayCurrentCode() {
  // Display in columns 5-10 (centered between 4-11)
  // Format: " XXXX " with spaces around it
  lcdController.printLine(" " + currentCode + "    ", 5, 3);
}

void GameEngine::displayCurrentClues() {
  Puzzle* currentPuzzle = PuzzleData::getCurrentPuzzle();
  if (currentPuzzle != nullptr) {
    lcdController.printLine(currentPuzzle->clue1, 0, 0);
    lcdController.printLine(currentPuzzle->clue2, 0, 1);
    lcdController.printLine(currentPuzzle->clue3, 0, 2);
  }
}

void GameEngine::displayCurrentDate() {
  Puzzle* currentPuzzle = PuzzleData::getCurrentPuzzle();
  if (currentPuzzle != nullptr) {
    dateController.showDate(currentPuzzle->month, currentPuzzle->day, currentPuzzle->year);
  }
}

void GameEngine::clearCurrentCode() {
  currentCode = "";
  displayCurrentCode();
}

bool GameEngine::isCodeValid() {
  Puzzle* currentPuzzle = PuzzleData::getCurrentPuzzle();
  if (currentPuzzle != nullptr) {
    return currentCode == currentPuzzle->code;
  }
  return false;
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

int GameEngine::getRemainingTimePercentage() {
  if (!gameState.gameActive) {
    return 0;
  }

  unsigned long totalSeconds = (unsigned long)COUNTDOWN_MINUTES * 60;
  unsigned long remainingSeconds = getRemainingTime();

  return (int)((remainingSeconds * 100) / totalSeconds);
}