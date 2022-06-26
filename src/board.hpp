/**
 * @file board.hpp
 * @author Hubert Kulpaczyński\n Indeks:330840
 * @author Uniwersytet Wrocławki: Instytut Informatyki
 */
#ifndef CHECKERS_BOARD_HPP
#define CHECKERS_BOARD_HPP

#include "pieces.hpp"
#include <iostream>
/**
 * Size of the board
 */
#define SIZE 8

//! Checkers Board
class Board {
    Piece Square[SIZE][SIZE];
public:
    /**
     * Getter for Square Table
     * @param x Row Index {A,B...H}.
     * @param y Column Index {1,2,3...8}.
     * @return Reference to Piece of Square[x][y];
     * @return if asking out of bounds return Piece.
     */
    Piece &at(int x, int y);

    /**
     * Getter for Square Table
     * @param x Row Index {A,B...H}.
     * @param y Column Index {1,2,3...8}.
     * @return Reference to Piece of Square[x][y].
     * @return if asking out of bounds return Piece.
     */
    Piece at(int x, int y) const;

    /**
     * Constructor for Board
     */
    Board();

    /**
     * Method that shows current state of Board.
     * @param out - stream reference to put Board.
     * @param Bo - const reference to Board.
     * @return stream with Display of Square.
     */
    friend std::ostream &operator<<(std::ostream &out, const Board &Bo);

};


#endif //CHECKERS_BOARD_HPP
