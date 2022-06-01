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
class Participant {
protected:
    /**
     * Color of player.
     */
    COLOR playerColor;
public:
    /**
     * Constructor of Participant
     * @param x - Color of Participant.
     */
    explicit Participant(COLOR x);
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
class Player : public Participant
{
    /**
     * Changes char from range: [A-Za-z] to A-Z
     * @param C - char from range [A-za-z]
     * @return - char from range A-Z
     * @return - if C is not from range [A-za-z] return '~'.
     */
    static char toUpperCase(char C);
public:
    /**
    * Virtual method that defines Piece move\n
    * @invariant Bounds and legality of move is not checked here.
    * @param bo - Board of used Checkers game.
    * @return Pair of defined move {X,Y} -> {X,Y}.
    */
    std::pair<std::pair<int,int>,std::pair<int,int>> makeMove(const Board& bo);

    /**
    * Virtual method that defines Piece move\n
    * @invariant Bounds and legality of move is not checked here.
    * @param bo - Board of used Checkers game.
    * @param oldMove - Old move from which you start new one.
    * @return Pair of defined move {X,Y} -> {X,Y}.
    */
    std::pair<std::pair<int,int>,std::pair<int,int>> makeMove(const Board& bo, std::pair<std::pair<int, int>, std::pair<int, int>> oldMove);
    /**
     * Constructor for Player using Participant constructor.
     * @param x Color of player.
     */
    explicit Player(COLOR x);

};

#endif //CHECKERS_PARTICIPANT_HPP
