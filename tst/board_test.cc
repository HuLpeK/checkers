/***
 * \file board_test.cc
 * @author Hubert Kulpaczyński
 */
#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "../src/board.hpp"
class BoardTest : public ::testing::Test
{
protected:
    BoardTest() = default;;
    ~BoardTest() override = default;;

    void SetUp() override {};
    void TearDown() override {};
};

bool operator==(const Piece& a, const Piece& b)
{
    return a.getName() == b.getName() and a.getColor() == b.getColor();
}
Board clearBoard()
{
    Board tmp;
    for(int i = 0; i < SIZE; i++)
        for(int j = 0;j < SIZE; j++)
            tmp.at(i,j) = Piece();
    return tmp;
}
TEST_F(BoardTest, Check_If_Board_Is_Correctly_Build) {
    Board Tmp;
    Piece expectedBoard[8][8];
    int index = 0;
    for(int i = 0; i < SIZE; i += 2)
        expectedBoard[index][i] = Man(WHITE), expectedBoard[index+2][i] = Man(WHITE);
    index++;
    for(int i = 1; i < SIZE; i += 2)
        expectedBoard[index][i] = Man(WHITE);

    index = 7;

    for(int i = 1; i < SIZE; i += 2)
        expectedBoard[index][i] = Man(BLACK), expectedBoard[index-2][i] = Man(BLACK);
    index--;
    for(int i = 0; i < SIZE; i += 2)
        expectedBoard[index][i] = Man(BLACK);


    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < 8; j++)
            std::cout << expectedBoard[i][j].getIcon();
        std::cout << "\n";
    }
    std::cout << "\n\n";
//    for(int i = 0; i < SIZE; i++)
//    {
//        for(int j = 0; j < 8; j++)
//            std::cout << Tmp.at(i,j).getIcon();
//        std::cout << "\n";
//    }
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            EXPECT_EQ(expectedBoard[i][j], Tmp.at(i,j));
}
//todo can we make better tests here?