// main.cpp
// A main program used to run a public interface of the Game Of Life program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "Menu.h"
#include <string>
#include <iostream>

using namespace std;

// Main method for the entire program.
int main(int argc, char** argv)
{
  Menu gol;
  gol.Run();
  return 0;
}

//Help
  //Class re-definition: Absolute C++, pg. 483
  //Pressing enter for each round: https://stackoverflow.com/questions/42818899/detecting-enter-key-in-c
  //Timed delay: https://stackoverflow.com/questions/158585/how-do-you-add-a-timed-delay-to-a-c-program
