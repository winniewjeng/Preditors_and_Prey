
#ifndef Organism_hpp
#define Organism_hpp
#include <iostream>
using namespace std;

class Organism {

public:
    //big 3: ctor, cpy ctor, assgnmnt oprtr
    Organism() : _face(' ') {}
    Organism(const Organism& other);
    Organism& operator=(const Organism& rhs);
    Organism(int row, int col) : _row(row), _col(col), _face(' ') {}
    virtual void move(int direction) {}
    virtual char get_face() {return _face;}
    virtual int get_row() {return _row;}
    virtual int get_col() {return _col;}
    
private:
    int _row;
    int _col;
    char _face;
};

#endif /* Organism_hpp */
