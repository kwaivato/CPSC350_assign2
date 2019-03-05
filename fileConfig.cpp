// fileConfig.cpp
// An implemented configuration child class used to set the first array from a map file for a Game of Life program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "fileConfig.h"

using namespace std;

// Constructor
FileConfig::FileConfig()
{

}

// Destructor
FileConfig::~FileConfig()
{
}

// Mutators
  // This mutator will set the matrix contents based on what the file contains.
void FileConfig::setMatrixContents(string file_name)
{
  m_input_stream.open(file_name);
  // First, we will check that the file can be opened. If it cannot, we will continue prompting the user until we get a file that works.
  while (m_input_stream.fail())
  {
    cout << "File does not exist!" << endl;
    cout << "Give me the name of a new file: ";
    cin >> file_name;
    m_input_stream.open(file_name);
  }
  // This program assumes that the user will give us a file that is structured as a map file. Running with this assumption, the first
  // two rows will have the number of rows and columns, respectively.
  m_input_stream >> m_rows >> m_columns;
  // After getting the number of rows and columns, we will read through the rest of the file to get the values contained in the matrix.
  // Thes values will be stored in a string.
  while (getline(m_input_stream,m_single_line))
  {
    for (int i = 0; i < m_single_line.size(); ++ i)
    {
      // The to-upper function is used to safeguard against any low-cap X's.
      if (toupper(m_single_line.at(i)) == 'X')
      {
        m_matrix_contents += 'X';
      }
      // This program assumes that empty matrix spaces will be notated with '-'.
      else if (m_single_line.at(i) == '-')
      {
        m_matrix_contents += '-';
      }
    }
  }
  m_input_stream.close();
}
