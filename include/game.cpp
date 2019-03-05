// game.cpp
// An implemented game parent class used to play Game Of Life given an initial board.
// represented by a string and two ints (columns and rows).
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "game.h"

using namespace std;

// Default Constructor
Game::Game()
{

}

// Overloaded Constructor
Game::Game(int rows, int columns, string initialBoard)
{
  m_current_matrix = initialBoard;
  m_start_matrix_rows = rows;
  m_start_matrix_columns = columns;
  m_start_matrix_minimum_row_index = 0;
  m_start_matrix_minimum_column_index = 0;
  m_start_matrix_maximum_row_index = m_start_matrix_rows - 1;
  m_start_matrix_maximum_column_index = m_start_matrix_columns - 1;
  // These play matrices are declared to be different to avoid early termination of the game.
  m_play_matrix_a1 = "0";
  m_play_matrix_a2 = "2";
  m_play_matrix_b1 = "1";
  m_play_matrix_b2 = "3";
  m_play_matrix_rows = rows + 2;
  m_play_matrix_columns = columns + 2;
  m_play_matrix_minimum_row_index = 0;
  m_play_matrix_minimum_column_index = 0;
  m_play_matrix_maximum_row_index = m_play_matrix_rows - 1;
  m_play_matrix_maximum_column_index = m_play_matrix_columns - 1;
  m_string_count = 0;
  m_neighbor_count = 0;
  m_game_count = 0;
  m_game_status = false;
  m_current_generation = "";
}

// Destructor
Game::~Game()
{

}

// Accessors
bool Game::getGameStatus()
{
  return m_game_status;
}

string Game::getCurrentGeneration()
{
  return m_current_generation;
}

// Mutators
void Game::setGameStatus()
{
  // Here the game is determined to be finished if the following conditions hold:
    // 1) Any two successive matrices are the same (statements 1 and 2).
    // 2) Any two matrices that are one apart are the same, indicating oscillation (statements 3 and 4).
    // 3) The generation count exceeds 999 (statement 5).
  if (m_play_matrix_a1 == m_play_matrix_b1 || m_play_matrix_a2 == m_play_matrix_b2 || m_play_matrix_a1 == m_play_matrix_a2 || m_play_matrix_b1 == m_play_matrix_b2 || m_game_count >= 999)
  {
    m_game_status = true;
  }
  else
  {
    m_game_status = false;
  }
}

  // This mutator creates a string that will look like an board when outputted to the user.
void Game::setCurrentGeneration()
{
  m_current_generation = "";
  m_current_generation += "\n";
  m_current_generation += "Generation ";
  m_current_generation += to_string(m_game_count);
  m_current_generation += "\n";
  for (int i = 0; i < m_start_matrix_rows; ++i)
  {
    for (int j = 0; j < m_start_matrix_columns; ++j)
    {
      m_current_generation += m_current_matrix.at(m_string_count);
      ++m_string_count;
    }
    m_current_generation += "\n";
  }
  m_string_count = 0;
}

// Methods
  // Since this is a generic parent class, no implementation is provided.
void Game::Simulation()
{

}
