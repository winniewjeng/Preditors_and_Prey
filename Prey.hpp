//
//  Prey.hpp
//  Preditor&Prey
//
//  Created by Winnifer Jeng on 11/21/18.
//  Copyright © 2018 Winnifer Jeng. All rights reserved.
//

#ifndef Prey_hpp
#define Prey_hpp

#include "Organism.hpp"
#include <vector>
#include <iostream>
using namespace std;
class Organism;

class Prey : public Organism {
public:
    Prey() : _prey_face('o') {}
    Prey(int i, int j) : _row(i), _col(j), _prey_face('o') {}
    // prey move inherits from Organism
    void move(int direction);
    // preditor inherits get_face from Organism
    char get_face() {return _prey_face;}
    int get_row() {return _row;}
    int get_col() {return _col;}
    
private:
    int _row;
    int _col;
    int _prey_face;
};

#endif /* Prey_hpp */
