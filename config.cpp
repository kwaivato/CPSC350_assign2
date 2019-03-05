// config.cpp
// An implemented configuration parent class used to set the first array for a Game of Life program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "config.h"

using namespace std;

// Default constructor
Config::Config()
{

}

// Overloaded constructor
Config::Config(int rows, int columns)
{
  m_rows = rows;
  m_columns = columns;
  m_matrix_contents = "";
}

// Destructor
Config::~Config()
{
}

// Accessors
int Config::getRows()
{
  return m_rows;
}

int Config::getColumns()
{
  return m_columns;
}

string Config::getMatrixContents()
{
  return m_matrix_contents;
}

// Mutators
void Config::setRows(int rows)
{
  m_rows = rows;
}

void Config::setColumns(int columns)
{
  m_columns = columns;
}

void Config::setMatrixContents()
{

}
