/**
 * @file game.hpp
 * @author Hubert Kulpaczyński\n Indeks:330840
 * @author Uniwersytet Wrocławki: Instytut Informatyki
 */
#ifndef CHECKERS_GAME_HPP
#define CHECKERS_GAME_HPP

#include "board.hpp"
#include "Participant.hpp"
#include <memory>

//! Class that Handles whole game.
class Game {
protected:
    Board board; ///< Board
    std::unique_ptr<Participant> white; ///< White player.
    std::unique_ptr<Participant> black; ///< Black player.

    /**
     * Perform actual move.
     * @param move - Description of move.
     * @param actualColor - Actual player color.
     * @invariant Move is legal.
     * @return True - if it's bicie has been done.
     */
    bool makeMove(std::pair<std::pair<int, int>, std::pair<int, int>> move, COLOR actualColor);

public:
    /**
     * game Starter;
     */
    void Start();

    Game()=delete;
    /**
     * Construcot of game.
     * @param wh - who do you want to take Whites PLace? "Bot" or a "Player".
     * @param bl - who do you want to take Black PLace? "Bot" or a "Player".
     */
    Game(const std::string& wh,  const std::string& bl);
};


#endif //CHECKERS_GAME_HPP
