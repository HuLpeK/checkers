//
// Created by Hubert Kulpaczyński on 27/05/2022.
//

#include "game.hpp"
#include "logic.hpp"
#include "clear.h"
void Game::Start() {
    COLOR actualColor = WHITE;
    while(!Logic::win(board)) {
        clear_screen();
        std::cout << board;

        std::pair<std::pair<int, int>, std::pair<int, int>> mv{};

        if (actualColor == WHITE)
            mv = white.makeMove();
        else
            mv = black.makeMove();

        while (!Logic::legalMove(board, mv, actualColor)) {
            std::cout << "BLAD!\n";
            if (actualColor == WHITE)
                mv = white.makeMove();
            else
                mv = black.makeMove();
        }
        const auto [fromX, fromY] = Logic::possibleBicie(board, actualColor);

        if (!makeMove(mv, actualColor)) // if bicie hasn't been done check if possibleBicie was possibleBicie
        {
            std::cout << "Za niebicie tracisz zycie!\n";
            board.at(fromX,fromY) = Piece();
        }
        else while(Logic::possibleBicie(board,actualColor, mv.second)) // performed bicie but one more is possible
        {
            std::cout << board;
            if(actualColor == WHITE)
            {
                std::pair<std::pair<int,int>,std::pair<int,int>> tmp {{-1,-1},{-1,-1}};
                tmp = white.makeMove(mv);

                while(!Logic::legalMove(board,tmp,WHITE))
                {
                    std::cout << "BLAD2!\n";
                    tmp = white.makeMove(mv);
                }
                mv = tmp;
            }
            if(actualColor == BLACK)
            {
                std::pair<std::pair<int,int>,std::pair<int,int>> tmp {{-1,-1},{-1,-1}};
                tmp = white.makeMove(mv);
                while(!Logic::legalMove(board,tmp,BLACK))
                {
                    std::cout << "BLAD2!\n";
                    tmp = white.makeMove(mv);
                }
                mv = tmp;
            }
            makeMove(mv,actualColor);
        }



        if(actualColor == WHITE)
            actualColor = BLACK;
        else
            actualColor = WHITE;
    }
    std::cout << board << '\n';
    if(Logic::win(board) == WHITE)
        std::cout << "Wygrał Czarny!\n\n";
    else
        std::cout << "Wygrał Biały!\n\n";
}

Game::Game() :board(), white(WHITE, board), black(BLACK, board) {}

bool Game::makeMove(std::pair<std::pair<int, int>, std::pair<int, int>> move, COLOR actualColor) {
    auto [from,to] = move;
    board.at(from.first,from.second) = Piece();

    if(actualColor == WHITE and to.second == SIZE-1 ) {
        board.at(to.first,to.second) = Man(WHITE);
        if(!Logic::possibleBicie(board,actualColor,to))
            board.at(to.first, to.second) = King(WHITE);
    }
    if(actualColor == BLACK and to.second == 0)
    {
        board.at(to.first,to.second) = Man(WHITE);
        if(!Logic::possibleBicie(board,actualColor,to))
            board.at(to.first,to.second) = King(BLACK);
    }

    if(actualColor == WHITE and to.second != SIZE-1)
        board.at(to.first,to.second) = Man(WHITE);

    if(actualColor == BLACK and to.second != 0)
        board.at(to.first,to.second) = Man(BLACK);

    bool flag = false;
    std::pair<int,int> distMove {to.first - from.first, to.second -from.second};
    std::pair<int,int> smallMove  {(distMove.first > 0 ? 1 : -1),(distMove.second > 0 ? 1 : -1)};

    for(auto i = from; i.first != to.first and i.second != to.second; i.first += smallMove.first, i.second += smallMove.second)
    {
        if(board.at(i.first,i.second).getColor() != NONE)
            flag = true;
        board.at(i.first,i.second) = Piece();
    }
    return flag;

}
