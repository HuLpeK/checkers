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
    Player white; ///< White Player.
    Player black; ///< Black (h3h3) Player.
public:
    /**
     * game Starter;
     */
    void Start();

    Game();
};


#endif //CHECKERS_GAME_HPP
