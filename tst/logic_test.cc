/// @file logic_test.cc
/// @author Hubert Kulpaczyński
#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "../src/logic.hpp"
#include "../src/board.hpp"

void clearBoard(Board& bo);


bool operator ==(std::pair<int,int> a, std::pair<int,int> b)
{
    return a.first == b.first and a.second == b.second;
}
/// @test Check - DRAW.
TEST(LogicTest, Check_If_Win_Occured_Should_Return_NONE)
{
    Board bo;
    EXPECT_EQ(Logic::win(bo), NONE);
}
/// @test Check BLACK Win.
TEST(LogicTest, Check_If_Win_Occured_Should_Return_BLACK)
{
    Board bo;
    clearBoard(bo);
    bo.at(2,2) = Man(BLACK);

    EXPECT_EQ(Logic::win(bo),BLACK);
}
/// @test Check WHITE WIN.
TEST(LogicTest, Check_If_Win_Occured_Should_Return_WHITE)
{
    Board bo;
    clearBoard(bo);
    bo.at(2,4) = Man(WHITE);

    EXPECT_EQ(Logic::win(bo),WHITE);
}
/// @test Check Legality of WHITE Man moves - left UP.
TEST(LogicTest, Check_If_Move_Is_Legal_Normal_Man_Move_Left_up)
{
    Board bo;
    clearBoard(bo);

    bo.at(1,2) = Man(WHITE);
    std::pair<int,int> from {1,2};
    std::pair<int,int> to {2,3};
    std::pair<std::pair<int,int>,std::pair<int,int>> mv {from,to};
    EXPECT_TRUE(Logic::legalMove(bo,mv,WHITE));
}

/// @test Check Legality of WHITE Man moves - right UP.
TEST(LogicTest, Check_If_Move_Is_Legal_Normal_Man_Move_Right_Up)
{
    Board bo;
    clearBoard(bo);

    bo.at(1,2) = Man(WHITE);
    std::pair<int,int> from {1,2};
    std::pair<int,int> to {0,3};
    std::pair<std::pair<int,int>,std::pair<int,int>> mv {from,to};
    EXPECT_TRUE(Logic::legalMove(bo,mv,WHITE));
}

/// @test Check Legality of BLACK Man moves - left DOWN.
TEST(LogicTest, Check_If_Move_Is_Legal_Normal_Man_Move_Left_Down)
{
    Board bo;
    clearBoard(bo);

    bo.at(1,2) = Man(BLACK);
    std::pair<int,int> from {1,2};
    std::pair<int,int> to {0,1};
    std::pair<std::pair<int,int>,std::pair<int,int>> mv {from,to};
    EXPECT_TRUE(Logic::legalMove(bo,mv,BLACK));
}
/// @test Check Legality of move - Wrong Color.
TEST(LogicTest, Check_If_Move_Is_Legal_Normal_Man_Wrong_Color)
{
    Board bo;
    clearBoard(bo);

    bo.at(1,2) = Man(BLACK);
    std::pair<int,int> from {1,2};
    std::pair<int,int> to {0,1};
    std::pair<std::pair<int,int>,std::pair<int,int>> mv {from,to};
    EXPECT_FALSE(Logic::legalMove(bo,mv,WHITE));
}

/// @test Check Legality of move - Occupied Place.
TEST(LogicTest, Check_If_Move_Is_Legal_Normal_Man_Occupied_Spot)
{
    Board bo;
    clearBoard(bo);

    bo.at(1,2) = Man(WHITE);
    bo.at(2,3) = Man(BLACK);
    std::pair<int,int> from {1,2};
    std::pair<int,int> to {2,3};
    std::pair<std::pair<int,int>,std::pair<int,int>> mv {from,to};
    EXPECT_FALSE(Logic::legalMove(bo,mv,WHITE));
}

/// @test Check Legality of move - Attack Move.
TEST(LogicTest, Check_Attack_Move)
{
    Board bo;
    clearBoard(bo);
    bo.at(1,2) = Man(WHITE);
    bo.at(2,3) = Man(BLACK);
    std::pair<int,int> from {1,2};
    std::pair<int,int> to {3,4};
    std::pair<std::pair<int,int>,std::pair<int,int>> mv {from,to};
    EXPECT_TRUE(Logic::legalMove(bo,mv,WHITE));
}

/// @test Check Legality of move - Illegal Attack Occupied spot after person.
TEST(LogicTest, Check_Attack_Move_Next_Occupied)
{
    Board bo;
    clearBoard(bo);
    bo.at(1,2) = Man(WHITE);
    bo.at(2,3) = Man(BLACK);
    bo.at(3,4) = Man(BLACK);
    std::pair<int,int> from {1,2};
    std::pair<int,int> to {3,4};
    std::pair<std::pair<int,int>,std::pair<int,int>> mv {from,to};
    EXPECT_FALSE(Logic::legalMove(bo,mv,WHITE));
}

/// @test Check Legality of move - Move that is not diagonal.
TEST(LogicTest, Move_Not_Diagonal)
{
    Board bo;
    clearBoard(bo);
    bo.at(1,2) = Man(WHITE);

    std::pair<int,int> from {1,2};
    std::pair<int,int> to {1,3};
    std::pair<std::pair<int,int>,std::pair<int,int>> mv {from,to};
    EXPECT_FALSE(Logic::legalMove(bo,mv,WHITE));
}

/// @test Check possibility of Bicie.
TEST(LogicTest, Check_If_Possible_Bicie_White_Move_Should_Return_True)
{
    Board bo;
    clearBoard(bo);

    bo.at(1,2) = Man(WHITE); //H1
    // {1,2} -> {B,3}
    bo.at(2,3) = Man(BLACK);

    EXPECT_TRUE(Logic::possibleBicie(bo,WHITE,{1,2}));
}

/// @test Check possible of bicie throughout Whole Board.
TEST(LogicTest, Check_If_Possible_Bicie_White_Move_Board_Should_Return_True)
{
    Board bo;
    clearBoard(bo);

    bo.at(1,2) = Man(WHITE); //H1
    // {1,2} -> {B,3}
    bo.at(2,3) = Man(BLACK);
    std::pair<int,int> expected {-1,-1};
    EXPECT_FALSE(expected == Logic::possibleBicie(bo,WHITE));
}

/// @test Check possible of bicie on default position of Board.
TEST(LogicTest, Check_If_Base_Board_Is_Bicie_Possible_Should_Return_Not)
{
    Board bo;
    std::pair<int,int> expected {-1,-1};
    EXPECT_TRUE(expected == Logic::possibleBicie(bo,WHITE) and expected == Logic::possibleBicie(bo,BLACK));
}

/// @test That has benn found out during games.
TEST(LogicTest,Check_Test_From_RealLife)
{
    Board bo;
    clearBoard(bo);
    std::vector<std::pair<std::string,int>> whitePos = {
            {"A", 1},
            {"C", 1},
            {"E", 1},
            {"G", 1},
            {"B", 2},
            {"D", 2},
            {"F", 2},
            {"H", 2},
            {"E", 3},
            {"G", 3},
            {"B", 4},
            {"D", 4}};
    std::vector<std::pair<std::string,int>> blackPos = {
            {"C",5},
            {"D",6},
            {"F",6},
            {"H",6},
            {"A",7},
            {"C",7},
            {"E",7},
            {"G",7},
            {"B",8},
            {"D",8},
            {"F",8},
            {"H",8}
    };
    for(const auto& [x,y] : whitePos)
    bo.at((x[0]-'A'),y-1) = Man(WHITE);

    for(const auto& [x,y] : blackPos)
    bo.at(x[0]-'A',y-1) = Man(BLACK);

    std::pair<char,int> fr {'D',4};
    std::pair<char,int> to {'B',6};
    std::pair<std::pair<int,int>,std::pair<int,int>> mv {
            {fr.first-'A',fr.second-1},
            {to.first-'A',to.second-1}
    };
//    std::cout << bo << "\n";
    EXPECT_TRUE(Logic::legalMove(bo,mv,WHITE));
}

/// @test Check Legality of move - Move that is not diagonal.
TEST(LogicTest, Check_Illegal_Move_Not_Diagonal)
{
    Board bo;
    clearBoard(bo);
    bo.at(1,1) = Man(WHITE);
    std::pair<int,int> from {1,1};
    std::pair<int,int> to {3,4};
    std::pair<std::pair<int,int>,std::pair<int,int>> mv{from,to};
    EXPECT_FALSE(Logic::legalMove(bo,mv,WHITE));
}