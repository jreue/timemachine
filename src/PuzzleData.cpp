#include "PuzzleData.h"

int PuzzleData::currentPuzzleIndex = 0;

Puzzle PuzzleData::puzzles[PuzzleData::PUZZLE_COUNT] = {
    {"FLUX CAPACITOR", "1.21 GIGAWATTS", "DELOREAN TIME", 12, 25, 1975, "1111"},
    {"HOVERBOARD ERA", "SPORTS ALMANAC", "CLOCK TOWER", 10, 21, 2015, "2222"},
    {"WESTERN TIMES", "TRAIN HEIST", "OLD WEST", 9, 2, 1885, "3333"}};

int PuzzleData::getCurrentPuzzleIndex() {
  return currentPuzzleIndex;
}

void PuzzleData::setCurrentPuzzleIndex(int index) {
  if (index >= 0 && index < PUZZLE_COUNT) {
    currentPuzzleIndex = index;
  }
}

Puzzle* PuzzleData::getCurrentPuzzle() {
  if (currentPuzzleIndex >= 0 && currentPuzzleIndex < PUZZLE_COUNT) {
    return &puzzles[currentPuzzleIndex];
  }
  return nullptr;
}

bool PuzzleData::hasNextPuzzle() {
  return currentPuzzleIndex < PUZZLE_COUNT - 1;
}

void PuzzleData::advanceToNextPuzzle() {
  if (hasNextPuzzle()) {
    currentPuzzleIndex++;
  }
}