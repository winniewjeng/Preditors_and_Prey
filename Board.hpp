
#ifndef Board_hpp
#define Board_hpp
#include <iostream>
#include "Wall.hpp"

const int ROW = 7;
const int COL = 7;

class Organism;

//using namespace std;

class Board {
public:
    Board();
    ~Board();
    void move(); //keep track of every organism on the board
    void print_board();
    void init_board(); //place all the organisms on board
    void init_walls();
    void init_preditors();
    char get_face() {return _board_face;}
    
private:
    Organism* _board[ROW][COL];
    char _board_face;
};


#endif /* Board_hpp */
