/**
 * @file game.hpp
 * @details Handles checkers game logic.
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
     *@return NONE - if game is not won yet.
     */
    COLOR Win(const Board& bo);
}

#endif //CHECKERS_LOGIC_HPP
