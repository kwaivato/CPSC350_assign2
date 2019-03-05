// pausePlayStyle.cpp
// An implemented play style child class used to customize output for a Game of Life program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "pausePlayStyle.h"

using namespace std;
// The following namespace is included for the sleep_for function.
using namespace std::this_thread;
// The following namespace is included for nanoseconds.
using namespace std::chrono;

// Default Constructor
PausePlayStyle::PausePlayStyle()
{

}

// Overloaded Constructor
PausePlayStyle::PausePlayStyle(string gameChoice, int rows, int columns, string initialBoard)
{
  m_game_choice = gameChoice;
  m_rows_play = rows;
  m_columns_play = columns;
  m_initial_board_play = initialBoard;
}

// Destructor
PausePlayStyle::~PausePlayStyle()
{

}

// Methods
  // This Play() method is implemented to pause between outputting each genertion.
void PausePlayStyle::Play()
{
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
      // This sleep_for function forces the computer to slow down for about 200000000 nanoseconds (0.2 seconds).
      sleep_for(nanoseconds(200000000));
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
      sleep_for(nanoseconds(200000000));
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
      sleep_for(nanoseconds(200000000));
    }
    cout << "Our population has reached stability, so the game has ended!" << endl;
  }
}
