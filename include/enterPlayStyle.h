// enterPlayStyle.h
// A declared play style child class used to customize output for a Game of Life program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "playStyle.h"

using namespace std;

class EnterPlayStyle : public PlayStyle
{
  public:
    //Constuctors
    EnterPlayStyle();
    EnterPlayStyle(string gameChoice, int rows, int columns, string initialBoard);
    //Destructor
    ~EnterPlayStyle();
    //Play Method
    void Play();
};
