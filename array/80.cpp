#include <cassert>
#include <gtest/gtest.h>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int> &nums)
    {
        int counter = 0;
        int current_num = 0;
        int final_size = nums.size();
        int shift = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (current_num != nums[i]) {
                if (counter > 2) {
                    final_size -= counter - 2;
                    shift += counter - 2;
                }
                current_num = nums[i];
                counter = 1;
            }
            else {
                counter += 1;
            }
            nums[i - shift] = nums[i];
        }
        if (counter > 2) {
            final_size -= counter - 2;
        }
        return final_size;
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
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int expected = 5;
    EXPECT_EQ(solution.removeDuplicates(nums), expected);
}

TEST_F(Testing, Case2)
{
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int expected = 7;
    EXPECT_EQ(solution.removeDuplicates(nums), expected);
}

TEST_F(Testing, Case3)
{
    vector<int> nums = {1, 1, 1, 2, 2, 2};
    int expected = 4;
    EXPECT_EQ(solution.removeDuplicates(nums), expected);
}