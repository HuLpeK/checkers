//
// Created by Hubert Kulpaczyński on 26/05/2022.
//

#include "pieces.hpp"

std::string Pieces::getName() {
    return this->Name;
}

COLOR Pieces::getColor() {
    return Color;
}

Pieces::Pieces() : Color(NONE) {}

Pieces::Pieces(COLOR x) :Color(x) {}

std::vector<std::pair<int, int>> &Pieces::getMoves() {
    return Moves;
}

Man::Man(COLOR x) : Pieces(x)  {
    Name = "Man";
    Moves = {{1,-1},{1,1}};
}

King::King(COLOR x): Pieces(x) {
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
