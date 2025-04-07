#include <gtest/gtest.h>
#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int> &nums)
    {
        int steps = 0;
        int i = nums.size() - 1;
        while (i > 0) {
            int j = i - 1;
            int previous_index = 0;
            while (j > -1) {
                if (nums[j] > i - j - 1) {
                    previous_index = j;
                }
                j--;
            }
            i = previous_index;
            steps++;
        }
        return steps;
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
    int result = 2;
    EXPECT_EQ(solution.jump(nums), result);
}

TEST_F(Testing, Case2)
{
    vector<int> nums = {2, 3, 0, 1, 4};
    int result = 2;
    EXPECT_EQ(solution.jump(nums), result);
}

TEST_F(Testing, Case3)
{
    vector<int> nums = {1, 2, 3};
    int result = 2;
    EXPECT_EQ(solution.jump(nums), result);
}

TEST_F(Testing, Case4)
{
    vector<int> nums = {1, 1, 1, 1};
    int result = 3;
    EXPECT_EQ(solution.jump(nums), result);
}

TEST_F(Testing, Case5)
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int result = 4;
    EXPECT_EQ(solution.jump(nums), result);
}
