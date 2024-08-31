#include <gtest/gtest.h>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> set(nums.begin(), nums.end());

        int longest = 0;
        for (int num : nums) {
            if (set.find(num - 1) == set.end()) {
                int currentNum = num;
                while (set.find(currentNum + 1) != set.end()) {
                    currentNum += 1;
                }
                longest = max(longest, currentNum - num + 1);
            }
        }
        return longest;
    }
    int longestConsecutive2(vector<int> &nums)
    {
        unordered_map<int, int> map;
        int longest = 0;
        for (int num : nums) {
            if (!map[num]) {
                map[num] = 1 + map[num - 1] + map[num + 1];
                map[num - map[num - 1]] = map[num];
                map[num + map[num + 1]] = map[num];
                longest = max(longest, map[num]);
            }
        }
        return longest;
    }
};

class TestSolution : public ::testing::Test {
    int testnum = 1;

protected:
    Solution sol;
    int (Solution::*func[2])(vector<int> &) = {&Solution::longestConsecutive,
                                               &Solution::longestConsecutive2};

public:
    void SetUp() override {}
    void TearDown() override {}
    void testSolution(vector<int> nums, int expected)
    {
        int output = (sol.*func[testnum])(nums);
        ASSERT_EQ(output, expected);
    }
};

TEST_F(TestSolution, t1)
{
    vector<int> nums = {100, 4, 200, 1, 3, 2, 2, 1};
    int expected = 4;
    testSolution(nums, expected);
}

TEST_F(TestSolution, t2)
{
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int expected = 9;
    testSolution(nums, expected);
}

TEST_F(TestSolution, t3)
{
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1, 9};
    int expected = 10;
    testSolution(nums, expected);
}

TEST_F(TestSolution, t4)
{
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1, 9, 10};
    int expected = 11;
    testSolution(nums, expected);
}
