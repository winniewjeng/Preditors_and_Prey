
#ifndef Organism_hpp
#define Organism_hpp
#include <iostream>

class Organism {

public:
    Organism() : _row(10), _col(10), _face('o') {}
    virtual void move() {}
    virtual char get_face() {return _face;}
    
private:
    int _row;
    int _col;
    char _face;
};

#endif /* Organism_hpp */
