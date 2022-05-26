/**
 * @file pieces.hpp
 * @details Header that defines figures on our Checkers table.
 * @author Hubert Kulpaczyński 330840
 */

#ifndef CHECKERS_PIECES_HPP
#define CHECKERS_PIECES_HPP

#include <string>
#include <vector>
/// enum for having own Color types
enum COLOR {
        WHITE, ///< White Piece
        BLACK, ///< Black Piece
        NONE ///< Blank
};
//! Class that provides template for creating Man and King.

class Pieces {
protected:
    //! Name of Piece
    std::string Name;
    //! Vector of avalible Piece moves
    /*! Implemented as std::vector of std::pairs of X,Y coordinates.*/
    std::vector<std::pair<int,int>> Moves;
    //! Color of Piece
    COLOR Color;
public:
    /**
     * Getter Method
     * @return Name
     */
    virtual std::string getName() ;
    /**
     * Getter Method
     * @return Color of Piece
     */
    virtual COLOR getColor() ;

    /**
     * Getter Method
     * @return std::vector Moves;
     */
    virtual std::vector<std::pair<int,int>>& getMoves();

    /**
     * Constructor that sets Color to NONE.
     */
    Pieces();
    /**
     * Constructor
     * @param x Color to be set
     */
    Pieces(COLOR x);
};

//! Class of Basic Piece
class Man : public Pieces
{
public:
    /**
     * Constructor that sets:\n
     * Name - "Man"\n
     * Moves - {1,-1},{1,1}
     * @param x Color to be set of Man
     */
     Man(COLOR x);
};

//! Best piece in Checkers
class King : public Pieces
{
public:
    /**
     * Constructor that sets\n
     * Name - "King"\n
     * Moves - all diagonals
     * @param x Color to be set of King
     */
    King(COLOR x);
};
#endif //CHECKERS_PIECES_HPP
