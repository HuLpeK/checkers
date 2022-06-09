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

TEST_F(BoardTest, Check_If_Board_Is_Correctly_Build) {
    Board Tmp;
    Board expectBoard;
    int index = 0;
    for(int i = 0; i < SIZE; i += 2)
        expectBoard.at(i,index) = Man(BLACK), expectBoard.at(i,index+2) = Man(BLACK);
    index++;
    for(int i = 1; i < SIZE; i += 2)
        expectBoard.at(i,index) = Man(BLACK);

    index = 7;

    for(int i = 1; i < SIZE; i += 2)
        expectBoard.at(i, index) = Man(WHITE), expectBoard.at(i,index-2) = Man(WHITE);
    index--;
    for(int i = 0; i < SIZE; i += 2)
        expectBoard.at(i,index) = Man(WHITE);


    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            ASSERT_EQ(expectBoard.at(i,j), Tmp.at(i,j));
}
//todo can we make better tests here?