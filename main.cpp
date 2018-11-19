
#include "Board.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    
    Board b;
    b.init_board();
//    b.print_board();
    
    string play = "\n";
    while (play != "Q") {
        b.print_board();
        getline(cin, play);
        b.move();
    }
    
    
    cout << "bye";
//    for (int i = 0; i < 55; i++){
//        int rand();
//        cout << rand() % (ROW - 1 ) + 1 << endl;}
    return 0;
}



