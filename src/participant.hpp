/**
 * @file board.hpp
 * @author Hubert Kulpaczyński\n Indeks:330840
 * @author Uniwersytet Wrocławki: Instytut Informatyki
 */
#ifndef CHECKERS_PARTICIPANT_HPP
#define CHECKERS_PARTICIPANT_HPP


#include <__utility/pair.h>
#include "board.hpp"
//! Virtual template class.
class participant {
protected:
    /**
     * Color of player.
     */
    COLOR playerColor;
public:
    /**
     * Constructor of participant
     * @param x - Color of participant.
     */
    explicit participant(COLOR x);
    /**
     * Getter method.
     * @return Players color.
     */
    COLOR getColor();
    /**
     * Virtual method that defines Piece move\n
     * @invariant Bounds and legality of move is not checked here.
     * @param bo - Board of used Checkers game.
     * @return Pair of defined move {X,Y} -> {X,Y}.
     */
     std::pair<std::pair<int,int>,std::pair<int,int>> makeMove(const Board& bo);
};

//! Player (User)
class Player : public participant
{
    /**
     * Changes char from range: [A-Za-z] to A-Z
     * @param C - char from range [A-za-z]
     * @return - char from range A-Z
     * @return - if C is not from range [A-za-z] return '~'.
     */
    char toUpperCase(char C);
public:
    /**
    * Virtual method that defines Piece move\n
    * @invariant Bounds and legality of move is not checked here.
    * @param bo - Board of used Checkers game.
    * @return Pair of defined move {X,Y} -> {X,Y}.
    */
    std::pair<std::pair<int,int>,std::pair<int,int>> makeMove(const Board& bo);
};

#endif //CHECKERS_PARTICIPANT_HPP
