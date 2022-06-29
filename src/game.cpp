//
// Created by Hubert Kulpaczyński on 27/05/2022.
//

#include "game.hpp"
#include "logic.hpp"
#include "../utils/clear.h"

//static inline void wypiszMove(const std::pair<std::pair<int,int>,std::pair<int,int>>& mv)
//{
//    auto [fromX, fromY] = mv.first;
//    auto [toX, toY] = mv.second;
//
//    const char from = fromX + 'A';
//    const char to =  toX + 'A';
//
//    std::ofstream fin("Ruchy.txt",std::ios_base::app);
////    fin.open("Ruchy.txt");
//    fromY++;
//    toY++;
//    fin << from << fromY << " " << to << toY << "\n";
//    std::cout << from << fromY << " " << to << toY << "\n";
////    fin.close();
//}


void Game::Start() {
    COLOR actualColor = WHITE;
//    int ilosc_tur {};
    while (!Logic::win(board)) {
//        ilosc_tur++;
        clear_screen();
        std::cout << board;

        std::pair<std::pair<int, int>, std::pair<int, int>> mv{};

        if (actualColor == WHITE)
            mv = white->makeMove();
        else
            mv = black->makeMove();

        while (!Logic::legalMove(board, mv, actualColor)) {
            std::cout << "BLAD!\n";
            if (actualColor == WHITE)
                mv = white->makeMove();
            else
                mv = black->makeMove();
        }
        const auto [fromX, fromY] = Logic::possibleBicie(board, actualColor);

        if (!makeMove(mv, actualColor)) // if bicie hasn't been done check if possibleBicie was possibleBicie
        {
            std::cout << "Za niebicie tracisz zycie!\n";
            board.at(fromX, fromY) = Piece();
        } else
            while (Logic::possibleBicie(board, actualColor, mv.second)) // performed bicie but one more is possible
            {
                std::cout << board;
                if (actualColor == WHITE) {
                    std::pair<std::pair<int, int>, std::pair<int, int>> tmp{{-1, -1},
                                                                            {-1, -1}};
                    tmp = white->makeMove(mv);

                    while (!Logic::legalMove(board, tmp, WHITE)) {
                        std::cout << "BLAD2!\n";
                        tmp = white->makeMove(mv);
                    }
                    mv = tmp;
                }
                if (actualColor == BLACK) {
                    std::pair<std::pair<int, int>, std::pair<int, int>> tmp{{-1, -1},
                                                                            {-1, -1}};
                    tmp = white->makeMove(mv);
                    while (!Logic::legalMove(board, tmp, BLACK)) {
                        std::cout << "BLAD2!\n";
                        tmp = white->makeMove(mv);
                    }
                    mv = tmp;
                }
                makeMove(mv, actualColor);
            }


        if (actualColor == WHITE)
            actualColor = BLACK;
        else
            actualColor = WHITE;
    }
    std::cout << board << '\n';
    if (Logic::win(board) == BLACK)
        std::cout << "Wygrał Czarny!\n\n";
    else
        std::cout << "Wygrał Biały!\n\n";
}

bool Game::makeMove(std::pair<std::pair<int, int>, std::pair<int, int>> move, COLOR actualColor) {
    auto [from, to] = move;
    board.at(from.first, from.second) = Piece();

    if (actualColor == WHITE and to.second == SIZE - 1) {
        board.at(to.first, to.second) = Man(WHITE);
        if (!Logic::possibleBicie(board, actualColor, to))
            board.at(to.first, to.second) = King(WHITE);
    }
    if (actualColor == BLACK and to.second == 0) {
        board.at(to.first, to.second) = Man(WHITE);
        if (!Logic::possibleBicie(board, actualColor, to))
            board.at(to.first, to.second) = King(BLACK);
    }

    if (actualColor == WHITE and to.second != SIZE - 1)
        board.at(to.first, to.second) = Man(WHITE);

    if (actualColor == BLACK and to.second != 0)
        board.at(to.first, to.second) = Man(BLACK);

    bool flag = false;
    std::pair<int, int> distMove{to.first - from.first, to.second - from.second};
    std::pair<int, int> smallMove{(distMove.first > 0 ? 1 : -1), (distMove.second > 0 ? 1 : -1)};

    for (auto i = from;
         i.first != to.first and i.second != to.second; i.first += smallMove.first, i.second += smallMove.second) {
        if (board.at(i.first, i.second).getColor() != NONE)
            flag = true;
        board.at(i.first, i.second) = Piece();
    }
    return flag;

}

Game::Game(const std::string& wh, const std::string& bl) {
    if(wh == "BOT")
        white = std::make_unique<Bot>(WHITE,board);
    if(wh == "PLAYER")
        white = std::make_unique<Player>(WHITE,board);

    if(bl == "BOT")
        black = std::make_unique<Bot>(BLACK,board);
    if(bl == "PLAYER")
        black = std::make_unique<Player>(BLACK,board);
}