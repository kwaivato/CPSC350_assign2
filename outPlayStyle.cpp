// outPlayStyle.cpp
// An implemented play style child class used to customize output for a Game of Life program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "outPlayStyle.h"

using namespace std;

// Default Constructor
OutPlayStyle::OutPlayStyle()
{

}

// Overloaded Constructor
OutPlayStyle::OutPlayStyle(string gameChoice, int rows, int columns, string initialBoard, string fileName)
{
  m_game_choice = gameChoice;
  m_rows_play = rows;
  m_columns_play = columns;
  m_initial_board_play = initialBoard;
  m_file_name_play_style = fileName + ".txt";
}

// Destructor
OutPlayStyle::~OutPlayStyle()
{

}

// Methods
  // This Play() method is implemented to output a results file for the game.
void OutPlayStyle::Play()
{
  // An output file is opened, and then basic information is put into it.
  m_out_stream.open(m_file_name_play_style);
  m_out_stream << "Game of Life Simulation" << endl;
  m_out_stream << "Author: Vidal M. Arroyo" << endl;
  m_out_stream << "Number of Rows: " << m_rows_play << endl;
  m_out_stream << "Number of Columns: " << m_columns_play << endl;
  // The if-else statements are here so that we can declare a game as either classic, doughnut, or mirror.
  if (m_game_choice == "C")
  {
    // The game mode is put into the file so that the user knows once they look back at the output file.
    m_out_stream << "Game Mode: Classic" << endl;
    ClassicGame m_game(m_rows_play, m_columns_play, m_initial_board_play);
    // This while loop ensure that the game is played until it is finished.
    while(!(m_game.getGameStatus()))
    {
      m_game.setCurrentGeneration();
      cout << m_game.getCurrentGeneration();
      // Each generation is printed into the output file.
      m_out_stream << m_game.getCurrentGeneration();
      m_game.Simulation();
      m_game.setGameStatus();
    }
    cout << "Our population has reached stability, so the game has ended!" << endl;
  }
  // The structure for doughnut and mirror is the exact same, except that it is played with slighly different rules (see Game classes).
  else if (m_game_choice == "D")
  {
    m_out_stream << "Game Mode: Doughnut" << endl;
    DoughnutGame m_game(m_rows_play, m_columns_play, m_initial_board_play);
    while(!(m_game.getGameStatus()))
    {
      m_game.setCurrentGeneration();
      cout << m_game.getCurrentGeneration();
      m_out_stream << m_game.getCurrentGeneration();
      m_game.Simulation();
      m_game.setGameStatus();
    }
    cout << "Our population has reached stability, so the game has ended!" << endl;
  }
  else if (m_game_choice == "M")
  {
    m_out_stream << "Game Mode: Mirror" << endl;
    MirrorGame m_game(m_rows_play, m_columns_play, m_initial_board_play);
    while(!(m_game.getGameStatus()))
    {
      m_game.setCurrentGeneration();
      cout << m_game.getCurrentGeneration();
      m_out_stream << m_game.getCurrentGeneration();
      m_game.Simulation();
      m_game.setGameStatus();
    }
    cout << "Our population has reached stability, so the game has ended!" << endl;
  }
  m_out_stream.close();
  cout << "Results are saved in " + m_file_name_play_style << endl;
}
