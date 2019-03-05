// mirrorGame.h
// A declared game child class used to play Game Of Life on Mirror mode given an initial board.
// represented by a string and two ints (columns and rows).
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "game.h"

using namespace std;

#ifndef M_GAME_H
#define M_GAME_H

class MirrorGame : public Game
{
  public:
    // Constructors
      // Default
    MirrorGame();
      // Overloaded
    MirrorGame(int rows, int columns, string initialBoard);
    // Destructor
    ~MirrorGame();
    // Methods
    void Simulation();
};

#endif
