// randomConfig.h
// A declared random configuration child class used to randomly set the first array for a Game of Life program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "config.h"

using namespace std;

class RandomConfig : public Config
{
  public:
    // Constructor
    RandomConfig();
    // Destructor
    ~RandomConfig();
    // Mutators
      // This mutator is different from the one declared in config.h because it takes three parameters.
    void setMatrixContents(int rows, int columns, double population_density);
  private:
    // These variables are unique to the randomConfig class, so they are declared to be private.
      // This probability will be computed for each elemnt in the matrix and will be compared to the density to determine
      // if a certain index should have and element or not
    double m_deterministic_probability;
    double m_population_density;
};
