#include <algorithm>
#include <gtest/gtest.h>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size() - 2) {
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                }
                else if (nums[left] + nums[right] < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
            while (i < nums.size() - 2 && nums[i] == nums[i + 1]) {
                i++;
            }
            i++;
        }
        return result;
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
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = {{-1, -1, 2}, {-1, 0, 1}};
    EXPECT_EQ(solution.threeSum(nums), result);
}

TEST_F(Testing, Case2)
{
    vector<int> nums = {0, 0, 0};
    vector<vector<int>> result = {{0, 0, 0}};
    EXPECT_EQ(solution.threeSum(nums), result);
}
