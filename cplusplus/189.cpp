#include <algorithm>
#include <cassert>
#include <gtest/gtest.h>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;
        vector<int> tmp(n);
        for (int i = 0; i < n; i++) {
            if (i < k) {
                tmp[i] = nums[n - k + i];
            }
            else {
                tmp[i] = nums[i - k];
            }
        }
        nums = tmp;
    }

    void rotate2(vector<int> &nums, int k)
    {
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k % nums.size());
        reverse(nums.begin() + k % nums.size(), nums.end());
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
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    vector<int> expected = {5, 6, 7, 1, 2, 3, 4};
    solution.rotate(nums, k);
    EXPECT_EQ(nums, expected);
}

TEST_F(Testing, Case2)
{
    vector<int> nums = {-1, -100, 3, 99};
    int k = 2;
    vector<int> expected = {3, 99, -1, -100};
    solution.rotate(nums, k);
    EXPECT_EQ(nums, expected);
}

TEST_F(Testing, Case1_2)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    vector<int> expected = {5, 6, 7, 1, 2, 3, 4};
    solution.rotate2(nums, k);
    EXPECT_EQ(nums, expected);
}

TEST_F(Testing, Case2_2)
{
    vector<int> nums = {-1, -100, 3, 99};
    int k = 2;
    vector<int> expected = {3, 99, -1, -100};
    solution.rotate2(nums, k);
    EXPECT_EQ(nums, expected);
}
