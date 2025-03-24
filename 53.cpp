#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
    public:
        tuple<int, int, int> crossing(vector<int>& nums, int left,int mid, int right) {
            int sum = 0;
            int lSum = INT_MIN;
            int rSum = INT_MIN;
            int lMin = mid;
            int rMax = mid + 1;
            for (auto i = mid; i >= left; i--) {
                sum += nums[i];
                if (sum > lSum) {
                    lSum = sum;
                    lMin = i;
                }
            }
            sum = 0;
            for (auto i = mid +1 ; i <= right; i++) {
                sum += nums[i];
                if (sum > rSum) {
                    rSum = sum;
                    rMax = i;
                }
            }
            return {lSum + rSum, lMin, rMax};
        
        }
        tuple<int, int, int> solver(vector<int>& nums, int left, int right) {
            if (left == right) {
                return {nums[left], left, right};
            }
            int mid = left + (right - left) / 2;
            
            auto [lSum, lMin, lMax] = solver(nums, left, mid);
            auto [rSum, rMin, rMax] = solver(nums, mid + 1, right);
            auto [cSum, cMin, cMax] = crossing(nums, left, mid, right);
            if (lSum >= rSum && lSum >= cSum) {
                return {lSum, lMin, lMax};
            }
            else if (rSum >= lSum && rSum >= cSum) {
                return {rSum, rMin, rMax};
            }
            else {
                return {cSum, cMin, cMax};
            }
        }
        int maxSubArray(vector<int>& nums) {
            tuple ans = solver(nums, 0, nums.size() - 1);
            return get<0>(ans);
        }
    };

class Testing : public testing::Test {
    public:
        Solution sol;
};


TEST_F(Testing, Case1) {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(sol.maxSubArray(nums), 6);
}

TEST_F(Testing, Case2) {
    vector<int> nums = {1};
    EXPECT_EQ(sol.maxSubArray(nums), 1);
}

TEST_F(Testing, Case3) {
    vector<int> nums = {5, 4, -1, 7, 8};
    EXPECT_EQ(sol.maxSubArray(nums), 23);
}

TEST_F(Testing, Case4) {
    vector<int> nums = {-1};
    EXPECT_EQ(sol.maxSubArray(nums), -1);
}

TEST_F(Testing, Case5) {
    vector<int> nums = {-2, 1};
    EXPECT_EQ(sol.maxSubArray(nums), 1);
}

TEST_F(Testing, Case6) {
    vector<int> nums = {-2, -1};
    EXPECT_EQ(sol.maxSubArray(nums), -1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
