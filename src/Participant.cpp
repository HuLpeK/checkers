//
// Created by Hubert Kulpaczyński on 28/05/2022.
//

#include "Participant.hpp"

Participant::Participant(COLOR x, Board& bo) : playerColor(x), bo(bo) {}

COLOR Participant::getColor() {
    return playerColor;
}

std::pair<std::pair<int, int>, std::pair<int, int>> Player::makeMove() {

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

Player::Player(COLOR x, Board& bo) : Participant(x,bo) {}

std::pair<std::pair<int, int>, std::pair<int, int>> Player::makeMove(std::pair<std::pair<int, int>, std::pair<int, int>> oldMove) {

    const auto [fromOld, toOld] = oldMove;
    std::cout << "Ruch:" << (playerColor == WHITE ? "BIAŁYCH" : "CZARNYCH") << "\nPodaj Współrzedne ruchu!: "
        << (char)('A' + toOld.first) << toOld.second+1 << " -> ";
    char xEnd {};
    int yEnd {};
    std::cin >>  xEnd >> yEnd;
    xEnd = toUpperCase(xEnd);
    if(xEnd == '~' ) //Error
        std::cerr << "BLAD!\n";
    xEnd -= 'A';
    yEnd--;
    return {toOld,{xEnd,yEnd}};
}


