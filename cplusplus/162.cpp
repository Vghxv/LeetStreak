#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        if (nums.size() == 1) {
            return 0;
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
              
            if (mid == 0) {
                if (nums[mid] > nums[mid + 1]) {
                    return mid;
                }
                else {
                    left = mid + 1;
                }
            }
            else if (mid == nums.size() - 1) {
                if (nums[mid] > nums[mid - 1]) {
                    return mid;
                }
                else {
                    right = mid - 1;
                }
            }
            else if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            else if (nums[mid] < nums[mid - 1]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};

class FindPeakElementTest : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(FindPeakElementTest, Test1)
{
    vector<int> nums = {1, 2, 3, 1};
    int result = solution.findPeakElement(nums);
    EXPECT_TRUE(result == 2);
}

TEST_F(FindPeakElementTest, Test2)
{
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    int result = solution.findPeakElement(nums);
    EXPECT_TRUE(result == 1 || result == 5);
}

TEST_F(FindPeakElementTest, Test3)
{
    vector<int> nums = {1};
    int result = solution.findPeakElement(nums);
    EXPECT_EQ(result, 0);
}

TEST_F(FindPeakElementTest, Test4)
{
    vector<int> nums = {1, 2};
    int result = solution.findPeakElement(nums);
    EXPECT_TRUE(result == 1);
}

TEST_F(FindPeakElementTest, Test5)
{
    vector<int> nums = {3, 2, 1};
    int result = solution.findPeakElement(nums);
    EXPECT_TRUE(result == 0);
}

TEST_F(FindPeakElementTest, Test6)
{
    vector<int> nums = {1, 3, 2};
    int result = solution.findPeakElement(nums);
    EXPECT_TRUE(result == 1);
}

TEST_F(FindPeakElementTest, Test7)
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int result = solution.findPeakElement(nums);
    EXPECT_EQ(result, 4);
}

TEST_F(FindPeakElementTest, Test8)
{
    vector<int> nums = {5, 4, 3, 2, 1};
    int result = solution.findPeakElement(nums);
    EXPECT_EQ(result, 0);
}

TEST_F(FindPeakElementTest, Test9)
{
    vector<int> nums = {1, 2, 3, 4, 3, 2, 1};
    int result = solution.findPeakElement(nums);
    EXPECT_TRUE(result == 3);
}

TEST_F(FindPeakElementTest, Test10)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int result = solution.findPeakElement(nums);
    EXPECT_EQ(result, 5);
}

TEST_F(FindPeakElementTest, Test11)
{
    vector<int> nums = {6, 5, 4, 3, 2, 1};
    int result = solution.findPeakElement(nums);
    EXPECT_EQ(result, 0);
}

TEST_F(FindPeakElementTest, Test12)
{
    vector<int> nums = {1, 3, 2, 1};
    int result = solution.findPeakElement(nums);
    EXPECT_TRUE(result == 1);
}

TEST_F(FindPeakElementTest, Test13)
{
    vector<int> nums = {1, 2, 3, 4, 5, 4};
    int result = solution.findPeakElement(nums);
    EXPECT_TRUE(result == 4);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}