
#ifndef Board_hpp
#define Board_hpp
#include <iostream>
#include "Wall.hpp"
#include "Prey.hpp"
#include "Preditor.hpp"
#include <cstdlib>
#include <ctime>

const int ROW = 22;
const int COL = 22;

class Organism;

using namespace std;

class Board {
public:
    Board();
    ~Board();
    void move(); //keep track of every organism movement on board
    void swap_spots(vector<Organism*> v, int i, int j); //ptrs manipulation
    void breed(); //double the preys every 3 generations
    void init_board(); //init board & place all the organisms on board
    void init_nulls();
    void init_walls();
    void init_preys();
    void breed_prey(int _num_preys);
    void init_preditors();
    bool is_avaialable(int row, int col);
    char get_face() {return _board_face;}
    int give_direction(int row, int col);
    vector<int> possible_prey_directions(int row, int col);
    vector<int> possible_preditor_directions(int row, int col);
    void print_board();
    int get_random(int count);
//    void store_flag(int i, int j);
    vector<Organism*> i_moved(Organism* me); //container for all the moved pieces
    bool has_moved(Organism* o, vector<Organism*>& v); //if Organism has moved, don't move
    bool has_empty(); // if there is empty space on board, then return true
    
private:
    Organism* _board[ROW][COL];
    char _board_face;
    int _num_preys; //number of preys
    int _num_preditors; //not used
    int _generation;
};


#endif /* Board_hpp */
