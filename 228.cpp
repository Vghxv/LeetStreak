#include <climits>
#include <gtest/gtest.h>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        if (nums.size() == 0) {
            return {};
        }
        vector<string> res;
        int start = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == INT_MAX) {
                if (start == nums[i]) {
                    res.push_back(to_string(start));
                }
                else {
                    res.push_back(to_string(start) + "->" + to_string(nums[i]));
                }
            }
            else if (find(nums.begin(), nums.end(), nums[i] + 1) ==
                     nums.end()) {
                if (start == nums[i]) {
                    res.push_back(to_string(start));
                }
                else {
                    res.push_back(to_string(start) + "->" + to_string(nums[i]));
                }
                if (i != nums.size() - 1) {
                    start = nums[i + 1];
                }
            }
        }
        return res;
    }
};

class Testing : public testing::Test {
public:
    Solution s;
};

TEST_F(Testing, Case)
{
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    vector<string> res = s.summaryRanges(nums);
    vector<string> expected = {"0->2", "4->5", "7"};
    ASSERT_EQ(res, expected);
}

TEST_F(Testing, Case2)
{
    vector<int> nums = {0, 2, 3, 4, 6, 8, 9};
    vector<string> res = s.summaryRanges(nums);
    vector<string> expected = {"0", "2->4", "6", "8->9"};
    ASSERT_EQ(res, expected);
}

TEST_F(Testing, Case3)
{
    vector<int> nums = {};
    vector<string> res = s.summaryRanges(nums);
    vector<string> expected = {};
    ASSERT_EQ(res, expected);
}

TEST_F(Testing, Case4)
{
    vector<int> nums = {0};
    vector<string> res = s.summaryRanges(nums);
    vector<string> expected = {"0"};
    ASSERT_EQ(res, expected);
}

TEST_F(Testing, Case5)
{
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<string> res = s.summaryRanges(nums);
    vector<string> expected = {"0->9"};
    ASSERT_EQ(res, expected);
}

TEST_F(Testing, Case6)
{
    vector<int> nums = {-2147483648, -2147483647, 2147483647};
    vector<string> res = s.summaryRanges(nums);
    vector<string> expected = {"-2147483648->-2147483647", "2147483647"};
    ASSERT_EQ(res, expected);
}