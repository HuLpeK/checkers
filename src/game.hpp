/**
 * @file game.hpp
 * @author Hubert Kulpaczyński\n Indeks:330840
 * @author Uniwersytet Wrocławki: Instytut Informatyki
 */
#ifndef CHECKERS_GAME_HPP
#define CHECKERS_GAME_HPP

#include "board.hpp"
#include "Participant.hpp"
//! Class that Handles whole game.
class Game {
protected:
    Board board; ///< Board
    Player white; ///< White player.
    Bot black; ///< Black player.

    /**
     * Perform actual move.
     * @param move - Description of move.
     * @param actualColor - Actual player color.
     * @invariant Move is legal.
     * @return True - if it's bicie has been done.
     */
    bool makeMove(std::pair<std::pair<int,int>, std::pair<int,int>> move, COLOR actualColor);
public:
    /**
     * game Starter;
     */
    void Start();

    Game();
};


#endif //CHECKERS_GAME_HPP
