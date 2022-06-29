#include <iostream>
#include <exception>
#include "src/game.hpp"
/**
 @file main.cpp
 @details Main file used to initialize game.
 @author Hubert Kulpaczyński
 */

bool checkInput(const std::string word)
{
    return word == "BOT" or word == "PLAYER";
}

/**
 * Main Function that turns on the game!
 * @return 0
 */
int main(int argc, char* argv[]) {

    if(argc < 3)
        throw std::invalid_argument("You've put to small number of arguments!\nLook into README.md!\n");

    if(not checkInput(argv[1]) or not checkInput(argv[2]))
        throw std::invalid_argument("You've put to a wrong input into arguments!\nLook into README.md!\n");

    Game x(argv[1],argv[2]);
    x.Start();

}
