#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
    public:
        inline int solver(vector<int>& nums, int target, int left, int right) {      
            int mid = left + (right - left) / 2;

            if (left > right) {
                return left;
            }

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                return solver(nums, target, mid + 1, right);
            }
            else {
                return solver(nums, target, left, mid - 1);
            }

        }    
                
        int searchInsert(vector<int>& nums, int target) {
            return solver(nums, target, 0, nums.size() - 1);
        }
    };


class Testing : public testing::Test {
    public:
        Solution sol;
};

TEST_F(Testing, tc1) {
    vector<int> nums = {1, 3, 5, 6};
    EXPECT_EQ(sol.searchInsert(nums, 5), 2);
}

TEST_F(Testing, tc2) {
    vector<int> nums = {1, 3, 5, 6};
    EXPECT_EQ(sol.searchInsert(nums, 2), 1);
}

TEST_F(Testing, tc3) {
    vector<int> nums = {1, 3, 5, 6};
    EXPECT_EQ(sol.searchInsert(nums, 7), 4);
}

TEST_F(Testing, tc4) {
    vector<int> nums = {1, 3, 5, 6};
    EXPECT_EQ(sol.searchInsert(nums, 0), 0);
}

TEST_F(Testing, tc5) {
    vector<int> nums = {1};
    EXPECT_EQ(sol.searchInsert(nums, 0), 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
