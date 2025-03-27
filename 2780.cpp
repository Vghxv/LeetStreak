#include <gtest/gtest.h>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int> &nums)
    {
        int t = 0;
        int count = 0;
        for (auto num : nums) {
            if (count == 0) {
                t = num;
            }
            count += (t == num) ? 1 : -1;
        }
        int totalcount = 0;
        for (auto num : nums) {
            if (num == t) {
                totalcount++;
            }
        }
        if (totalcount <= (nums.size() / 2)) {
            return -1;
        }
        int c = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == t) {
                c++;
            }
            if ((c * 2) > (i + 1) &&
                ((totalcount - c) * 2) > (nums.size() - i - 1)) {
                    return i;
            }
        }
        return -1;
    }
};

class Testing : public testing::Test {

public:
    Solution sol;
};

TEST_F(Testing, tc1)
{
    vector<int> nums = {1, 2, 2, 2};
    EXPECT_EQ(sol.minimumIndex(nums), 2);
}

TEST_F(Testing, tc2)
{
    vector<int> nums = {2, 1, 3, 1, 1, 1, 7, 1, 2, 1};
    EXPECT_EQ(sol.minimumIndex(nums), 4);
}

TEST_F(Testing, tc3)
{
    vector<int> nums = {3, 3, 3, 3, 7, 2, 2};
    EXPECT_EQ(sol.minimumIndex(nums), -1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
