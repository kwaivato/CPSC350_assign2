// classicGame.h
// A declared game child class used to play Game Of Life on Classic mode given an initial board.
// represented by a string and two ints (columns and rows).
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "game.h"

using namespace std;

#ifndef C_GAME_H
#define C_GAME_H

class ClassicGame : public Game
{
  public:
    // Constructors
      // Default
    ClassicGame();
      // Overloaded
    ClassicGame(int rows, int columns, string initialBoard);
    // Destructor
    ~ClassicGame();
    // Methods
    void Simulation();
};

#endif
