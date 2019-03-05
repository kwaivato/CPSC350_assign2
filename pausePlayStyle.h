// pausePlayStyle.h
// A declared play style child class used to customize output for a Game of Life program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include <chrono>
#include <thread>
#include "playStyle.h"

using namespace std;

class PausePlayStyle : public PlayStyle
{
  public:
    // Constructors
      // Default
    PausePlayStyle();
      // Overloaded
    PausePlayStyle(string gameChoice, int rows, int columns, string initialBoard);
    // Destructor
    ~PausePlayStyle();
    // Play
    void Play();
};
