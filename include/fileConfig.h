// fileConfig.h
// A declared configuration child class used to set the first array from a map file for a Game of Life program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "config.h"

using namespace std;

class FileConfig : public Config
{
  public:
    // Constructor
    FileConfig();
    // Destructor
    ~FileConfig();
    // Mutators
      // This mutator is different from the one declared in config.h because it takes a string.
    void setMatrixContents(string file_name);
  private:
    // These variables are unique to the fileConfig class, so they are declared to be private.
    string m_file_name;
    ifstream m_input_stream;
    string m_single_line;
    char m_single_char;
};
