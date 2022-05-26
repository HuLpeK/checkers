//
// Created by Hubert Kulpaczyński on 26/05/2022.
//

#ifndef CHECKERS_BOARD_HPP
#define CHECKERS_BOARD_HPP

/**
 * @file board.hpp
 * @author Hubert Kulpaczynski\n Indeks:330840
 * @author Uniwersytet Wrocławki: Instytut Informatyki
 */

#include "pieces.hpp"
#include <iostream>
#define SIZE 8

class Board {
    Piece Square[8][8];
public:
    /**
     * Getter for Square Table
     * @param x first axis
     * @param y second axis
     * @return Reference to Piece of Square[x][y]; \todo Check bounds
     */
    Piece& at(const int x,const  int y);
    const Piece at(const int x, const int y) const;
    /**
     * Constructor for Board
     */
    Board();
    /**
     * Method that shows current state of Board.
     * @param out - stream reference to put Board
     * @param Bo - const reference to Board
     * @return stream with Display of Square
     */
    friend std::ostream& operator<<(std::ostream& out, const Board& Bo);

};


#endif //CHECKERS_BOARD_HPP
