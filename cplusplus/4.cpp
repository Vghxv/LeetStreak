#include <climits>
#include <gtest/gtest.h>
#include <vector>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int s1 = nums1.size();
        int s2 = nums2.size();
        if (s1 < s2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int l = 0;
        int r = s2 * 2;
        while (l <= r) {
            int mid2 = (l + r) / 2;
            int mid1 = s1 + s2 - mid2;
            double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];
            double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
            double R1 = (mid1 == s1 * 2) ? INT_MAX : nums1[mid1 / 2];
            double R2 = (mid2 == s2 * 2) ? INT_MAX : nums2[mid2 / 2];
            if (L1 > R2) {
                l = mid2 + 1;
            }
            else if (L2 > R1) {
                r = mid2 - 1;
            }
            else {
                return (max(L1, L2) + min(R1, R2)) / 2;
            }
        }
        return -1;
    }
};

class Testing : public testing::Test {
public:
    Solution s;
    void SetUp() {}
    void TearDown() {}
};

TEST_F(Testing, testfindMedianSortedArrays)
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double res = s.findMedianSortedArrays(nums1, nums2);
    double expected = 2.0;
    EXPECT_EQ(res, expected);
}

TEST_F(Testing, testfindMedianSortedArrays2)
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    double res = s.findMedianSortedArrays(nums1, nums2);
    double expected = 2.5;
    EXPECT_EQ(res, expected);
}

TEST_F(Testing, testfindMedianSortedArrays3)
{
    vector<int> nums1 = {0, 0};
    vector<int> nums2 = {0, 0};
    double res = s.findMedianSortedArrays(nums1, nums2);
    double expected = 0.0;
    EXPECT_EQ(res, expected);
}
