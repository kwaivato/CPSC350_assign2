// menu.h
// A declared menu interface used to facilitate a Game of Life program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "PausePlayStyle.h"
#include "EnterPlayStyle.h"
#include "OutPlayStyle.h"
#include "randomConfig.h"
#include "fileConfig.h"

using namespace std;

class Menu
{
  public:
    // Constructor
    Menu();
    // Destructor
    ~Menu();
    // Methods
      // The Run() method is used to facilitate the menu interface itself. It will take in input and use that input to customize
      // the user experience.
    void Run();
  private:
    // The following strings are used to take in the choices of the user for 1) initial board set-up, 2) game mode, and 3) output style (pause,
    // enter, or out file).
    // m_choice_1 is used to tell whether the user wants to start with a randomly-generated board or with a map file.
    string m_choice_1;
    // m_choice_2 is used to tell whether the user wants to play classic, doughnut, or mirror mode.
    string m_choice_2;
    // m_choice_3 is used to tell whether the user wants the program to pause between output, necessitate an 'enter' between output, or
    // run at normal speed and output results to an out file.
    string m_choice_3;
    // The Config class is used to CONFIGure the initial board for the game. It can do this either randomly or with a map file.
    Config m_config;
    // If the user wants to create an initial board randomly, we will need to know the numbe of rows they want, the number of columns they want, and
    // the board density that they want. That's what these three numbers are used for.
    int m_rows_menu;
    int m_columns_menu;
    double m_random_config_density;
    // If the user wants to import an initial starting board from a map file, we will need to now the file name. That's what this string
    // is used for.
    string m_file_config_file_name;
    // To make things easy, I decided to store a 'matrix' among three variables: 1) a string, 2) the number of rows for the matrix, and 3)
    // the number of columns for the matrix. m_rows_menu and m_columns_menu are used to store the rows and columns, respectively. This variable,
    // m_initial_board_menu, is used to store the contents of the matrix in a string.
    string m_initial_board_menu;
    // The PlayStyle class will be used to customize whether the user wants a pause between output, press enter between output, or have
    // output sent to an out file.
    PlayStyle m_play_style;
    // If the user wants to have their output sent to an out file, we will need to know the intended name of that file (no file extension).
    // That is what this variable is used to store.
    string m_out_play_style_file_name;
};
