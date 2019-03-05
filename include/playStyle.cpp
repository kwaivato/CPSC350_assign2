// playStyle.cpp
// An implemented play style parent class used to customize output for a Game of Life program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "playStyle.h"

using namespace std;

// Default Constructor
PlayStyle::PlayStyle()
{

}

// Overloaded Constructor
PlayStyle::PlayStyle(string gameChoice, int rows, int columns, string initialBoard)
{
  m_game_choice = gameChoice;
  m_rows_play = rows;
  m_columns_play = columns;
  m_initial_board_play = initialBoard;
}

// Destructor
PlayStyle::~PlayStyle()
{

}

// Methods
void PlayStyle::Play()
{

}
