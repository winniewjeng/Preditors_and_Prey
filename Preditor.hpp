//preditor inherits from the organism class
//the rule for preditor: start out with preys / 4 number of preditors
//with every turn of the game, 1) look for prey to devour or 2) move to an empty space
//every 3 turns, if not eaten anything, die
#ifndef Preditor_hpp
#define Preditor_hpp
#include "Organism.hpp"
//#include <vector>
#include <iostream>
using namespace std;
class Organism;

class Preditor : public Organism {
public:
    Preditor() : _preditor_face('X') {}
    Preditor(int i, int j) : _row(i), _col(j), _preditor_face('X') {}
    // preditor move inherits from Organism
    void move(int direction) {}
    // preditor inherits get_face from Organism
    char get_face() {return _preditor_face;}
    int get_row() {return _row;}
    int get_col() {return _col;}
    
private:
    int _row;
    int _col;
    int _preditor_face;
};

#endif /* Preditor_hpp */
