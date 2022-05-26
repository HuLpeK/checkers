#include <iostream>
#include <vector>
#include "src/board.hpp"
/**
 @file main.cpp
 @details Main file used to initialize game.
 @author Hubert Kulpaczyński
 */


int main() {

    Board x;

    std::cout << x << "\n";
//    system("clr");
    x.at(0,0) = Piece();
    x.at(0,0) = King(BLACK);
    std::cout << x << "\n";
    return 0;
}
