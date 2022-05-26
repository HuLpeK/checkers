//
// Created by Hubert Kulpaczyński on 26/05/2022.
//

#include "board.hpp"


Piece &Board::at(const int x,const  int y) {
    return Square[x][y];
}

const Piece Board::at(const int x, const int y) const {
    return Square[x][y];
}


Board::Board() {

    int index = 0;
    for(int i = 0; i < SIZE; i += 2)
        at(i,index) = Man(WHITE), at(i,index+2) = Man(WHITE);
    index++;
    for(int i = 1; i < SIZE; i += 2)
        at(i,index) = Man(WHITE);

    index = 7;

    for(int i = 0; i < SIZE; i += 2)
        at(i,index) = Man(BLACK), at(i,index-2) = Man(BLACK);
    index--;
    for(int i = 1; i < SIZE; i += 2)
        at(i,index) = Man(BLACK);

}

std::ostream &operator<<(std::ostream &out,const Board &Bo) {
    for(int i = SIZE-1; i >= 0; i--)
    {
        for(int j = 0; j < SIZE; j++)
            out << Bo.at(j,i).getName() << "\t";
        out << "\n";
    }
    return out;
}





