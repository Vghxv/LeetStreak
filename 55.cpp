#include <algorithm>
#include <cassert>
#include <gtest/gtest.h>
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1) {
            return true;
        }
        if (nums[0] == 0) {
            return false;
        }
        if (find(nums.begin(), nums.end() - 1, 0) == nums.end() - 1) {
            return true;
        }
        int evidence = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == 0) {
                evidence = 0;
                int j = i - 1;
                while (j >= 0) {
                    if (nums[j] > i - j) {
                        evidence++;
                    }
                    j--;
                }
                if (evidence == 0) {
                    return false;
                }
            }
        }
        return true;
    }
};

class Testing : public testing::Test {
public:
    Solution solution;
    void SetUp() {}

    void TearDown() {}
};

TEST_F(Testing, Case1)
{
    vector<int> nums = {2, 3, 1, 1, 4};
    bool expected = true;
    EXPECT_EQ(solution.canJump(nums), expected);
}

TEST_F(Testing, Case2)
{
    vector<int> nums = {3, 2, 1, 0, 4};
    bool expected = false;
    EXPECT_EQ(solution.canJump(nums), expected);
}

TEST_F(Testing, Case3)
{
    vector<int> nums = {0};
    bool expected = true;
    EXPECT_EQ(solution.canJump(nums), expected);
}

TEST_F(Testing, Case4)
{
    vector<int> nums = {1, 0, 1, 0};
    bool expected = false;
    EXPECT_EQ(solution.canJump(nums), expected);
}

TEST_F(Testing, Case5)
{
    vector<int> nums = {1, 1, 1, 1};
    bool expected = true;
    EXPECT_EQ(solution.canJump(nums), expected);
}

TEST_F(Testing, Case6)
{
    vector<int> nums = {1, 1, 1, 1, 0};
    bool expected = true;
    EXPECT_EQ(solution.canJump(nums), expected);
}

TEST_F(Testing, Case7)
{
    vector<int> nums = {0, 1};
    bool expected = false;
    EXPECT_EQ(solution.canJump(nums), expected);
}

TEST_F(Testing, Case8)
{
    vector<int> nums = {1, 1, 1, 0};
    bool expected = true;
    EXPECT_EQ(solution.canJump(nums), expected);
}

TEST_F(Testing, Case9)
{
    vector<int> nums = {2, 0, 1, 0, 1};
    bool expected = false;
    EXPECT_EQ(solution.canJump(nums), expected);
}

TEST_F(Testing, Case10)
{
    vector<int> nums = {2, 0, 0};
    bool expected = true;
    EXPECT_EQ(solution.canJump(nums), expected);
}
