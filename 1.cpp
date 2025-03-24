#include <gtest/gtest.h>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end()) {
                return {hash[complement], i};
            }
            hash[nums[i]] = i;
        }
        return {};
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
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = {0, 1};
    EXPECT_EQ(solution.twoSum(nums, target), result);
}

TEST_F(Testing, Case2)
{
    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> result = {1, 2};
    EXPECT_EQ(solution.twoSum(nums, target), result);
}

TEST_F(Testing, Case3)
{
    vector<int> nums = {3, 3};
    int target = 6;
    vector<int> result = {0, 1};
    EXPECT_EQ(solution.twoSum(nums, target), result);
}
