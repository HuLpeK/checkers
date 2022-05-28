/**
 * @file pieces.hpp
 * @details Header that defines figures on our Checkers table.
 * @author Hubert Kulpaczynski\n Indeks:330840
 * @author Uniwersytet Wrocławki: Instytut Informatyki
 */
//todo names to convetion
#ifndef CHECKERS_PIECES_HPP
#define CHECKERS_PIECES_HPP

#include <string>
#include <vector>
/// enum for having own Color types
enum COLOR {
        NONE, ///< Blank
        WHITE, ///< White Piece
        BLACK ///< Black Piece

};
//! Class that provides template for creating Man and King.

class Piece {
protected:
    //! Name of Piece
    std::string Name;
    std::string Icon;
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
    virtual std::string getName() const;
    /**
     * Getter Method
     * @return Color of Piece
     */
    virtual COLOR getColor() const;

    /**
     * Getter Method
     * @return std::vector Moves;
     */
    virtual std::vector<std::pair<int, int>> getMoves() const;
    /**
     * Getter method
     * @return Icon of Piece
     */
    virtual std::string getIcon() const;

    /**
     * Constructor that sets Color to NONE.
     */
    Piece();
    /**
     * Constructor
     * @param x Color to be set
     */
    Piece(COLOR x);
};

//! Class of Basic Piece
class Man : public Piece
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
class King : public Piece
{
public:
    /**
     * Constructor that sets\n
     * Name - "King"\n
     * Moves - all diagonals
     * @param x Color to be set of King
     */
    explicit King(COLOR x);
};
#endif //CHECKERS_PIECES_HPP
