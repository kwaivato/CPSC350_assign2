// menu.cpp
// An implemented menu interface used to facilitate a Game of Life program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "menu.h"

using namespace std;

// Default Constructor
  // Since all variables will eventually have definitive values, there is no need to initialize any in the constructor.
Menu::Menu()
{
}

// Destructor
Menu::~Menu()
{
}

//Method(s)
  // The Run() method implements the inferface for the user. Comments will be ammended where necessary.
void Menu::Run()
{
  cout << "Welcome to the Game of Life!" << endl;
  cout << "Note: All input is cap-sensitive." << endl;

  // The user will first be prompted for choice 1.
  cout << "Firstly, would you like to set your board with a random simulator, or with a map file?" << endl;
  // The while-loop is used to ensure that the user provides a valid choice 1 (F or R)
  while (!(m_choice_1 == "F" || m_choice_1 == "R"))
  {
    cout << "Type in 'R' for random and 'F' for file: " << endl;
    cin >> m_choice_1;
    if (m_choice_1 == "R")
    {
      cout << "Looks like you wanna play random!" << endl;
      cout << "How many rows do you want for your game: ";
      cin >> m_rows_menu;
      cout << "How many columns do you want for your game: ";
      cin >> m_columns_menu;
      cout << "What would you like the board density to be for your game? It must be a decimal between 0 and 1: ";
      cin >> m_random_config_density;
      // The Config class has both FileConfig and RandomConfig child classes. Here the base object m_config is declared to be RandomConfig so that
      // the contents of m_config can be set according to random chance.
      RandomConfig m_config;
      m_config.setMatrixContents(m_rows_menu, m_columns_menu, m_random_config_density);
      // The Config class creates a string representing the characters in the matrix. Here, we retrieve the string.
      m_initial_board_menu = m_config.getMatrixContents();
    }
    else if (m_choice_1 == "F")
    {
      cout << "Looks like you wanna play file!" << endl;
      cout << "What is the name of the map file you would like us to read from?: " << endl;
      cin >> m_file_config_file_name;
      // Here the base object m_config is declared to be FileConfig so that the contents of m_config can be set according to a file.
      FileConfig m_config;
      m_config.setMatrixContents(m_file_config_file_name);
      // Since the user did not enter the number of rows or columns, we must obtain them manually.
      m_rows_menu = m_config.getRows();
      m_columns_menu = m_config.getColumns();
      // The Config class creates a string representing the characters in the matrix. Here, we retrieve the string.
      m_initial_board_menu = m_config.getMatrixContents();
    }
    else
    {
      cout << "Invalid input! Try again." << endl;
    }
  }

  // The user will be prompted for the second choice (game mode).
  cout << "Now, let's decide to play the game in classic mode, doughnut mode, or mirror mode." << endl;
  // Similar to choice 1, a while loop is used to ensure that the user enters a valid input for game choice.
  while (!(m_choice_2 == "C" || m_choice_2 == "D" || m_choice_2 == "M"))
  {
    cout << "Type in 'C' for classic, 'D' for doughnut, or 'M' for mirror: " << endl;
    cin >> m_choice_2;
    if (m_choice_2 == "C")
    {
      cout << "Looks like you wanna play classic!" << endl;
    }
    else if (m_choice_2 == "D")
    {
      cout << "Looks like you wanna play doughnut!" << endl;
    }
    else if (m_choice_2 == "M")
    {
      cout << "Looks like you wanna play mirror!" << endl;
    }
    else
    {
      cout << "Invalid input! Try again." << endl;
    }
  }

  // Here, the user is prompted for the final choice: how they want program output to be formatted.
  cout << "Finally, please let me know how you would like to play the game." << endl;
  // Similar to choices 1 and 2, the while loop will ensure that the user enters valid input for choice 3.
  while (!(m_choice_3 == "P" || m_choice_3 == "E" || m_choice_3 == "O"))
  {
    cout << "Enter 'P' for pausing between output, 'E' if you want to press enter to see output, or 'O' if you want it in an output file: " << endl;
    cin >> m_choice_3;
    // In this part of menu, another class (PlayStyle) will be declared to be one of its sub-classes (PausePlayStyle, EnterPlayStyle, or
    // OutPlayStyle). These sub-classes implement what we want in terms of program length and output style. Below, these object m_play_style
    // is declared to be one of its sub-classes and then it uses the Play() method to carry out the Game of Life simulation given an initial
    // board represented by a string, the number of rows, and the number of columns.
    if (m_choice_3 == "P")
    {
      cout << "Looks like you wanna play pause!" << endl;
      PausePlayStyle m_play_style(m_choice_2, m_rows_menu, m_columns_menu, m_initial_board_menu);
      m_play_style.Play();
    }
    else if (m_choice_3 == "E")
    {
      cout << "Looks like you wanna play enter!" << endl;
      EnterPlayStyle m_play_style(m_choice_2, m_rows_menu, m_columns_menu, m_initial_board_menu);
      m_play_style.Play();
    }
    else if (m_choice_3 == "O")
    {
      cout << "Looks like you wanna play output!" << endl;
      cout << "What would you like your output file name to be? Do not add a file extension." << endl;
      cin >> m_out_play_style_file_name;
      OutPlayStyle m_play_style(m_choice_2, m_rows_menu, m_columns_menu, m_initial_board_menu, m_out_play_style_file_name);
      m_play_style.Play();
    }
    else
    {
      cout << "Invalid input! Try again." << endl;
    }
  }
  // To be polite, we give our warmest salutations to the user.
  cout << "Thank you for playing The Game of Life, we hope to play again with you soon! :-)" << endl;
}
