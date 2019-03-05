// game.h
// A declared game parent class used to play Game Of Life given an initial board.
// represented by a string and two ints (columns and rows).
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#ifndef GAME_H
#define GAME_H

class Game{
  public:
    // Constructors
      // Default
    Game();
      // Overloaded
    Game(int rows, int columns, string initialBoard);
    ~Game();
    // Accessors
    bool getGameStatus();
    string getCurrentGeneration();
    // Mutators
    void setGameStatus();
    void setCurrentGeneration();
    // Methods
    void Simulation();
  // Similar to the Config class, these variables are protected so that they're easier to access by child classes.
  protected:
    // The current matrix that we will want to print out and/or we're playing with
    string m_current_matrix;
    // Everything needed for the starting matrix (rows x columns).
    int m_start_matrix_rows;
    int m_start_matrix_columns;
      // The minimum and maximum indices (for i and j) will be used for iterations and element retrieval.
    int m_start_matrix_minimum_row_index;
    int m_start_matrix_minimum_column_index;
    int m_start_matrix_maximum_row_index;
    int m_start_matrix_maximum_column_index;
    // Everything needed for the play matrix ((rows + 2) x (columns x 2))
      // These four strings will be used to tell when the program has ended. We need four separate ones to handle oscillations.
    string m_play_matrix_a1;
    string m_play_matrix_a2;
    string m_play_matrix_b1;
    string m_play_matrix_b2;
    int m_play_matrix_rows;
    int m_play_matrix_columns;
      // The minimum and maximum indices (for i and j) will be used for iterations and element retrieval.
    int m_play_matrix_minimum_row_index;
    int m_play_matrix_minimum_column_index;
    int m_play_matrix_maximum_row_index;
    int m_play_matrix_maximum_column_index;
    // This int will make string-matrix transfers very easy.
    int m_string_count;
    // This int is needed to keep track of how many neighbors there are for each cell.
    int m_neighbor_count;
    // This int will keep track of game number.
    int m_game_count;
    // This bool will be used to tell if my game is finished.
    bool m_game_status;
    // This string is used to output results and also make it easy to write them to a file.
    string m_current_generation;
};

#endif
