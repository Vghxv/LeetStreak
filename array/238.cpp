#include <gtest/gtest.h>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> res(nums.size(), 1);
        for (int i = nums.size() - 1; i > 0; i--) {
            res[i - 1] = nums[i] * res[i];
        }
        for (int i = 1; i < nums.size(); i++) {
            if (i != nums.size() - 1) {
                nums[i] = nums[i] * nums[i - 1];
            }
            res[i] = res[i] * nums[i - 1];
        }
        return res;
    }
};

class Testing : public testing::Test {
public:
    Solution sol;
    void SetUp() {}
    void TearDown() {}
};

TEST_F(Testing, test_1)
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = {24, 12, 8, 6};
    EXPECT_EQ(sol.productExceptSelf(nums), res);
}

TEST_F(Testing, test_2)
{
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> res = {120, 60, 40, 30, 24};
    EXPECT_EQ(sol.productExceptSelf(nums), res);
}

TEST_F(Testing, test_3)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    vector<int> res = {720, 360, 240, 180, 144, 120};
    EXPECT_EQ(sol.productExceptSelf(nums), res);
}

TEST_F(Testing, test_4)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    vector<int> res = {5040, 2520, 1680, 1260, 1008, 840, 720};
    EXPECT_EQ(sol.productExceptSelf(nums), res);
}
