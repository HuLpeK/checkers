/***
 * \file logic_test.cc
 * @author Hubert Kulpaczyński
 */
#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "../src/logic.hpp"
#include "../src/board.hpp"

void clear(Board& bo)
{
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            bo.at(i,j) = Piece();
}

bool operator ==(std::pair<int,int> a, std::pair<int,int> b)
{
    return a.first == b.first and a.second == b.second;
}
TEST(Logic, Check_If_Win_Occured_Should_Return_NONE)
{
    Board bo;
    EXPECT_EQ(Logic::win(bo), NONE);
}

TEST(LogicTest, Check_If_Win_Occured_Should_Return_BLACK)
{
    Board bo;
    clear(bo);
    bo.at(2,2) = Man(BLACK);

    EXPECT_EQ(Logic::win(bo),BLACK);
}

TEST(LogicTest, Check_If_Win_Occured_Should_Return_WHITE)
{
    Board bo;
    clear(bo);
    bo.at(2,4) = Man(WHITE);

    EXPECT_EQ(Logic::win(bo),WHITE);
}

TEST(LogicTest, Check_If_Move_Is_Legal_Normal_Man_Move_Left_up)
{
    Board bo;
    clear(bo);

    bo.at(1,2) = Man(WHITE);
    std::pair<int,int> from {1,2};
    std::pair<int,int> to {2,3};
    std::pair<std::pair<int,int>,std::pair<int,int>> mv {from,to};
    EXPECT_TRUE(Logic::legalMove(bo,mv,WHITE));
}

TEST(LogicTest, Check_If_Move_Is_Legal_Normal_Man_Move_Right_Up)
{
    Board bo;
    clear(bo);

    bo.at(1,2) = Man(WHITE);
    std::pair<int,int> from {1,2};
    std::pair<int,int> to {0,3};
    std::pair<std::pair<int,int>,std::pair<int,int>> mv {from,to};
    EXPECT_TRUE(Logic::legalMove(bo,mv,WHITE));
}


TEST(LogicTest, Check_If_Move_Is_Legal_Normal_Man_Move_Left_Down)
{
    Board bo;
    clear(bo);

    bo.at(1,2) = Man(BLACK);
    std::pair<int,int> from {1,2};
    std::pair<int,int> to {0,1};
    std::pair<std::pair<int,int>,std::pair<int,int>> mv {from,to};
    EXPECT_TRUE(Logic::legalMove(bo,mv,BLACK));
}

TEST(LogicTest, Check_If_Move_Is_Legal_Normal_Man_Wrong_Color)
{
    Board bo;
    clear(bo);

    bo.at(1,2) = Man(BLACK);
    std::pair<int,int> from {1,2};
    std::pair<int,int> to {0,1};
    std::pair<std::pair<int,int>,std::pair<int,int>> mv {from,to};
    EXPECT_FALSE(Logic::legalMove(bo,mv,WHITE));
}

TEST(LogicTest, Check_If_Move_Is_Legal_Normal_Man_Occupied_Spot)
{
    Board bo;
    clear(bo);

    bo.at(1,2) = Man(WHITE);
    bo.at(2,3) = Man(BLACK);
    std::pair<int,int> from {1,2};
    std::pair<int,int> to {2,3};
    std::pair<std::pair<int,int>,std::pair<int,int>> mv {from,to};
    EXPECT_FALSE(Logic::legalMove(bo,mv,WHITE));
}

TEST(LogicTest, Check_Attack_Move)
{
    Board bo;
    clear(bo);
    bo.at(1,2) = Man(WHITE);
    bo.at(2,3) = Man(BLACK);
    std::pair<int,int> from {1,2};
    std::pair<int,int> to {3,4};
    std::pair<std::pair<int,int>,std::pair<int,int>> mv {from,to};
    EXPECT_TRUE(Logic::legalMove(bo,mv,WHITE));
}

TEST(LogicTest, Check_Attack_Move_Next_Occupied)
{
    Board bo;
    clear(bo);
    bo.at(1,2) = Man(WHITE);
    bo.at(2,3) = Man(BLACK);
    bo.at(3,4) = Man(BLACK);
    std::pair<int,int> from {1,2};
    std::pair<int,int> to {3,4};
    std::pair<std::pair<int,int>,std::pair<int,int>> mv {from,to};
    EXPECT_FALSE(Logic::legalMove(bo,mv,WHITE));
}

TEST(LogicTest, Move_Not_Diagonal)
{
    Board bo;
    clear(bo);
    bo.at(1,2) = Man(WHITE);

    std::pair<int,int> from {1,2};
    std::pair<int,int> to {1,3};
    std::pair<std::pair<int,int>,std::pair<int,int>> mv {from,to};
    EXPECT_FALSE(Logic::legalMove(bo,mv,WHITE));
}

TEST(LogicTest, Check_If_Possible_Bicie_White_Move_Should_Return_True)
{
    Board bo;
    clear(bo);

    bo.at(1,2) = Man(WHITE); //H1
    // {1,2} -> {B,3}
    bo.at(2,3) = Man(BLACK);

    EXPECT_TRUE(Logic::possibleBicie(bo,WHITE,{1,2}));
}

TEST(LogicTest, Check_If_Possible_Bicie_White_Move_Board_Should_Return_True)
{
    Board bo;
    clear(bo);

    bo.at(1,2) = Man(WHITE); //H1
    // {1,2} -> {B,3}
    bo.at(2,3) = Man(BLACK);
    std::pair<int,int> expected {-1,-1};
    EXPECT_FALSE(expected == Logic::possibleBicie(bo,WHITE));
}

TEST(LogicTest, Check_If_Base_Board_Is_Bicie_Possible_Should_Return_Not)
{
    Board bo;
    std::pair<int,int> expected {-1,-1};
    EXPECT_TRUE(expected == Logic::possibleBicie(bo,WHITE) and expected == Logic::possibleBicie(bo,BLACK));
}