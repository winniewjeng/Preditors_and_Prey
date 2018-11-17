
#ifndef Wall_hpp
#define Wall_hpp
#include "Organism.hpp"
using namespace std;
// The wall does not move
class Organism;

class Wall : public Organism {
public:
    Wall(int i, int j) : _row(i), _col(j), _wall_face('*') {}
    // wall does not move, but inherits move() from Organism. 0 means not moving
    void move(int direction = 0) {}
    // wall inherits get_face from Organism
    char get_face() {return _wall_face;}
private:
    int _row;
    int _col;
    char _wall_face;
};

#endif /* Wall_hpp */
