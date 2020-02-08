#include "lottery.h"
#include "gtest/gtest.h"

class lotteryTest : public testing::Test
{
public:
    void makeTestData()
    {
        lottery.addMember(memberInfo(1, "name1", "department1", "team1"));
        lottery.addMember(memberInfo(2, "name2", "department1", "team1"));
        lottery.addMember(memberInfo(3, "name3", "department1", "team1"));
        lottery.addMember(memberInfo(4, "name4", "department1", "team2"));
        lottery.addMember(memberInfo(5, "name5", "department1", "team2"));
        lottery.addMember(memberInfo(6, "name6", "department1", "team3"));
        lottery.addMember(memberInfo(7, "name7", "department1", "team3"));
        lottery.addMember(memberInfo(8, "name8", "department1", "team3"));
        lottery.addMember(memberInfo(9, "name9", "department1", "team3"));
        lottery.addMember(memberInfo(10, "name10", "department1", "team4"));
        lottery.addMember(memberInfo(11, "name11", "department2", "team4"));
        lottery.addMember(memberInfo(12, "name12", "department2", "team5"));
        lottery.addMember(memberInfo(13, "name13", "department2", "team6"));
        lottery.addMember(memberInfo(14, "name14", "department2", "team6"));
        lottery.addMember(memberInfo(15, "name15", "department2", "team6"));
    }

    virtual void SetUp()
    {
        makeTestData();
    }

    virtual void TearDown() 
    {

    }

    Lottery lottery;
};

TEST_F(lotteryTest, addMember)
{
    EXPECT_TRUE(lottery.addMember(memberInfo(16, "name16", "department3", "team6")));
    EXPECT_FALSE(lottery.addMember(memberInfo(1, "name1", "department1", "team1")));
}

TEST_F(lotteryTest, delMember)
{
    EXPECT_TRUE(lottery.delMember(1));
    EXPECT_FALSE(lottery.delMember(16));
}

TEST_F(lotteryTest, setRatio)
{
    EXPECT_TRUE(lottery.setRatio(1, 2));
    EXPECT_FALSE(lottery.setRatio(16, 2));
}

TEST_F(lotteryTest, setDepartmentRatio)
{
    EXPECT_TRUE(lottery.setDepartmentRatio("department1", 2));
    EXPECT_FALSE(lottery.setDepartmentRatio("department3", 2));
}

TEST_F(lotteryTest, setTeamRatio)
{
    EXPECT_TRUE(lottery.setTeamRatio("team1", 2));
    EXPECT_FALSE(lottery.setTeamRatio("team7", 2));
}

TEST_F(lotteryTest, normalDrawPutBcak)
{
     EXPECT_TRUE(lottery.normalDraw(5, true));
    EXPECT_TRUE(lottery.normalDraw(12, true));
    EXPECT_FALSE(lottery.normalDraw(16, true));
    EXPECT_FALSE(lottery.normalDraw(-1, true));
}

TEST_F(lotteryTest, normalDrawNotPutBcak)
{
    EXPECT_TRUE(lottery.normalDraw(5));
    EXPECT_FALSE(lottery.normalDraw(12));
    EXPECT_FALSE(lottery.normalDraw(16));
}

TEST_F(lotteryTest, departmentDrawPutBcak)
{
    EXPECT_TRUE(lottery.departmentDraw("department1", 5, true));
    EXPECT_TRUE(lottery.departmentDraw("department1", 8, true));
    EXPECT_FALSE(lottery.departmentDraw("department1", 12, true));

    EXPECT_FALSE(lottery.departmentDraw("department3", 5, true));
}

TEST_F(lotteryTest, departmentDrawNotPutBcak)
{
    EXPECT_TRUE(lottery.departmentDraw("department1", 5));
    EXPECT_FALSE(lottery.departmentDraw("department1", 8));
    EXPECT_FALSE(lottery.departmentDraw("department1", 12));

    EXPECT_FALSE(lottery.departmentDraw("department3", 5));
}

TEST_F(lotteryTest, teamDrawPutBcak)
{
    EXPECT_TRUE(lottery.teamDraw("team1", 2, true));
    EXPECT_TRUE(lottery.teamDraw("team1", 2, true));
    EXPECT_FALSE(lottery.teamDraw("team1", 5, true));

    EXPECT_FALSE(lottery.departmentDraw("team10", 5, true));
}

TEST_F(lotteryTest, teamDrawNotPutBcak)
{
    EXPECT_TRUE(lottery.teamDraw("team1", 2));
    EXPECT_FALSE(lottery.teamDraw("team1", 2));
    EXPECT_FALSE(lottery.teamDraw("team1", 5));

    EXPECT_FALSE(lottery.departmentDraw("team10", 5));
}
