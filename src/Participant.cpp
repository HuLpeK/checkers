//
// Created by Hubert Kulpaczyński on 28/05/2022.
//

#include "Participant.hpp"

Participant::Participant(COLOR x, Board &bo) : playerColor(x), bo(bo) {}

COLOR Participant::getColor() {
    return playerColor;
}

std::pair<std::pair<int, int>, std::pair<int, int>> Player::makeMove() {

    std::cout << "Ruch:" << (playerColor == WHITE ? "BIAŁYCH" : "CZARNYCH") << "\nPodaj Współrzedne ruchu!: ";
    char xStart{};
    int yStart{};
    char xEnd{};
    int yEnd{};
    std::cin >> xStart >> yStart >> xEnd >> yEnd;

    xStart = toUpperCase(xStart);
    xEnd = toUpperCase(xEnd);
    if (xStart == '~' or xEnd == '~') //Error
        std::cerr << "BLAD!\n";

    int x = xStart - 'A';
    int x1 = xEnd - 'A';
    yStart--;
    yEnd--;
    return {{x,  yStart},
            {x1, yEnd}};
}

char Player::toUpperCase(char C) {
    if (C >= 'A' and C <= 'Z')
        return C;
    if (C >= 'a' and C <= 'z')
        return C - 'a' + 'A';
    return '~';

}

Player::Player(COLOR x, Board &bo) : Participant(x, bo) {}

std::pair<std::pair<int, int>, std::pair<int, int>>
Player::makeMove(std::pair<std::pair<int, int>, std::pair<int, int>> oldMove) {

    const auto [fromOld, toOld] = oldMove;
    std::cout << "Ruch:" << (playerColor == WHITE ? "BIAŁYCH" : "CZARNYCH") << "\nPodaj Współrzedne ruchu!: "
              << (char) ('A' + toOld.first) << toOld.second + 1 << " -> ";
    char xEnd{};
    int yEnd{};
    std::cin >> xEnd >> yEnd;
    xEnd = toUpperCase(xEnd);
    if (xEnd == '~') //Error
        std::cerr << "BLAD!\n";
    xEnd -= 'A';
    yEnd--;
    return {toOld, {xEnd, yEnd}};
}


Bot::Bot(COLOR x, Board &bo) : Participant(x, bo) {}

std::pair<std::pair<int, int>, std::pair<int, int>> Bot::makeMove() {
    if (Logic::possibleBicie(bo, playerColor) != std::pair<int, int>{-1, -1})
        return {Logic::possibleBicie(bo, playerColor), makeBicie(Logic::possibleBicie(bo, playerColor))};

    std::vector<std::pair<int, int>> posPieces{getPieces()};

    for (const auto &[x, y]: posPieces)
        for (const auto &[mvX, mvY]: bo.at(x, y).getMoves()) {
            std::pair<std::pair<int, int>, std::pair<int, int>> mv{{x,       y},
                                                                   {x + mvX, y + mvY}};
            if (Logic::legalMove(bo, mv, playerColor))
                return {{x,       y},
                        {mvX + x, mvY + y}};
        }

    return {};
}

std::pair<int, int> Bot::makeBicie(const std::pair<int, int> oldMove) {
    COLOR oppositeColor = (playerColor == BLACK ? WHITE : BLACK);
    const auto &[startX, startY] = oldMove;
    for (const auto &[mvX, mvY]: bo.at(startX, startY).getAttacks()) {
        const auto &[toX, toY] = std::pair<int, int>{mvX + startX, mvY + startY};
        if (bo.at(toX, toY).getColor() == oppositeColor) {
            const auto &[dirX, dirY] = std::pair<int, int>{
                    (mvX > 0 ? 1 : -1),
                    (mvY > 0 ? 1 : -1)
            };
            if (bo.at(toX + dirX, toY + dirY).getColor() == NONE) {
                std::pair<std::pair<int, int>, std::pair<int, int>> mv{oldMove, {toX + dirX, toY + dirY}};
                if (Logic::legalMove(bo, mv, playerColor))
                    return mv.second;
            }
        }
    }
    return {-1, -1};
}

std::vector<std::pair<int, int>> Bot::getPieces() {

    std::vector<std::pair<int, int>> pos{};
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (bo.at(i, j).getColor() == playerColor)
                pos.emplace_back(i, j);

    auto comp = [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return a.second > b.second;
    };

    std::sort(pos.begin(), pos.end(), comp);
    if (playerColor == BLACK)
        std::reverse(pos.begin(), pos.end());

    return pos;
}

std::pair<std::pair<int, int>, std::pair<int, int>>
Bot::makeMove(std::pair<std::pair<int, int>, std::pair<int, int>> oldMove) {
    return {oldMove.first, makeBicie(oldMove.first)};
}
