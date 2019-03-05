// doughnutGame.h
// A declared game child class used to play Game Of Life on Doughnut mode given an initial board.
// represented by a string and two ints (columns and rows).
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "game.h"

using namespace std;

#ifndef D_GAME_H
#define D_GAME_H

class DoughnutGame : public Game
{
  public:
    // Constructors
      // Default
    DoughnutGame();
      // Overloaded
    DoughnutGame(int rows, int columns, string initialBoard);
    // Destructor
    ~DoughnutGame();
    // Methods
    void Simulation();
};

#endif
