/**
 * @file board.hpp
 * @author Hubert Kulpaczyński\n Indeks:330840
 * @author Uniwersytet Wrocławki: Instytut Informatyki
 */
#ifndef CHECKERS_PARTICIPANT_HPP
#define CHECKERS_PARTICIPANT_HPP


#include <utility>
#include "board.hpp"
#include "logic.hpp"

//! Virtual template class.
class Participant {
protected:
    /**
     * Color of player.
     */
    COLOR playerColor;
    /**
     * Reference to Board that game is taking place.
     */
    const Board &bo {};
public:
    /**
     * Constructor of Participant
     * @param x - Color of Participant.
     * @param bo - Board that game is taking place on.
     */
    Participant(COLOR x, Board &bo);
    virtual ~Participant()=default;
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
    virtual std::pair<std::pair<int, int>, std::pair<int, int>> makeMove()=0;

    /**
   * Method that defines Piece move\n
   * @invariant Bounds and legality of move is not checked here.
   * @param oldMove - Old move from which you start new one.
   * @return Pair of defined move {X,Y} -> {X,Y}.
   */
    virtual std::pair<std::pair<int, int>, std::pair<int, int>>
    makeMove(std::pair<std::pair<int, int>, std::pair<int, int>> oldMove)=0;
};

//! Player (User)
class Player : public Participant {
public:
    /**
     * Changes char from range: [A-Za-z] to A-Z
     * @param C - char from range [A-za-z]
     * @return - char from range A-Z
     * @return - if C is not from range [A-za-z] return '~'.
     */
    static char toUpperCase(char C);

    /**
    * Method that defines Piece move\n
    * @invariant Bounds and legality of move is not checked here.
    * @return Pair of defined move {X,Y} -> {X,Y}.
    */
    std::pair<std::pair<int, int>, std::pair<int, int>> makeMove() final;

    /**
    * Method that defines Piece move\n
    * @invariant Bounds and legality of move is not checked here.
    * @param oldMove - Old move from which you start new one.
    * @return Pair of defined move {X,Y} -> {X,Y}.
    */
    std::pair<std::pair<int, int>, std::pair<int, int>>
    makeMove(std::pair<std::pair<int, int>, std::pair<int, int>> oldMove) final;

    /**
     * Constructor for Player using Participant constructor.
     * @param x Color of player.
     * @param bo  Reference to Board that is taken place.
     */
    explicit Player(COLOR x, Board &bo);

};

//!Simple 'AI' to play with.
class Bot : public Participant {
protected:
    /**
     * Define move for Bot if Bicie is possible.
     * @param start Starting position
     * @invariant Bicie is always possible.
     * @return pair {x,y} where to move Piece from start ( start -> {x,y} ).
     */
    std::pair<int, int> makeBicie(std::pair<int, int> oldMove);


    /**     *
     * @invariant At least one Piece of playerColor on Board.
     * @return All Pieces of playerColor of board sorted from furthest to closest.
     */
    std::vector<std::pair<int, int>> getPieces();

public:
    /**
     * Constructor for bot
     * @param x - COLOR of side
     * @param bo - Board that game takes place at.
     */
    explicit Bot(COLOR x, Board &bo);


    /**
    * Method that defines Piece move\n
    * @invariant Bounds and legality of move is not checked here.
    * @return Pair of defined move {X,Y} -> {X,Y}.
    */
    std::pair<std::pair<int, int>, std::pair<int, int>> makeMove() final ;

    /**
    * Method that defines Piece move\n
    * @invariant Bounds and legality of move is not checked here.
    * @param oldMove - Old move from which you start new one.
    * @return Pair of defined move {X,Y} -> {X,Y}.
    */
    std::pair<std::pair<int, int>, std::pair<int, int>>
    makeMove(std::pair<std::pair<int, int>, std::pair<int, int>> oldMove) final;

};

#endif //CHECKERS_PARTICIPANT_HPP
