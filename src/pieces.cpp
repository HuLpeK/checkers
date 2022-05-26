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

Piece::Piece() : Color(NONE) {}

Piece::Piece(COLOR x) : Color(x) {}

std::vector<std::pair<int, int>> &Piece::getMoves() {
    return Moves;
}

Man::Man(COLOR x) : Piece(x)  {
    Name = "Man";
    Moves = {{1,-1},{1,1}};
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

}
