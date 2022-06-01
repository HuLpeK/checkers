//
// Created by Hubert Kulpaczyński on 28/05/2022.
//

#include "logic.hpp"

COLOR Logic::win(const Board &bo) {
    int numberWhite {};
    int numberBlack {};

    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
        {
            if(bo.at(i,j).getColor() == WHITE)
                numberWhite++;
            if(bo.at(i,j).getColor() == BLACK)
                numberBlack++;
        }

    if(!numberWhite)
        return BLACK;
    if(!numberBlack)
        return WHITE;
    return NONE;
}

bool Logic::legalMove(const Board &bo, std::pair<std::pair<int, int>, std::pair<int, int>>& move, COLOR playerColor) {
    auto const& [from,to] = move;
    //Check bounds
    if(from.first < 0 or from.second < 0 or from.first >= SIZE or from.second >= SIZE)
        return false;
    //Check Color
    if(bo.at(from.first, from.second).getColor() != playerColor)
        return false;


    std::pair<int,int> distMove {to.first - from.first, to.second -from.second};
    std::pair<int,int> smallMove  {(distMove.first > 0 ? 1 : -1),(distMove.second > 0 ? 1 : -1)};

    for(std::pair<int,int> i = {from.first + smallMove.first, from.second + smallMove.second}; i.first != to.first and i.second != to.second; i.first += smallMove.first,
            i.second += smallMove.second)
        if(bo.at(i.first,i.second).getColor() == playerColor)
            return false;

    for(const auto& [x,y]: bo.at(from.first,from.second).getMoves())
        if(from.first + x == to.first and from.second + y == to.second and bo.at(to.first, to.second).getColor() == NONE)
            return true;

    COLOR opositeColor {};
    if(playerColor == WHITE)
        opositeColor = BLACK;
    else
        opositeColor = WHITE;
    //Check bicie
    for(const auto& [x,y]: bo.at(from.first,from.second).getMoves())
        if(from.first + 2*x == to.first and from.second + 2*y == to.second and bo.at(to.first, to.second).getColor() == NONE
        and bo.at(from.first+x,from.second+y).getColor() == opositeColor)
            return true;
    return false;
}

std::pair<int,int> Logic::possibleBicie(const Board &bo, COLOR playerColor) {
    COLOR oppositeColor = (playerColor == WHITE ? WHITE : BLACK);
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            if(bo.at(i,j).getColor() == playerColor)
                for(const auto& [x, y]: bo.at(i,j).getMoves())
                {
                    std::pair<int,int> smallMove  {(x > 0 ? 1 : -1),(y > 0 ? 1 : -1)};
                    if(bo.at(i+x,i+y).getColor() == oppositeColor
                        and bo.at(i+smallMove.first * 2,j+smallMove.second*2).getColor() == NONE)
                            return {i,j};
                }

    return {-1,-1};
}
