/// @file Participant_test.cc
/// @author Hubert Kulpaczyński
#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "../src/Participant.hpp"

class PlayerTest : public ::testing::Test {
protected:
    PlayerTest() = default;

    ~PlayerTest() override = default;

    void SetUp() override {};

    void TearDown() override {};
};

class BotTest : public ::testing::Test {
protected:
    BotTest() = default;

    ~BotTest() override = default;

    void SetUp() override {};

    void TearDown() override {};
};

void clearBoard(Board& bo);
/// @test Checks if UpperCase converstion works.\n Should return char in UpperCase.
TEST_F(PlayerTest, Test_Player_ToUpperCaseTest_Should_Return_Char_In_UpperIndex)
{
    std::vector<char> expected;
    expected.reserve(('Z'-'A')+('z'-'a'));
    for(char i = 'A'; i <= 'Z'; i++)
        expected.push_back(i);
    for(char i = 'A'; i <= 'Z'; i++)
        expected.push_back(i);
    expected.shrink_to_fit();

    std::vector<char> ans;
    ans.reserve(('Z'-'A')+('z'-'a'));
    for(char i = 'A'; i <= 'Z'; i++)
        ans.push_back(Player::toUpperCase(i));
    for(char i = 'a'; i <= 'z'; i++)
        ans.push_back(Player::toUpperCase(i));
    ans.shrink_to_fit();

    EXPECT_EQ(ans.size(),expected.size());
    for(unsigned i = 0; i < ans.size(); i++)
        EXPECT_EQ(ans[i],expected[i]);
}

/// @test Check if move is possible on blank Board for BLACK Man.
TEST_F(BotTest, Bot_Test_Check_If_Performs_Man_White_Not_Bicie_Move)
{
    Board bo;
    Bot Pl(WHITE,bo);
    clearBoard(bo);

    bo.at(1,2) = Man(WHITE);

    const auto mv = Pl.makeMove();
    EXPECT_TRUE((mv.second == std::pair<int,int>{0,3} or mv.second == std::pair<int,int>{3,3}) and (mv.first == std::pair<int,int>{1,2}));
}
/// @test Check if move is possible on blank Board for WHITE Man.
TEST_F(BotTest, Bot_Test_Check_If_Performs_Man_Black_Not_Bicie_Move)
{
    Board bo;
    Bot Pl(BLACK,bo);
    clearBoard(bo);

    bo.at(1,2) = Man(BLACK);

    const auto mv = Pl.makeMove();
    EXPECT_TRUE((mv.second == std::pair<int,int>{0,1} or mv.second == std::pair{3,1}) and (mv.first == std::pair{1,2}));
}

/// @test Check if move is possible on blank Board for WHITE King.
TEST_F(BotTest, Bot_Test_Check_if_Performs_King_White_Not_Bicie_Move)
{
    Board bo;
    clearBoard(bo);
    Bot Pl(WHITE,bo);
    bo.at(2,3) = King(WHITE);
    const auto mv = Pl.makeMove();
    const auto& [konX, konY] = mv.second;

    bool flag {false};
    const auto [x,y] = std::pair{2,3};
    for(const auto& [mvX, mvY] : King(WHITE).getMoves())
        if(std::pair{x+mvX,y+mvY} == std::pair{konX,konY})
            flag = true;
    EXPECT_TRUE((flag and mv.first == std::pair{2,3}));
}

/// @test Check if move is possible on blank Board for BLACK King.
TEST_F(BotTest, Bot_Test_Check_if_Performs_King_BLACK_Not_Bicie_Move)
{
    Board bo;
    clearBoard(bo);
    Bot Pl(BLACK,bo);
    bo.at(4,5) = King(BLACK);
    const auto mv = Pl.makeMove();
    const auto& [konX, konY] = mv.second;

    bool flag {false};
    const auto [x,y] = std::pair{4,5};
    for(const auto& [mvX, mvY] : King(WHITE).getMoves())
        if(std::pair{x+mvX,y+mvY} == std::pair{konX,konY})
            flag = true;
    EXPECT_TRUE((flag and mv.first == std::pair{4,5}));
}

/// @test Check if the closest to end Piece is moved for WHITE site.
TEST_F(BotTest, Bot_Test_Check_If_Furthes_Is_Moved_For_White)
{
    Board bo;
    clearBoard(bo);
    Bot Pl(WHITE,bo);

    bo.at(1,1) = Man(WHITE);
    bo.at(1,6) = Man(WHITE);

    bo.at(2,3) = Man(BLACK);
    bo.at(7,7) = Man(BLACK);

    const auto mv = Pl.makeMove();

    const auto& [from,to] = mv;
    EXPECT_TRUE((from == std::pair{1,6} and (to == std::pair{0,7} or to == std::pair{2,6})));
}

/// @test Check if the closest to end Piece is moved for BLACK site.
TEST_F(BotTest, Bot_Test_Check_If_Furthes_Is_Moved_For_Black)
{
    Board bo;
    clearBoard(bo);
    Bot Pl(BLACK,bo);

    bo.at(1,1) = Man(WHITE);
    bo.at(1,6) = Man(WHITE);

    bo.at(2,3) = Man(BLACK);
    bo.at(7,7) = Man(BLACK);

    const auto mv = Pl.makeMove();

    const auto& [from,to] = mv;
    EXPECT_TRUE((from == std::pair{2,3} and (to == std::pair{1,2} or to == std::pair{3,2})));
}

/// @test Check - if the closest to end Piece is illegal for BLACK
TEST_F(BotTest, Bot_Test_If_Furthest_Move_Is_Not_Legal_For_Black)
{
    Board bo;
    clearBoard(bo);
    Bot pl(BLACK,bo);
    bo.at(0,0) = Man(WHITE);
    bo.at(2,0) = Man(WHITE);
    bo.at(1,1) = Man(BLACK);


    bo.at(4,4) = Man(BLACK);
    const auto mv = pl.makeMove();

    const auto& [from, to] = mv;
    EXPECT_TRUE((from == std::pair{4,4}) and (to == std::pair{3,3} or to == std::pair{5,3}));
}

/// @test Check - if the closest to end Piece is illegal for WHITE.
TEST_F(BotTest, Bot_Test_If_Furthest_Move_Is_Not_Legal_For_White)
{
    Board bo;
    clearBoard(bo);
    Bot pl(WHITE,bo);

    bo.at(0,7) = Man(BLACK);
    bo.at(2,7) = Man(BLACK);
    bo.at(1,6) = Man(WHITE);

    bo.at(1,0) = Man(WHITE);

    const auto mv = pl.makeMove();
    const auto& [from, to] = mv;
    EXPECT_TRUE((from == std::pair{1,0} and (to == std::pair{0,1} or to == std::pair{2,1})));
}

/// @test Check - if the bicie is made working for WHITE.
TEST_F(BotTest, Bot_Test_If_Bicie_Is_Working_For_White)
{
    Board bo;
    clearBoard(bo);
    Bot pl(WHITE,bo);
    bo.at(1,2) = Man(WHITE);
    bo.at(2,3) = Man(BLACK);

    bo.at(6,6) = Man(WHITE);
    const auto mv = pl.makeMove();
    const auto& [from, to] = mv;


    EXPECT_TRUE((from == std::pair{1,2} and to == std::pair{3,4}));
}

/// @test Check - if the bicie is made working for BLACK.
TEST_F(BotTest, Bot_Test_If_Bicie_Is_Working_For_Black)
{
    Board bo;
    clearBoard(bo);
    Bot pl(BLACK,bo);
    bo.at(1,2) = Man(WHITE);
    bo.at(2,3) = Man(BLACK);

    bo.at(6,1) = Man(BLACK);

    const auto mv = pl.makeMove();
    const auto& [from, to] = mv;

    EXPECT_TRUE((from == std::pair{2,3} and to == std::pair{0,1}));
}