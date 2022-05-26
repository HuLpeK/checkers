#include <iostream>
#include <vector>
#include "src/pieces.hpp"
/**
 @file main.cpp
 @details Main file used to initialize game.
 @author Hubert Kulpaczyński
 */


int main() {

    King x(WHITE);
    std::cout << x.getColor() << "\n";
    auto hlp = x.getMoves();
    for(auto [f,s]: hlp)
        std::cout << "{" << f << "," << s << "},";
    std::cout << "\n" << "♟" << " ";
    return 0;
}
