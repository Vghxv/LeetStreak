#include <gtest/gtest.h>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) != map.end() && i - map[nums[i]] <= k) {
                return true;
            }
            map[nums[i]] = i;
        }
        return false;
    }
};

class TestSolution : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(TestSolution, t1)
{
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    bool output = sol.containsNearbyDuplicate(nums, k);
    bool expected = true;
    ASSERT_EQ(output, expected);
}

TEST_F(TestSolution, t2)
{
    vector<int> nums = {1, 0, 1, 1};
    int k = 1;
    bool output = sol.containsNearbyDuplicate(nums, k);
    bool expected = true;
    ASSERT_EQ(output, expected);
}