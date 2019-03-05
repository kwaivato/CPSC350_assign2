// classicGame.cpp
// An implemented game child class used to play Game Of Life on Classic mode given an initial board.
// represented by a string and two ints (columns and rows).
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "classicGame.h"

using namespace std;

// Default Constructor
ClassicGame::ClassicGame()
{

}

// Overloaded Constructor
ClassicGame::ClassicGame(int rows, int columns, string initialBoard)
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
ClassicGame::~ClassicGame()
{

}

void ClassicGame::Simulation()
{
  // First, I will form a matrix from the string and two ints I have been given.
  char start_matrix[m_start_matrix_rows][m_start_matrix_columns];

  for (int i = 0; i < m_start_matrix_rows; ++i)
  {
    for (int j = 0; j < m_start_matrix_columns; ++j)
    {
      start_matrix[i][j] = m_current_matrix.at(m_string_count);
      // String count is used here to iterate through the string
      ++m_string_count;
    }
  }
  // String count is set to 0 so I can use it later
  m_string_count = 0;

  // I will now make two matrices - play matrix 1 and play matrix 2. These are both 2 rows and 2 columns bigger than our actual play matrix. This allows us to easily implement the mirror and doughnut
  // game modes.
  char play_matrix_1[m_play_matrix_rows][m_play_matrix_columns];
  char play_matrix_2[m_play_matrix_rows][m_play_matrix_columns];

  // I will fill out play matrix according to the values of the start matrix. Here, I also fill the outer values (I.E. the extra rows and columns on the outside) according to the edges of the starting
  // matrix. Since this is CLASSIC MODE, I wil fill these extra cells as empty.
  for (int i = (m_play_matrix_minimum_row_index); i <= m_play_matrix_maximum_row_index; ++i)
  {
    for (int j = (m_play_matrix_minimum_column_index); j <= m_play_matrix_maximum_column_index; ++j)
    {
      if (i == m_play_matrix_minimum_row_index && j == m_play_matrix_minimum_column_index)
      {
        play_matrix_1[i][j] = '-';
      }
      else if (i == m_play_matrix_maximum_row_index && j == m_play_matrix_minimum_column_index)
      {
        play_matrix_1[i][j] = '-';
      }
      else if (i == m_play_matrix_minimum_row_index && j == m_play_matrix_maximum_column_index)
      {
        play_matrix_1[i][j] = '-';
      }
      else if (i == m_play_matrix_maximum_row_index && j == m_play_matrix_maximum_column_index)
      {
        play_matrix_1[i][j] = '-';
      }
      else if (i == m_play_matrix_minimum_row_index)
      {
        play_matrix_1[i][j] = '-';
      }
      else if (i == m_play_matrix_maximum_row_index)
      {
        play_matrix_1[i][j] = '-';
      }
      else if (j == m_play_matrix_minimum_column_index)
      {
        play_matrix_1[i][j] = '-';
      }
      else if (j == m_play_matrix_maximum_column_index)
      {
        play_matrix_1[i][j] = '-';
      }
      else
      {
        // If it isn't one of the above special cases, then it's a normal inner cell. So I will fill it with it's value in the start matrix.
        play_matrix_1[i][j] = start_matrix[i-1][j-1];
      }
    }
  }

  // I will now fill another matrix (play matrix 2) according to the amount of neighbors for each cell in play matrix 1.
  // I will only fill in the inner values of the matrix (hende i0 + 1 -> iN - 1)
  for (int i = (m_play_matrix_minimum_row_index + 1); i <= (m_play_matrix_maximum_row_index - 1); ++i)
  {
    for (int j = (m_play_matrix_minimum_column_index + 1); j <= (m_play_matrix_maximum_column_index - 1); ++j)
    {
      //This for loop will count the number of neighbors around each cell by iterating through the 3x3 matrix surrounding that cell.
      for (int a = (i-1); a <= (i+1); ++a)
      {
        for (int b = (j-1); b <= (j+1); ++b)
        {
          // We don't want to count the middle cell since this is the value itself, so we will skip it.
          if (a == i && b == j)
          {
            continue;
          }
          else if (play_matrix_1[a][b] == 'X')
          {
            ++m_neighbor_count;
          }
        }
      }
      // Following are the rules of the game.
      if (m_neighbor_count <= 1)
      {
        play_matrix_2[i][j] = '-';
      }
      else if (m_neighbor_count == 2)
      {
        play_matrix_2[i][j] = play_matrix_1[i][j];
      }
      else if (m_neighbor_count == 3)
      {
        play_matrix_2[i][j] = 'X';
      }
      else if (m_neighbor_count >= 4)
      {
        play_matrix_2[i][j] = '-';
      }
      // Count must be reset
      m_neighbor_count = 0;
    }
  }

  // We will now store the values of our new matrix in a string.
  m_current_matrix = "";
  for (int i = (m_play_matrix_minimum_row_index + 1); i <= (m_play_matrix_maximum_row_index - 1); ++i)
  {
    for (int j = (m_play_matrix_minimum_column_index + 1); j <= (m_play_matrix_maximum_column_index - 1); ++j)
    {
      // If it gets here, then it's one of the most innner cells with a value. So we will add it to our string.
      m_current_matrix += play_matrix_2[i][j];
    }
  }

  // We want to know when to end our game (I.E. 2 successive matrices are the same or we have oscillation). Here, a counting technique is used to store the current matrix in 4 separate string.
  // Oscillatory behavior and equality is checked in the setGameStatus() mutator.
  if ((m_game_count%4) == 0)
  {
    m_play_matrix_a1 = m_current_matrix;
  }
  else if ((m_game_count%4) == 1)
  {
    m_play_matrix_b1 = m_current_matrix;
  }
  else if ((m_game_count%4) == 2)
  {
    m_play_matrix_a2 = m_current_matrix;
  }
  else if ((m_game_count%4) == 3)
  {
    m_play_matrix_b2 = m_current_matrix;
  }

  // Game count increases.
  ++m_game_count;
}
