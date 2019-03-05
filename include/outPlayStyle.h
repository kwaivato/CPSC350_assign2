// outPlayStyle.h
// A declared play style child class used to customize output for a Game of Life program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "playStyle.h"

using namespace std;

class OutPlayStyle : public PlayStyle
{
  public:
    // Constructors
      // Default
    OutPlayStyle();
      // Oveloaded
    OutPlayStyle(string gameChoice, int rows, int columns, string initialBoard, string fileName);
    // Destructor
    ~OutPlayStyle();
    // Methods
    void Play();
  // The following variables are unique to the outPlayStyle, so they are declared private.
  private:
    string m_file_name_play_style;
    ofstream m_out_stream;
};
