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

//    if(abs(from.first - to.first) != abs(from.second - to.second)) // if it's not diagonal
    if(abs(to.first - from.first) != abs(to.second - from.second))
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
    COLOR oppositeColor = (playerColor == BLACK ? WHITE : BLACK);
    const auto& [startX, startY] = starter;
    for(const auto& [mvX, mvY] : bo.at(startX, startY).getMoves())
    {
        const auto& [toX, toY] = std::pair<int,int> {mvX+startX,mvY+startY};
        if(bo.at(toX,toY).getColor() == oppositeColor)
        {
            const auto& [dirX,dirY] = std::pair<int,int> {
                    (mvX > 0 ? 1 : -1),
                    (mvY > 0 ? 1 : -1)
            };
            if(bo.at(toX+dirX,toY+dirY).getColor() == NONE)
            {
                std::pair<std::pair<int,int>,std::pair<int,int>> mv {starter,{toX+dirX,toY+dirY}};
                if(Logic::legalMove(bo,mv,playerColor))
                    return true;
            }
        }

    }

    return false;
}

std::pair<int, int> Logic::possibleBicie(const Board &bo, COLOR playerColor) {
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            if(possibleBicie(bo,playerColor,{i,j}))
                return {i,j};

    return {-1,-1};
}
