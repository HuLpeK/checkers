
#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "../src/Participant.hpp"

class ParticipantTest : public ::testing::Test {
protected:
    ParticipantTest() = default;

    ~ParticipantTest() override = default;

    void SetUp() override {};

    void TearDown() override {};
};

void clearBoard(Board& bo);

TEST_F(ParticipantTest, Test_Player_ToUpperCaseTest_Should_Return_Char_In_UpperIndex)
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


TEST_F(ParticipantTest, Bot_Test_Check_If_Performs_Man_White_Not_Bicie_Move)
{
    Board bo;
    Bot Pl(WHITE,bo);
    clearBoard(bo);

    bo.at(1,2) = Man(WHITE);

    const auto mv = Pl.makeMove();
    EXPECT_TRUE((mv.second == std::pair<int,int>{0,3} or mv.second == std::pair<int,int>{3,3}) and (mv.first == std::pair<int,int>{1,2}));
}

TEST_F(ParticipantTest, Bot_Test_Check_If_Performs_Man_Black_Not_Bicie_Move)
{
    Board bo;
    Bot Pl(BLACK,bo);
    clearBoard(bo);

    bo.at(1,2) = Man(BLACK);

    const auto mv = Pl.makeMove();
    EXPECT_TRUE((mv.second == std::pair<int,int>{0,1} or mv.second == std::pair{3,1}) and (mv.first == std::pair{1,2}));
}

TEST_F(ParticipantTest, Bot_Test_Check_if_Performs_King_White_Not_Bicie_Move)
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

TEST_F(ParticipantTest, Bot_Test_Check_if_Performs_King_BLACK_Not_Bicie_Move)
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