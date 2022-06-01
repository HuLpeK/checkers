//
// Created by Hubert Kulpaczyński on 27/05/2022.
//

#include "game.hpp"
#include "logic.hpp"
void Game::Start() {
    COLOR actualColor = WHITE;
    board.at(1,3) = Man(BLACK);
    while(!Logic::win(board)) {

        std::cout << board;

        std::pair<std::pair<int, int>, std::pair<int, int>> mv{};

        if (actualColor == WHITE)
            mv = white.makeMove(board);
        else
            mv = black.makeMove(board);

        while (!Logic::legalMove(board, mv, actualColor)) {
            std::cout << "BLAD!\n";
            if (actualColor == WHITE)
                mv = white.makeMove(board);
            else
                mv = black.makeMove(board);
        }
//        const auto [fromX, fromY] = Logic::possibleBicie(board, actualColor);
        const int fromX = Logic::possibleBicie(board,actualColor).first;
        const int fromY = Logic::possibleBicie(board,actualColor).second;
        if (!makeMove(mv, actualColor) and fromX != -1) // if bicie hasn't been done check if possibleBicie was possibleBicie
        {
            std::cout << "Za niebicie tracisz zycie!\n";
            board.at(fromX,fromY) = Piece();
        }



        if(actualColor == WHITE)
            actualColor = BLACK;
        else
            actualColor = WHITE;
    }
}

Game::Game() : white(WHITE), black(BLACK), board() {}

bool Game::makeMove(std::pair<std::pair<int, int>, std::pair<int, int>> move, COLOR actualColor) {
    auto [from,to] = move;
    board.at(from.first,from.second) = Piece();

    if(actualColor == WHITE and to.first == SIZE-1)
        board.at(to.first,to.second) = King(WHITE);
    if(actualColor == BLACK and to.first == 0)
        board.at(to.first,to.second) = King(BLACK);

    if(actualColor == WHITE and to.first != SIZE-1)
        board.at(to.first,to.second) = Man(WHITE);

    if(actualColor == BLACK and to.first != 0)
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
