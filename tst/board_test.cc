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

class BoardMock{
public:
    MOCK_METHOD(Piece, at,(int x,int y));
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
    for (int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++)
            if((i+j)%2 == 0) {
                if (j >= 5)
                    expectedBoard[i][j] = Man(BLACK);
                else if (j < 3)
                    expectedBoard[i][j] = Man(WHITE);
            }
    }

//    for (int i = 0; i < SIZE; i++) {
//        for (int j = 0; j < 8; j++)
//            std::cout << expectedBoard[i][j].getIcon();
//        std::cout << "\n";
//    }
//    std::cout << "\n\n";
//    for(int i = 0; i < SIZE; i++)
//    {
//        for(int j = 0; j < 8; j++)
//            std::cout << Tmp.at(i,j).getIcon();
//        std::cout << "\n";
//    }
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            EXPECT_EQ(expectedBoard[i][j], Tmp.at(i, j));
}

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

TEST_F(BoardTest, Check_Board_Mock)
{
    testing::NiceMock<BoardMock> x;
    ON_CALL(x, at(testing::_,testing::_)).WillByDefault(testing::Return(King(BLACK)));
    ON_CALL(x, at(1,testing::_)).WillByDefault(testing::Return(Man(WHITE)));
    //EXPECT_CALL(board, isFree(move.first,move.second)).WillOnce(Return(true));

    std::cout << x.at(1,0).getIcon() << " ";
}