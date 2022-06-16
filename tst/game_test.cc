
#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "../src/game.hpp"
#include "../src/logic.hpp"
class GameTest : public ::testing::Test
{
protected:
    GameTest() = default;
    ~GameTest() override = default;

    void SetUp() override {};
    void TearDown() override {};
};

void clearBo(Board& bo)
{
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            bo.at(i,j) = Piece();
}
TEST(GameTest,Test_1)
{
    Board bo;
    clearBo(bo);
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
    std::pair<char,int> to {'A',6};
    std::pair<std::pair<int,int>,std::pair<int,int>> mv {
            {fr.first-'A',fr.second-1},
            {to.first-'A',to.second-1}
    };
    EXPECT_TRUE(Logic::legalMove(bo,mv,WHITE));
}