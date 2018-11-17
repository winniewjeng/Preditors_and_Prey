
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
    //count and increment move every time it's called (breed)
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            // move all the preditors
            //...code goes here
            if(_board[i][j] != nullptr) {
                char type = _board[i][j]->get_face();
                if(type =='o') {
                    //take 'S' as center, notations Q-W-E-A-S-D-Z-X-C represent 1-2-3-4-0-6-7-8-9
                    cout << "oh\n";
                    int direction = give_direction(i, j);
                    //move or stay
                    // store current position in temp
                    Organism* temp = _board[i][j];
                    temp->move(direction);
                    //                    _board[i][j] = nullptr;
                }
                
            }
            // move all the preys
        }
    }
}

// place all organisms on the board: walls, preditors, preys
void Board::init_board() {
    init_walls();
    cout << "init preys\n";
    init_preys();
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
    cout << "init preys\n";
    //depending on the board size, generate N number of preys
    int prey_nums;
    if (ROW * COL / 10 < 4) {
        prey_nums = 1;
    } else {
        prey_nums = ROW * COL / 10 + 1;
    }
    
    //seeding a random number
    srand(static_cast<unsigned int>(time(0)));
    
    // place N number of preys randomly on the board
    for (int i = 0; i < prey_nums; i++) {
        int row, col;
        do {
            row = rand() % (ROW - 1 ) + 1; // generate a random number i between 1 and ROW - 1
            col = rand() % (COL - 1 ) + 1; // and a number j between 1 and COL - 1
        } while(!is_avaialable(row, col)); // If i, j occupied, generate new set of i and j
        // place the prey on board
        _board[row][col] = new Prey(row, col);
    }
}

//NOT YET IMPLEMENTED
// randomly initialize n number of preditors
void Board::init_preditors() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if(_board[i][j] == nullptr) {
            }
        }
    }
}

bool Board::is_avaialable(int row, int col) {
    return _board[row][col] == nullptr;
}

//determine which direction the organism can move
//take 'S' as center, notations Q-W-E-A-S-D-Z-X-C represent 1-2-3-4-0-6-7-8-9
int Board::give_direction(int row, int col) {
    int count = 0;
    vector<int> v;
    //check if any of the four direction is free. If free, pop its number into vector
    if (_board[row-1][col-1] == nullptr) {
        v.push_back(1);
        count++;
    } else if (_board[row-1][col] == nullptr) {
        v.push_back(2);
        count++;
    } else if (_board[row-1][col+1] == nullptr) {
        v.push_back(3);
        count++;
    } else if (_board[row][col-1] == nullptr) {
        v.push_back(4);
        count++;
    } else if (_board[row][col+1] == nullptr) {
        v.push_back(6); //skip 5 because 5 is the current position, accounted as unmove
        count++;
    } else if (_board[row+1][col-1] == nullptr) {
        v.push_back(7);
        count++;
    } else if (_board[row+1][col] == nullptr) {
        v.push_back(8);
        count++;
    } else if (_board[row+1][col+1] == nullptr){
        v.push_back(9);
        count++;
    }
    // cannot move
    if (count == 0) {
        return 0;
    }
    
    //seeding a random number between 0 - count to pick a random vector slot
    srand(static_cast<unsigned int>(time(0)));
    int random = rand() % count;
    for (int i = 0; i < random; i++) {
        v.pop_back();
    }
    return v.front();
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
    cout << endl;
}







