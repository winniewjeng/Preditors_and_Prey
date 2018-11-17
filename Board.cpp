
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

//output the board
void Board::print_board() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (_board[i][j] != nullptr) {
                std::cout << _board[i][j]->get_face() << " ";}
            else {
                std::cout << " " << " ";
            }
        }
        std::cout << endl;
    }
    std::cout << endl;
}







