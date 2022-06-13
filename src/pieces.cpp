//
// Created by Hubert Kulpaczyński on 26/05/2022.
//

#include "pieces.hpp"

std::string Piece::getName() const {
    return this->Name;
}

COLOR Piece::getColor() const {
    return Color;
}

Piece::Piece() : Color(NONE), Icon("□"), Moves(), Name("Square")  {}

Piece::Piece(COLOR x) : Color(x) {}

std::vector<std::pair<int, int>>  Piece::getMoves() const {
    return Moves;
}

std::string Piece::getIcon() const {
    return Icon;
}

Man::Man(COLOR x) : Piece(x)  {
    Name = "Man";
    Moves.clear();
    Moves = {{-1,1},{1,1}};
    switch (Color)
    {
        case WHITE:
            Icon = "♟";
        break;
        case BLACK:
            Icon = "♙";
        break;
        case NONE:
            Icon = "□";
        break;
    }
    if(Color == BLACK)
    {
        Moves[0].second *= -1;
        Moves[1].second *= -1;
    }
}

King::King(COLOR x): Piece(x) {
    Name = "King";
    for(int i = 1; i <= 8; i++)
    {
        Moves.emplace_back(i,i);
        Moves.emplace_back(-i,-i);
        Moves.emplace_back(i,-i);
        Moves.emplace_back(-i,i);
    }
    Moves.shrink_to_fit();

    switch (Color)
    {
        case WHITE:
            Icon = "♚";
        break;
        case BLACK:
            Icon = "♔";
        break;

        case NONE:
            Icon = "";
        break;
    }
}
