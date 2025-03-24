#include <cassert>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        int i = m - 1;
        int j = n - 1;
        int cur = m + n - 1;
        while (i > -1 && j > -1) {
            if (nums1[i] > nums2[j]) {
                nums1[cur] = nums1[i];
                i--;
                cur--;
            }
            else {
                nums1[cur] = nums2[j];
                j--;
                cur--;
            }
        }
        while (j > -1) {
            nums1[cur] = nums2[j];
            j--;
            cur--;
        }
        return;
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
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    solution.merge(nums1, m, nums2, n);
    vector<int> expected = {1, 2, 2, 3, 5, 6};
    EXPECT_EQ(nums1, expected);
}

TEST_F(Testing, Case2)
{
    vector<int> nums1 = {1};
    int m = 1;
    vector<int> nums2 = {};
    int n = 0;
    solution.merge(nums1, m, nums2, n);
    vector<int> expected = {1};
    EXPECT_EQ(nums1, expected);
}

TEST_F(Testing, Case3)
{
    vector<int> nums1 = {0};
    int m = 0;
    vector<int> nums2 = {1};
    int n = 1;
    solution.merge(nums1, m, nums2, n);
    vector<int> expected = {1};
    EXPECT_EQ(nums1, expected);
}