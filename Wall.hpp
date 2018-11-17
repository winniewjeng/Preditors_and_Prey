
#ifndef Wall_hpp
#define Wall_hpp
#include "Organism.hpp"
using namespace std;
// The wall does not move
class Organism;

class Wall : public Organism {
public:
    Wall(int i, int j) : _row(i), _col(j), _face('*') {}
    // wall does not move
    void move() {}
    char get_face() {return _face;}
private:
    int _row;
    int _col;
    char _face;
};

#endif /* Wall_hpp */
