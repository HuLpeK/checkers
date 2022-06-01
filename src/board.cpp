//
// Created by Hubert Kulpaczyński on 26/05/2022.
//

#include "board.hpp"


Piece &Board::at(const int x,const  int y) {
    return Square[x][y];
}

const Piece Board::at(const int x, const int y) const {
    if(x < 0 or y < 0 or x >= SIZE or y >= SIZE)
        return Piece();
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

    for(int i = 1; i < SIZE; i += 2)
        at(i, index) = Man(BLACK), at(i,index-2) = Man(BLACK);
    index--;
    for(int i = 0; i < SIZE; i += 2)
        at(i,index) = Man(BLACK);

}

std::ostream &operator<<(std::ostream &out,const Board &Bo) {

    std::string tab[SIZE+3][SIZE+3];
    for(int i = 0; i <= SIZE; i++)
    {
        tab[0][i+1] = 'A' + i;
        tab[i][0] = '0' + i;
    }
    tab[0][0] = " ";
    for(int i = SIZE-1; i >= 0; i--)
    {
        for(int j = 0; j < SIZE; j++)
            tab[i+1][j+1] = Bo.at(j,i).getIcon();
    }

    for(int i = SIZE; i >= 0; i--)
    {
        for(int j = 0; j <= SIZE; j++)
            out << tab[i][j];
        out << "\n";
    }

//    for(int i = SIZE-1; i >= 0; i--)
//    {
//        for(int j = 0; j < SIZE; j++)
//            out << Bo.at(j,i).getIcon() << "";
//        out << "\n";
//    }
    return out;
}





