/**
 * @file board.hpp
 * @author Hubert Kulpaczyński\n Indeks:330840
 * @author Uniwersytet Wrocławki: Instytut Informatyki
 */
#ifndef CHECKERS_PARTICIPANT_HPP
#define CHECKERS_PARTICIPANT_HPP


#include <utility>
#include "board.hpp"
//! Virtual template class.
class Participant {
protected:
    /**
     * Color of player.
     */
    COLOR playerColor;

    const Board& bo;
public:
    /**
     * Constructor of Participant
     * @param x - Color of Participant.
     */
    explicit Participant(COLOR x, Board& bo);
    /**
     * Getter method.
     * @return Players color.
     */
    COLOR getColor();

     /**
     * Virtual method that defines Piece move\n
     * @invariant Bounds and legality of move is not checked here.
     * @return Pair of defined move {X,Y} -> {X,Y}.
     */
     std::pair<std::pair<int, int>, std::pair<int, int>> makeMove();
};

//! Player (User)
class Player : public Participant
{
public:
    /**
     * Changes char from range: [A-Za-z] to A-Z
     * @param C - char from range [A-za-z]
     * @return - char from range A-Z
     * @return - if C is not from range [A-za-z] return '~'.
     */
    static char toUpperCase(char C);
    /**
    * Virtual method that defines Piece move\n
    * @invariant Bounds and legality of move is not checked here.
    * @return Pair of defined move {X,Y} -> {X,Y}.
    */
    std::pair<std::pair<int, int>, std::pair<int, int>> makeMove();

    /**
    * Virtual method that defines Piece move\n
    * @invariant Bounds and legality of move is not checked here.
    * @param oldMove - Old move from which you start new one.
    * @return Pair of defined move {X,Y} -> {X,Y}.
    */
    std::pair<std::pair<int, int>, std::pair<int, int>> makeMove( std::pair<std::pair<int, int>, std::pair<int, int>> oldMove);

        /**
         * Constructor for Player using Participant constructor.
         * @param x Color of player.
         * @param bo  Reference to Board that is taken place.
         */
    explicit Player(COLOR x, Board& bo);

};

#endif //CHECKERS_PARTICIPANT_HPP
