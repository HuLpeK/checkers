
#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "../src/pieces.hpp"
#include "../src/board.hpp"
class PiecesTest : public ::testing::Test
{
protected:
    PiecesTest() = default;
    ~PiecesTest() override = default;

    void SetUp() override {};
    void TearDown() override {};
};

void clearBoard(Board& bo)
{
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            bo.at(i,j) = Piece();
}

/**
 * Test tak checks default Piece constructor.
 */
TEST_F(PiecesTest, Check_Basic_Constructor_Should_Return_Square)
{
    Piece x;
    EXPECT_TRUE(x.getColor() == NONE and x.getName() == "Square");
}

/**
 * Test that checks Mans constructors.
 * @returns Returns if color and name are set to correct ones.
 */
TEST_F(PiecesTest, Check_Man_Black_and_White_Constructor_Should_Return_Man)
{
    Man x{WHITE};
    EXPECT_TRUE(x.getColor() == WHITE and x.getName() == "Man");
    Man y{BLACK};
    EXPECT_TRUE(y.getColor() == BLACK and y.getName() == "Man");
}

/**
 * Test that checks King's constructors.
 * @return Returns if color and name are set to correct ones.
 */
TEST_F(PiecesTest, Check_King_Constructor_Should_Return_King)
{
    King x{WHITE};
    EXPECT_TRUE(x.getColor() == WHITE and x.getName() == "King");
    King y{BLACK};
    EXPECT_TRUE(y.getColor() == BLACK and y.getName() == "King");
}

/**
 * Test that checks if White Man moves works as intended.
 * @return Left and Right 'corner' of piece.
 */
TEST_F(PiecesTest, Check_White_Man_Moves_Should_Return_Left_And_Right_Corner)
{
    Board expected;
    clearBoard(expected);
    const auto& [startX,startY] = std::pair<int,int>{1,2};
    expected.at(startX,startY) = Man(WHITE);
    expected.at(2,3) = King(BLACK);
    expected.at(0,3) = King(BLACK);

    Board tab;
    clearBoard(tab);
    tab.at(startX,startY) = Man(WHITE);
    for(const auto& it: tab.at(startX,startY).getMoves())
        tab.at(startX+it.first,startY+it.second) = King(BLACK);

    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            EXPECT_EQ(tab.at(i,j).getIcon(),expected.at(i,j).getIcon());

}

/**
 * Test that checks if Black Man moves works as intended.
 * @return Left and Right 'corner' of piece.
 */
TEST_F(PiecesTest, Check_Black_Man_Moves_Should_Return_Left_And_Right_Corner)
{
    Board expected;
    clearBoard(expected);
    const auto& [startX,startY] = std::pair<int,int>{1,2};
    expected.at(startX,startY) = Man(BLACK);
    expected.at(2,1) = King(WHITE);
    expected.at(0,1) = King(WHITE);

    Board tab;
    clearBoard(tab);
    tab.at(startX,startY) = Man(BLACK);
    for(const auto& it: tab.at(startX,startY).getMoves())
        tab.at(startX+it.first,startY+it.second) = King(WHITE);

    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            EXPECT_EQ(tab.at(i,j).getIcon(),expected.at(i,j).getIcon());

}

/**
 * Check if black king moves works as intended.
 * @return All 4 diagonals from Piece.
 */
TEST_F(PiecesTest, Check_Black_King_Moves_Should_Return_Left_And_Right_Diagonal)
{
    King Tmp{BLACK};
    const std::string expectedTab[5][5] {
            {"X","","","","X"},
            {"","X","","X",""},
            {"","","O","",""},
            {"","X","","X",""},
            {"X","","","","X"},
    };
    const int midX {2}, midY {2};

    std::string tab[5][5];
    tab[midX][midY] = "O";
    for(const auto& [x,y]: Tmp.getMoves())
        if(midX+x < 5 and midY + y < 5 and midX+x >= 0 and midY+y >=0)
            tab[midX+x][midY+y] = "X";

    for(int i = 0;i < 5; i++)
        for(int j = 0; j < 5; j++)
            EXPECT_EQ(tab[i][j], expectedTab[i][j]);
}

/**
 * Check if white king moves works as intended.
 * @return All 4 diagonals from Piece.
 */
TEST_F(PiecesTest, Check_White_King_Moves_Should_Return_Left_And_Right_Diagonal)
{
    King Tmp{WHITE};
    const std::string expectedTab[5][5] {
            {"X","","","","X"},
            {"","X","","X",""},
            {"","","O","",""},
            {"","X","","X",""},
            {"X","","","","X"},
    };
    const int midX {2}, midY {2};

    std::string tab[5][5];
    tab[midX][midY] = "O";
    for(const auto& [x,y]: Tmp.getMoves())
        if(midX+x < 5 and midY + y < 5 and midX+x >= 0 and midY+y >= 0)
            tab[midX+x][midY+y] = "X";


    for(int i = 0;i < 5; i++)
        for(int j = 0; j < 5; j++)
            ASSERT_EQ(tab[i][j], expectedTab[i][j]);
}