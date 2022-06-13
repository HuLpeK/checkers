
/**
 * \file Participant_test
 * @author Hubert Kulpaczyński
 */
#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "../src/Participant.hpp"

class ParticipantTest : public ::testing::Test {
protected:
    ParticipantTest() = default;;

    ~ParticipantTest() override = default;;

    void SetUp() override {};

    void TearDown() override {};
};


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
