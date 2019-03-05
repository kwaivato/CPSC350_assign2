// config.h
// A declared configuration parent class used to set the first array for a Game of Life program.
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

#ifndef CONFIG_H
#define CONFIG_H

using namespace std;

class Config
{
  public:
    // Constructors
      // Default
    Config();
      // Overloaded
    Config(int rows, int columns);
    // Destructor
    ~Config();
    // Accessors
    int getRows();
    int getColumns();
    string getMatrixContents();
    // Mutators
    void setRows(int rows);
    void setColumns(int columns);
    void setMatrixContents();
  // The following variables are declared protected (and not private) so that the subclasses (Random and File) can easily modify them.
  protected:
    int m_rows;
    int m_columns;
    string m_matrix_contents;
};

#endif
