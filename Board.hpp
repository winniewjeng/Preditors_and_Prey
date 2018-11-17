
#ifndef Board_hpp
#define Board_hpp
#include <iostream>
#include "Wall.hpp"
#include "Prey.hpp"
#include <cstdlib>
#include <ctime>

const int ROW = 20;
const int COL = 20;

class Organism;

using namespace std;

class Board {
public:
    Board();
    ~Board();
    void move(); //keep track of every organism on the board
    void init_board(); //place all the organisms on board
    void init_walls();
    void init_preys();
    void init_preditors();
    bool is_avaialable(int row, int col);
    char get_face() {return _board_face;}
    int give_direction(int row, int col);
    void print_board();
    
private:
    Organism* _board[ROW][COL];
    char _board_face;
};


#endif /* Board_hpp */
