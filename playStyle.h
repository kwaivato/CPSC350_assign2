// playStyle.h
// A declared play style parent class used to customize output for a Game of Life program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "classicGame.h"
#include "doughnutGame.h"
#include "mirrorGame.h"

using namespace std;

#ifndef PLAYSTYLE_H
#define PLAYSTYLE_H

class PlayStyle{
  public:
    // Constructors
      // Default
    PlayStyle();
      // Overloaded
    PlayStyle(string gameChoice, int rows, int columns, string initialBoard);
    // Destructor
    ~PlayStyle();
    // Methods
    void Play();
  // The following variables are declared private so that the child classes can easily access and modify them.
  protected:
    Game m_game;
    string m_game_choice;
    int m_rows_play;
    int m_columns_play;
    string m_initial_board_play;
};

#endif
