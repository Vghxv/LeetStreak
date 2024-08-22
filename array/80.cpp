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

    int removeDuplicates2(vector<int> &nums)
    {
        int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (j == 1 || nums[i] != nums[j - 2]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
    int removeDuplicates3(vector<int> &nums)
    {
        int i = 0;
        for (auto ele : nums) {
            if (i == 0 || i == 1 || nums[i - 2] != ele) {
                nums[i++] = ele;
            }
        }
        return i;
    }
};

class Testing : public testing::Test {
public:
    Solution solution;
    void SetUp() {}

    void TearDown() {}
};

class Testing2 : public testing::Test {
public:
    Solution solution;
    void SetUp() {}

    void TearDown() {}
};

class Testing3 : public testing::Test {
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

TEST_F(Testing2, Case1)
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int expected = 5;
    EXPECT_EQ(solution.removeDuplicates2(nums), expected);
}

TEST_F(Testing2, Case2)
{
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int expected = 7;
    EXPECT_EQ(solution.removeDuplicates2(nums), expected);
}

TEST_F(Testing2, Case3)
{
    vector<int> nums = {1, 1, 1, 2, 2, 2};
    int expected = 4;
    EXPECT_EQ(solution.removeDuplicates2(nums), expected);
}

TEST_F(Testing3, Case1)
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int expected = 5;
    EXPECT_EQ(solution.removeDuplicates3(nums), expected);
}

TEST_F(Testing3, Case2)
{
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int expected = 7;
    EXPECT_EQ(solution.removeDuplicates3(nums), expected);
}

TEST_F(Testing3, Case3)
{
    vector<int> nums = {1, 1, 1, 2, 2, 2};
    int expected = 4;
    EXPECT_EQ(solution.removeDuplicates3(nums), expected);
}
