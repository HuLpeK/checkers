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

namespace Logic
{
    /**
     * Function that determines if game is Won or not.
     * @param bo - Board of asked game.
     * @return WHITE - if white wins.
     * @return BLACK -if black wins.
     * @return NONE - if game is not won yet.
     */
     COLOR win(const Board& bo);

     /**
      * Checks if performed move is legal
      * @param bo - Board of game.
      * @param move - Move to perform.
      * @param playerColor - Color of player that moves.
      * @invariant Never ask from something out of board.
      * @return True - legal.
      * @return False - not legal.
      */
     bool legalMove(const Board& bo, std::pair<std::pair<int,int>,std::pair<int,int>>& move, COLOR playerColor);
}

#endif //CHECKERS_LOGIC_HPP
