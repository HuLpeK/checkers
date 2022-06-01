//
// Created by Hubert Kulpaczyński on 28/05/2022.
//

#include "Participant.hpp"

Participant::Participant(COLOR x) : playerColor(x) {}

COLOR Participant::getColor() {
    return playerColor;
}

std::pair<std::pair<int, int>, std::pair<int, int>> Player::makeMove(const Board &bo) {
    std::cout << "Ruch:" << (playerColor == WHITE ? "BIAŁYCH" : "CZARNYCH") << "\nPodaj Współrzedne ruchu!: ";
    char xStart {};
    int yStart {};
    char xEnd {};
    int yEnd {};
    std::cin >> xStart >> yStart >> xEnd >> yEnd;

    xStart = toUpperCase(xStart);
    xEnd = toUpperCase(xEnd);
    if(xStart == '~' or xEnd == '~' ) //Error
        std::cerr << "BLAD!\n";

    int x = xStart-'A';
    int x1 = xEnd - 'A';
    yStart--;
    yEnd--;
    return {{x, yStart}, {x1,yEnd}};
}

char Player::toUpperCase(char C) {
    if(C >= 'A' and C <= 'Z')
        return C;
    if(C >= 'a' and C <= 'z')
        return C - 'a' + 'A';
    return '~';

}

Player::Player(COLOR x) : Participant(x) {}


