/// \file board_test.cc
#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "../src/board.hpp"
class BoardTest : public ::testing::Test
{
protected:
    BoardTest() = default;
    ~BoardTest() override = default;

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
/// @test Check of Board constructor.
TEST_F(BoardTest, Check_If_Board_Is_Correctly_Build) {
    Board Tmp;
    Piece expectedBoard[8][8];
    for (int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++)
            if((i+j)%2 == 0) {
                if (j >= 5)
                    expectedBoard[i][j] = Man(BLACK);
                else if (j < 3)
                    expectedBoard[i][j] = Man(WHITE);
            }
    }

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            EXPECT_EQ(expectedBoard[i][j], Tmp.at(i, j));
}
/// @test Check Board.at() for refereint {1,2} -> {B,3}.
TEST_F(BoardTest, Check_If_1_2_Reffer_To_B_3)
{
    Board bo = clearBoard();
    Piece expectedBoard[8][8];
    bo.at(1,2) = Man(WHITE);
    expectedBoard[5][1] = Man(WHITE);

    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            EXPECT_EQ(expectedBoard[7-j][i], bo.at(i,j));
}