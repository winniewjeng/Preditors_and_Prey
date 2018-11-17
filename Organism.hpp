
#ifndef Organism_hpp
#define Organism_hpp
#include <iostream>

class Organism {

public:
    Organism() : _row(10), _col(10), _generic_face('?') {}
    virtual void move(int direction) {}
    virtual char get_face() {return _generic_face;}
    
private:
    int _row;
    int _col;
    char _generic_face;
};

#endif /* Organism_hpp */
