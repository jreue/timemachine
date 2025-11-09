#pragma once

#include <Arduino.h>

struct Puzzle {
    String clue1;
    String clue2;
    String clue3;
    int month;
    int day;
    int year;
    String code;
};

class PuzzleData {
  public:
    static const int PUZZLE_COUNT = 3;
    static Puzzle puzzles[PUZZLE_COUNT];

    static int getCurrentPuzzleIndex();
    static void setCurrentPuzzleIndex(int index);
    static Puzzle* getCurrentPuzzle();
    static bool hasNextPuzzle();
    static void advanceToNextPuzzle();

  private:
    static int currentPuzzleIndex;
};