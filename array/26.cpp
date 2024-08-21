#include <cassert>
#include <gtest/gtest.h>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int i = 0;
        int j = 1;

        while (j < nums.size()) {
            if (nums[i] == nums[j]) {
                j++;
            }
            else {
                nums[i + 1] = nums[j];
                i++;
            }
        }

        return i + 1;
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
    vector<int> nums = {1, 1, 2};
    int result = 2;
    EXPECT_EQ(solution.removeDuplicates(nums), result);
}

TEST_F(Testing, Case2)
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int result = 5;
    EXPECT_EQ(solution.removeDuplicates(nums), result);
}
