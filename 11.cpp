#include <algorithm>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        for (int i = 0, j = height.size() - 1; i < j;) {
            int h = min(height[i], height[j]);
            int w = j - i;
            int area = h * w;
            max_area = max(max_area, area);
            if (height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        return max_area;
    }
};

class Testing : public testing::Test {
public:
    Solution s;
};

TEST_F(Testing, BasicTest)
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    EXPECT_EQ(s.maxArea(height), 49);
}

TEST_F(Testing, NoSolution)
{
    vector<int> height = {1, 1};
    EXPECT_EQ(s.maxArea(height), 1);
}

TEST_F(Testing, MultipleSolutions)
{
    vector<int> height = {4, 3, 2, 1, 4};
    EXPECT_EQ(s.maxArea(height), 16);
}

TEST_F(Testing, NegativeNumbers)
{
    vector<int> height = {1, 2, 1};
    EXPECT_EQ(s.maxArea(height), 2);
}

TEST_F(Testing, AllSameHeight)
{
    vector<int> height = {1, 1, 1, 1, 1};
    EXPECT_EQ(s.maxArea(height), 4);
}

TEST_F(Testing, IncreasingHeight)
{
    vector<int> height = {1, 2, 3, 4, 5};
    EXPECT_EQ(s.maxArea(height), 6);
}

TEST_F(Testing, DecreasingHeight)
{
    vector<int> height = {5, 4, 3, 2, 1};
    EXPECT_EQ(s.maxArea(height), 6);
}

TEST_F(Testing, RandomHeight)
{
    vector<int> height = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ(s.maxArea(height), 20);
}
