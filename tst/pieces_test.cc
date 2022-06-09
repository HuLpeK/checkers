/**
 * \file pieces_test.cc
 */
#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "../src/pieces.hpp"
class PiecesTest : public ::testing::Test
{
protected:
    PiecesTest() = default;;
    ~PiecesTest() override = default;;

    void SetUp() override {};
    void TearDown() override {};
};

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
    Man Tmp{WHITE};
    const std::string expectedTab[3][3]
            {
                {"X","","X"},
                {"","O",""},
                {"","",""}
            };
    std::string tab[3][3] {};
    const int midX = 1, midY = 1;
    tab[midX][midY] = 'O';
    for(const auto& [x,y] : Tmp.getMoves())
        tab[midX+x][midY+y] = 'X';

    for(int i = 0;i < 3; i++)
        for(int j = 0; j < 3; j++)
            ASSERT_EQ(tab[i][j],expectedTab[i][j]);
}

/**
 * Test that checks if Black Man moves works as intended.
 * @return Left and Right 'corner' of piece.
 */
TEST_F(PiecesTest, Check_Black_Man_Moves_Should_Return_Left_And_Right_Corner)
{
    Man Tmp{BLACK};
    const std::string expectedTab[3][3]
            {
                    {"","",""},
                    {"","O",""},
                    {"X","","X"}
            };
    std::string tab[3][3] {};
    const int midX = 1, midY = 1;
    tab[midX][midY] = 'O';
    for(const auto& [x,y] : Tmp.getMoves())
        tab[midX+x][midY+y] = 'X';

    for(int i = 0;i < 3; i++)
        for(int j = 0; j < 3; j++)
            ASSERT_EQ(tab[i][j],expectedTab[i][j]);
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
    const int midX {3}, midY {3};

    std::string tab[5][5];
    tab[midX][midY] = 'O';
    for(const auto& [x,y]: Tmp.getMoves())
        if(midX+x < 5 and midY + y < 5)
            tab[midX+x][midY+y] = 'X';

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
    const int midX {3}, midY {3};

    std::string tab[5][5];
    tab[midX][midY] = 'O';
    for(const auto& [x,y]: Tmp.getMoves())
        if(midX+x < 5 and midY + y < 5)
            tab[midX+x][midY+y] = 'X';

    for(int i = 0;i < 5; i++)
        for(int j = 0; j < 5; j++)
            ASSERT_EQ(tab[i][j], expectedTab[i][j]);
}