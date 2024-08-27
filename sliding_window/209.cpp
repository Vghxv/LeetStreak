#include <algorithm>
#include <climits>
#include <gtest/gtest.h>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        if (find(nums.begin(), nums.end(), target) != nums.end()) {
            return 1;
        }
        int sum = 0;
        int minValue = INT_MAX;
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            sum += nums[right];
            while (sum >= target) {
                minValue = min(minValue, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return minValue == INT_MAX ? 0 : minValue;
    }
};

class Testing : public testing::Test {
public:
    Solution s;
};

TEST_F(Testing, case1)
{
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    EXPECT_EQ(s.minSubArrayLen(7, nums), 2);
}

TEST_F(Testing, case2)
{
    vector<int> nums = {1, 4, 4};
    EXPECT_EQ(s.minSubArrayLen(4, nums), 1);
}

TEST_F(Testing, case3)
{
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    EXPECT_EQ(s.minSubArrayLen(11, nums), 0);
}

TEST_F(Testing, case4)
{
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(s.minSubArrayLen(11, nums), 3);
}

TEST_F(Testing, case5)
{
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    EXPECT_EQ(s.minSubArrayLen(11, nums), 0);
}
