#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        int total = 0;
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int curMax = 0;
        int curMin = 0;
        for (auto num : nums) {
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);
            total += num;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};

class Testing : public testing::Test {
public:
    Solution sol;
};  

TEST_F(Testing, tc1) {
    vector<int> nums = {1, -2, 3, -2};
    EXPECT_EQ(sol.maxSubarraySumCircular(nums), 3);
}

TEST_F(Testing, tc2) {
    vector<int> nums = {5, -3, 5};
    EXPECT_EQ(sol.maxSubarraySumCircular(nums), 10);
}

TEST_F(Testing, tc3) {
    vector<int> nums = {3, -1, 2, -1};
    EXPECT_EQ(sol.maxSubarraySumCircular(nums), 4);
}

TEST_F(Testing, tc4) {
    vector<int> nums = {3, -2, 2, -3};
    EXPECT_EQ(sol.maxSubarraySumCircular(nums), 3);
}

TEST_F(Testing, tc5) {
    vector<int> nums = {-2, -3, -1};
    EXPECT_EQ(sol.maxSubarraySumCircular(nums), -1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
