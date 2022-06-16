//
// Created by Hubert Kulpaczyński on 26/05/2022.
//

#include "board.hpp"
#include "../utils/clear.h"

Piece &Board::at(const int x,const  int y) {
    return Square[7-y][x];
}

Piece Board::at(const int x, const int y) const {
    if (x < 0 or y < 0 or x >= SIZE or y >= SIZE)
        return {};
    return Square[7-y][x];
}


Board::Board() {
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            if((i+j) % 2 == 0) {
                if (j <= 2)
                    at(i, j) = Man(WHITE);
                else
                    if (j >= 5)
                        at(i, j) = Man(BLACK);
            }

}

std::ostream &operator<<(std::ostream &out,const Board &Bo) {

    clear_screen();
    std::string tab[SIZE+3][SIZE+3];
    for(int i = 0; i <= SIZE; i++)
    {
        tab[SIZE][i+1] = std::string(reinterpret_cast<const char *>('A' + i));
        tab[i-1][0] = std::string(reinterpret_cast<const char *>('9' - i));
    }
    tab[SIZE][0] = " ";
    for(int i = 0; i < SIZE ; i++)
    {
        for(int j = 0; j < SIZE; j++)
            tab[7-j][i+1] = Bo.at(i,j).getIcon();
//        at{0,0} -> {7,1}
//        at{7,7} -> {0,8} // at{i,j} -> {7-j,i+1}
//        at{0,7} -> {0,1}
    }

    for(int i = 0; i <= SIZE ; i++)
    {
        for(int j = 0; j <= SIZE; j++)
            out << tab[i][j];
        out << "\n";
    }

    return out;
}


