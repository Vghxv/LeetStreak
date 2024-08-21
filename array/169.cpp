#include <cassert>
#include <gtest/gtest.h>
#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }

            if (num == candidate) {
                count++;
            }
            else {
                count--;
            }
        }

        return candidate;
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
    vector<int> nums = {3, 2, 3};
    int expected = 3;
    EXPECT_EQ(solution.majorityElement(nums), expected);
}

TEST_F(Testing, Case2)
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int expected = 2;
    EXPECT_EQ(solution.majorityElement(nums), expected);
}
