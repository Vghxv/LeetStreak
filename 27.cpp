#include <cassert>
#include <gtest/gtest.h>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
            }
            else {
                i++;
            }
        }
        return nums.size();
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
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    int result = 2;
    EXPECT_EQ(solution.removeElement(nums, val), result);
}

TEST_F(Testing, Case2)
{
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int result = 5;
    EXPECT_EQ(solution.removeElement(nums, val), result);
}
