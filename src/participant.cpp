//
// Created by Hubert Kulpaczyński on 28/05/2022.
//

#include "participant.hpp"

participant::participant(COLOR x) : playerColor(x) {
}

COLOR participant::getColor() {
    return playerColor;
}

std::pair<std::pair<int, int>, std::pair<int, int>> Player::makeMove(const Board &bo) {
    std::cout << "Podaj Współrzedne ruchu!: ";
    char xStart {};
    int yStart {};
    std::cin >> xStart >> yStart;

    char xEnd {};
    int yEnd {};
    std::cin >> xEnd >> yEnd;

    xStart = toUpperCase(xStart);
    xEnd = toUpperCase(xEnd);

    int x = xStart-'A';
    int x1 = xEnd - 'A';

    return {{x, yStart}, {x1,xEnd}};
}

char Player::toUpperCase( char C) {
    if(C >= 'A' and C <= 'Z')
        return C;
    if(C >= 'a' and C <= 'z')
        return C - 'a' + 'A';
    return '~';

}


