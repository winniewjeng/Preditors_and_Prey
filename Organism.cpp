
#include "Organism.hpp"

Organism::Organism(const Organism& other) {
    _row = other._row;
    _col = other._col;
    _face = other._face;
}

Organism& Organism::operator=(const Organism& rhs) {
    //self-check
    if (this == &rhs) {
        return *this;
    }
    //clean up the lhs
    
    //instantiate all the attributes of lhs again
    _row = rhs._row;
    _col = rhs._col;
    _face = rhs._face; //allocate space for the lhs
    
    return *this;
}

