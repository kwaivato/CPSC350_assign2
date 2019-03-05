// randomConfig.cpp
// An implemented random configuration child class used to randomly set the first array for a Game of Life program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "randomConfig.h"

using namespace std;

// Constructor
  // This constructor has default values in the case that the user does not setMatrixContents().
RandomConfig::RandomConfig()
{
  m_rows = 1;
  m_columns = 1;
  m_population_density = 0.5;
}

// Destructor
RandomConfig::~RandomConfig()
{

}

// Mutators
  // This setMatrixContents mutator is different from the one in fileConfig.h, so comments will be appended as needed.
void RandomConfig::setMatrixContents(int rows, int columns, double population_density)
{
  m_rows = rows;
  m_columns = columns;
  // This if/else structure will be used to handle cases where the user does not input a valid population density (0 < x < 1).
  if (population_density > 0 && population_density <= 1)
  {
    m_population_density = population_density;
  }
  else
  {
    cout << "You did not enter a proper density between 0 and 1! So, I will set the board to be half-full (0.5)." << endl;
    m_population_density = 0.5;
  }

  // Here, I am seeding it in such a way that it is unique for every combination of population density, row, and column numbers.
  srand(static_cast<int>(m_rows*m_columns*m_population_density*100));

  // Using a random-number generator, I will fill out the matrix.
  for (int i = 0; i < m_rows; ++i)
  {
    for (int j = 0; j < m_columns; ++j)
    {
      // The deterministic probability must be computed for every single element in the board, or else every position in the board will
      // be the same.
      m_deterministic_probability = (RAND_MAX - rand())/static_cast<double>(RAND_MAX);
      // The deterministic_probability is used to fill out the board. X is checked first since density is relative to full (not empty) spaces.
      if (m_deterministic_probability < m_population_density)
      {
        m_matrix_contents += 'X';
      }
      else
      {
        m_matrix_contents += '-';
      }
    }
  }
}
