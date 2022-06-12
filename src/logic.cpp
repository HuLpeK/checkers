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

bool checkBounds(std::pair<int,int> pos)
{
    const auto& [x,y] = pos;
    if(x >= SIZE or y >= SIZE or x < 0 or y < 0)
        return false;
    return true;
}

bool Logic::legalMove(const Board &bo, std::pair<std::pair<int, int>, std::pair<int, int>>& move, COLOR playerColor) {
    auto const& [from,to] = move;
    if(!checkBounds(from) or !checkBounds(to))
       return false;
    if(bo.at(from.first,from.second).getColor() != playerColor)
        return false;
    if(bo.at(to.first, to.second).getColor() != NONE)
        return false;

    COLOR oppositeColor = (playerColor == WHITE ? BLACK : WHITE);

    std::pair<int,int> direction {(to.first - from.first > 0 ? 1 : -1), (to.second - from.second > 0 ? 1 : -1)};
    const auto& [dirX, dirY] = direction;

    if(abs(from.first - to.first) != abs(from.second - to.second)) // if it's not diagonal
       return false;

    for(int i = from.first, j = from.second; i != to.first-dirX and j != to.second-dirY; i+= dirX, j+=dirY)
    {
        if(bo.at(i,j).getColor() == playerColor and i != from.first)
            return false;
        if(bo.at(i,j).getColor() == oppositeColor)
        {
            if(bo.at(i+dirX,j+dirY).getColor() == NONE)
                return true;
            return false;
        }
    }
    return true;

}

bool Logic::possibleBicie(const Board &bo, COLOR playerColor, std::pair<int,int> starter) {
    COLOR oppositeColor = (playerColor == WHITE ? WHITE : BLACK);
//    if(bo.at(starter.first,starter.second).getColor() == playerColor)
//        for(const auto& [x,y]: bo.at(starter.first,starter.second).getMoves())
//        {
//           std::pair<int,int> smallMove {{x > 0 ? 1 : -1}, {y > 0 ? 1 : -1}};
//           const auto& [xS, yS] = smallMove;
//           const auto& [startX, startY] = starter;
//           if(bo.at(startX + xS, starter.second + yS).getColor() == oppositeColor)
//
//        }

    return false;
}

std::pair<int, int> Logic::possibleBicie(const Board &bo, COLOR playerColor) {
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            if(possibleBicie(bo,playerColor,{i,j}))
                return {i,j};

    return {-1,-1};
}
