
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

void Board::init_preditors() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if(_board[i][j] == nullptr) {
                
            }
        }
    }
}

//output the boardter
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







