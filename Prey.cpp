//
//  Prey.cpp
//  Preditor&Prey
//
//  Created by Winnifer Jeng on 11/21/18.
//  Copyright © 2018 Winnifer Jeng. All rights reserved.
//

#include "Prey.hpp"

void Prey::move(int direction) {
    //        cout << "in preditor move the coord beings: " << this->_row << ", " << this->_col << endl;
    if (direction == 1) {
        _row = _row - 1;
        _col = _col - 1;
        //                cout << "in preditor move the coord ends: " << this->_row << ", " << this->_col << endl;
    }
    if (direction == 2) {
        _row = _row - 1;
        //                cout << "in preditor move the coord ends: " << this->_row << ", " << this->_col << endl;
    }
    if (direction == 3) {
        _row = _row - 1;
        _col = _col + 1;
        //                cout << "in preditor move the coord ends: " << this->_row << ", " << this->_col << endl;
    }
    if (direction == 4) {
        _col = _col - 1;
        //                cout << "in preditor move the coord ends: " << this->_row << ", " << this->_col << endl;
    }
    if (direction == 6) {
        _col = _col + 1;
        //                cout << "in preditor move the coord ends: " << this->_row << ", " << this->_col << endl;
    }
    if (direction == 7) {
        _row = _row + 1;
        _col = _col - 1;
        //                cout << "in preditor move the coord ends: " << this->_row << ", " << this->_col << endl;
    }
    if (direction == 8) {
        _row = _row + 1;
        //                cout << "in preditor move the coord ends: " << this->_row << ", " << this->_col << endl;
    }
    if (direction == 9) {
        _row = _row + 1;
        _col = _col + 1;
        //                cout << "in preditor move the coord ends: " << this->_row << ", " << this->_col << endl;
    }
    if (direction == 0){
        //don't move!
    }
    //    cout << endl;
}

