/**
 * @file game.hpp
 * @details Handles game logic.
 * @author Hubert Kulpaczyński\n Indeks:330840
 * @author Uniwersytet Wrocławki: Instytut Informatyki
 */

#ifndef CHECKERS_LOGIC_HPP
#define CHECKERS_LOGIC_HPP

#include "pieces.hpp"
#include "board.hpp"

namespace Logic {
    /**
     * Function that determines if game is Won or not.
     * @param bo - Board of asked game.
     * @return WHITE - if white wins.
     * @return BLACK -if black wins.
     * @return NONE - if game is not won yet.
     */
    COLOR win(const Board &bo);

    /**
     * Checks if performed move is legal
     * @param bo - Board of game.
     * @param move - Move to perform.
     * @param playerColor - Color of player that moves.
     * @invariant Never ask from something out of board.
     * @return True - legal.
     * @return False - not legal.
     */
    bool legalMove(const Board &bo, std::pair<std::pair<int, int>, std::pair<int, int>> &move, COLOR playerColor);

    /**
     * Check if bicie is able to be performed starting on starter tile.
     * @param bo - Board of game.
     * @param playerColor - Color of player that moves.
     * @param starter - if you want to check if it's possible to attack from starter position set it up here.
     * @return if bicie is possible
     */
    bool possibleBicie(const Board &bo, COLOR playerColor, std::pair<int, int> starter);

    /**
    * Check if bicie is able to be performed on whole board.
    * @param bo - Board of game.
    * @param playerColor - Color of player that moves.
    * @return {-1,-1} of bicie is not possible.
    * @return Position of available bicie in any other case.
    */
    std::pair<int, int> possibleBicie(const Board &bo, COLOR playerColor);
}

#endif //CHECKERS_LOGIC_HPP
