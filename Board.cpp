#include "Board.hpp"

Board::Board() {
    _board_face = 'O';
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            _board[i][j] = nullptr;
        }
    }
}

Board::~Board() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            delete _board[i][j];
        }
    }
}

//move all the pieces of the board besides the wall
void Board::move() {
    //vector keeping track of & preveting double move within one move cycle
    vector<Organism*> v_double_move;
    
    // move all the preditors
    for (int i = 1; i < ROW - 1; i++) {
        for (int j = 1; j < COL - 1; j++) {
            if (!has_moved(_board[i][j], v_double_move)) {
                // move all the preditors
                if (_board[i][j]->get_face() == 'X') {
                    //take care of preditor ptr movement
                    swap_spots(v_double_move, i, j);
                }
                // move all the preys
                else if(_board[i][j]->get_face() == 'o') {
                    //take care of prey ptr movement
                    swap_spots(v_double_move, i, j);
                    // breed
                    if (_generation % 2 == 0 && _generation != 0) {
                        breed_prey(1);
                    }
                }
            }
        }
    }
    
    cout << "Generation "<< _generation << endl;
    // increment the generation count
    _generation++;
    if (_generation % 3 == 0) {
        //breed preys & kill preditor
        
    }
    
}

//potentially erroneous
void Board::swap_spots(vector<Organism*> v, int i, int j) {
    //take 'S' as center, notations Q-W-E-A-S-D-Z-X-C represent 1-2-3-4-0-6-7-8-9
    int direction = give_direction(i, j);
    //move or stay: store current position in temp
    //cpying preditor's junk to the temp variable
    Organism* temp(_board[i][j]);
    //cout << "row: " << temp->get_row() << ", col: " << temp->get_col() << endl; //testing purpose
    //move preditor's junk over to a new position
    temp->move(direction);
    //cout << "row: " << temp->get_row() << ", col: " << temp->get_col() << endl; //testing purpose
    //house keeping and cleaning the old position
    _board[i][j]= nullptr; //free the position of old ptr
    _board[i][j] = new Organism(i, j); //replace position with a new blank ptr
    //the new position gets the preditor junk of the old position
    _board[temp->get_row()][temp->get_col()] = nullptr;
    _board[temp->get_row()][temp->get_col()] = temp; //update the new position with the new prey ptr occupant
    //push the moved Organism into vector to prevent double move
    //store the new position in vector to prevent double move
    v = i_moved(_board[temp->get_row()][temp->get_col()]);
    //clear temp junk
    //    delete temp;
    temp = nullptr; //free temp ptr
    
}

// place all organisms on the board: walls, preditors, preys
void Board::init_board() {
    init_nulls();
    init_walls();
    init_preys();
    init_preditors();
}

void Board::init_nulls() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            _board[i][j] = new Organism(i, j);
        }
    }
}

// construct the wall of the gameboard
void Board::init_walls() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == 0 || i + 1 == ROW || j == 0 || j + 1 == COL) {
                _board[i][j] = new Wall(i, j);
            }
        }
    }
}

// initialize N number of preys to fill the Board
void Board::init_preys() {
    //depending on the board size, generate N number of preys
    //    int prey_nums;
    int num_preys;
    if (ROW * COL / 10 < 40) {
        num_preys = 1;
    } else {
        //_num_preys = 1; //for testing purpose
        num_preys = 20;
    }
    
    // place N number of preys randomly on the board
    for (int i = 0; i < num_preys; i++) {
        //breed "_num_preys" number of preys
        breed_prey(num_preys);
    }
}

// if there is empty space on board, then return true
bool Board::board_has_empty() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (_board[i][j]->get_face() != ' ') {
                return true;
            }
        }
    }
    return false;
}
// if board has avaialable space then breed, if not then don't
void Board::breed_prey(int num_preys) {
    
    //seeding a random number
    srand(static_cast<unsigned int>(time(0)));
    
    int row, col;
    // this loop breaks
    
    // generate a random number i between 1 and ROW - 1
    // and a number j between 1 and COL - 1
    for (int i = 0; i < num_preys; i++) {
        row = rand() % (ROW - 1) + 1;
        col = rand() % (COL - 1) + 1;
        
        if (is_avaialable(row, col)) {
            _board[row][col] = new Prey(row, col);
        } else if (board_has_empty()) {
            cout << "boop" << endl;
//            while (!is_avaialable(row, col)) {
//                row = rand() % (ROW - 1) + 1;
//                col = rand() % (COL - 1) + 1;
//            }
//            _board[row][col] = new Prey(row, col);
        }
    }
    
}

// randomly initialize n number of preditors
void Board::init_preditors() {
    if (_num_preys < 8) {
        _num_preditors = 1;
    } else if (_num_preys >= 8 && _num_preys < 50 ) {
        _num_preditors = 3;
    } else {
        _num_preditors = _num_preys / 10;
    }
    
    for (int i = 0; i < _num_preditors; i++) {
        int row, col;
        int try_direction = 0;
        do {
            
            // generate a random number i between 1 and ROW - 1
            row = rand() % (ROW - 1 ) + 1;
            // and a number j between 1 and COL - 1
            col = rand() % (COL - 1 ) + 1;
            try_direction++;
        } while(!is_avaialable(row, col) || try_direction <= 8); // If i, j occupied, get new set
        
        if (is_avaialable(row, col)) {
            // place the prey on board
            _board[row][col] = new Preditor(row, col);
        }
    }
}

bool Board::is_avaialable(int row, int col) {
    return _board[row][col]->get_face() == ' ';
}

//determine which direction the organism can move take 'S' as center,
// notations Q-W-E-A-S-D-Z-X-C represent positions 1-2-3-4-0-6-7-8-9
int Board::give_direction(int row, int col) {
    
    vector<int> v;
    
    if (_board[row][col]->get_face() == 'X') {
        v = possible_preditor_directions(row, col);
    } else {
        v = possible_prey_directions(row, col);
    }
    // if cannot move, do not move, return 0
    if (v.empty()) {
        return 0;
    }
    //count keeps track of the number of possible move directions
    int count = static_cast<unsigned int>(v.size());
    //random generate a random position number of the vector
    int random = get_random(count);
    
    for (int i = 0; i < random; i++) {
        v.pop_back();
    }
    //cout << "give_direction: "<< v.back() << endl;
    return v.back();
}

//store all possible preditor move positions inside a vector
vector<int> Board::possible_preditor_directions(int row, int col) {
    //if any of the 8 directions is free, pop its number into vector
    vector<int> v;
    if (_board[row-1][col-1]->get_face() == ' ' ||
        _board[row-1][col-1]->get_face() == 'o') {
        v.push_back(1);
    }
    if (_board[row-1][col]->get_face() == ' ' ||
        _board[row-1][col]->get_face() == 'o') {
        v.push_back(2);
    }
    if (_board[row-1][col+1]->get_face() == ' ' ||
        _board[row-1][col+1]->get_face() == 'o') {
        v.push_back(3);
    }
    if (_board[row][col-1]->get_face() == ' ' ||
        _board[row][col-1]->get_face() == 'o') {
        v.push_back(4);
    }
    //skip 5 because 5 is the current position, accounted as unmove
    if (_board[row][col+1]->get_face() == ' ' ||
        _board[row][col+1]->get_face() == 'o') {
        v.push_back(6);
    }
    if (_board[row+1][col-1]->get_face() == ' ' ||
        _board[row+1][col-1]->get_face() == 'o') {
        v.push_back(7);
    }
    if (_board[row+1][col]->get_face() == ' ' ||
        _board[row+1][col]->get_face() == 'o') {
        v.push_back(8);
    }
    if (_board[row+1][col+1]->get_face() == ' ' ||
        _board[row+1][col+1]->get_face() == 'o'){
        v.push_back(9);
    }
    // testing purpose: print out the possible directions vector
    //    for (int i = 0; i < v.size(); i++) {
    //        cout << v.data()[i] << " ";
    //    }
    //    cout << endl;
    return v;
}

//store all possible prey move positions inside a vector
vector<int> Board::possible_prey_directions(int row, int col) {
    //if any of the 8 directions is free, pop its number into vector
    vector<int> v;
    if (_board[row-1][col-1]->get_face() == ' ') {
        v.push_back(1);
    }
    if (_board[row-1][col]->get_face() == ' ') {
        v.push_back(2);
    }
    if (_board[row-1][col+1]->get_face() == ' ') {
        v.push_back(3);
    }
    if (_board[row][col-1]->get_face() == ' ') {
        v.push_back(4);
    }
    //skip 5 because 5 is the current position, accounted as unmove
    if (_board[row][col+1]->get_face() == ' ') {
        v.push_back(6);
    }
    if (_board[row+1][col-1]->get_face() == ' ') {
        v.push_back(7);
    }
    if (_board[row+1][col]->get_face() == ' ') {
        v.push_back(8);
    }
    if (_board[row+1][col+1]->get_face() == ' '){
        v.push_back(9);
    }
    // testing purpose: print out the possible directions vector
    //    for (int i = 0; i < v.size(); i++) {
    //        cout << v.data()[i] << " ";
    //    }
    //    cout << endl;
    return v;
}

// get a random number within the range 0 to count
int Board::get_random(int count) {
    //    srand(static_cast<unsigned int>(time(0)));
    return rand() % (count); //////////-1? +1?
}

//output the board
void Board::print_board() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (_board[i][j] != nullptr) {
                cout << _board[i][j]->get_face() << " ";}
            else {
                cout << " " << " ";
            }
        }
        cout << endl;
    }
}

//vector container storing an Organism if its coordinate
// has been updated within one life cycle (one loop through the entire Board)
vector<Organism*> Board::i_moved(Organism* me) {
    vector<Organism*> v;
    v.push_back(me);
    return v;
}

//tells if an Organism has moved within one life cycle
// (one loop through the entire Board)
bool Board::has_moved(Organism* organism, vector<Organism*>& v) {
    for (int i = 0; i < v.size(); i++) {
        if (organism == v.at(i)) {
            v.clear();
            return true;
        }
    }
    return false;
}

