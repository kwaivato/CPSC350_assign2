// enterPlayStyle.cpp
// An implemented play style child class used to customize output for a Game of Life program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "enterPlayStyle.h"

using namespace std;

// Default Constructor
EnterPlayStyle::EnterPlayStyle()
{

}

// Overloaded Constructor
EnterPlayStyle::EnterPlayStyle(string gameChoice, int rows, int columns, string initialBoard)
{
  m_game_choice = gameChoice;
  m_rows_play = rows;
  m_columns_play = columns;
  m_initial_board_play = initialBoard;
}

// Destructor
EnterPlayStyle::~EnterPlayStyle()
{

}

// Methods
  // This Play() method is implemented to force the user to press enter between each output.
void EnterPlayStyle::Play()
{
  // The if-else statements are here so that we can declare a game as either classic, doughnut, or mirror.
  if (m_game_choice == "C")
  {
    ClassicGame m_game(m_rows_play, m_columns_play, m_initial_board_play);
    // This while loop ensure that the game is played until it is finished.
    while(!(m_game.getGameStatus()))
    {
      m_game.setCurrentGeneration();
      cout << m_game.getCurrentGeneration();
      m_game.Simulation();
      m_game.setGameStatus();
      // The cin.ignore() statement forces the user to press enter before the next iteration of the game.
      cin.ignore();
    }
    cout << "Our population has reached stability, so the game has ended!" << endl;
  }
  // The structure for doughnut and mirror is the exact same, except that it is played with slighly different rules (see Game classes).
  else if (m_game_choice == "D")
  {
    DoughnutGame m_game(m_rows_play, m_columns_play, m_initial_board_play);
    while(!(m_game.getGameStatus()))
    {
      m_game.setCurrentGeneration();
      cout << m_game.getCurrentGeneration();
      m_game.Simulation();
      m_game.setGameStatus();
      cin.ignore();
    }
    cout << "Our population has reached stability, so the game has ended!" << endl;
  }
  else if (m_game_choice == "M")
  {
    MirrorGame m_game(m_rows_play, m_columns_play, m_initial_board_play);
    while(!(m_game.getGameStatus()))
    {
      m_game.setCurrentGeneration();
      cout << m_game.getCurrentGeneration();
      m_game.Simulation();
      m_game.setGameStatus();
      cin.ignore();
    }
    cout << "Our population has reached stability, so the game has ended!" << endl;
  }
}
