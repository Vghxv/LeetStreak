#include <algorithm>
#include <gtest/gtest.h>
#include <vector>
using namespace std;
class Solution {
public:
    inline static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), cmp);
        int counter = 0;
        int i = 0;
        while (i < points.size()) {
            int j = i + 1;
            int right = points[i][1];
            while (j != points.size()) {
                if (right >= points[j][0]) {
                    right = min(right, points[j][1]);
                    j++;
                }
                else {
                    break;
                }
            }
            counter++;
            i = j;
        }
        return counter;
    }
};

class Testing : public testing::Test {
public:
    Solution s;
};

TEST_F(Testing, t1)
{
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    EXPECT_EQ(s.findMinArrowShots(points), 2);
}

TEST_F(Testing, t2)
{
    vector<vector<int>> points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    EXPECT_EQ(s.findMinArrowShots(points), 4);
}

TEST_F(Testing, t3)
{
    vector<vector<int>> points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    EXPECT_EQ(s.findMinArrowShots(points), 2);
}

TEST_F(Testing, t4)
{
    vector<vector<int>> points = {{-2147483646, -2147483645},
                                  {2147483646, 2147483647}};
    EXPECT_EQ(s.findMinArrowShots(points), 2);
}

TEST_F(Testing, t5)
{
    vector<vector<int>> points = {{1, 2}};
    EXPECT_EQ(s.findMinArrowShots(points), 1);
}

TEST_F(Testing, t6)
{
    vector<vector<int>> points = {{2, 3}, {2, 3}};
    EXPECT_EQ(s.findMinArrowShots(points), 1);
}
TEST_F(Testing, t7)
{
    vector<vector<int>> points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
    EXPECT_EQ(s.findMinArrowShots(points), 3);
}

TEST_F(Testing, t8)
{
    vector<vector<int>> points = {{0, 10}, {20, 30}, {40, 50}, {60, 70}};
    EXPECT_EQ(s.findMinArrowShots(points), 4);
}

TEST_F(Testing, t9)
{
    vector<vector<int>> points = {{-10, -5}, {-7, 0}, {2, 5}, {7, 10}};
    EXPECT_EQ(s.findMinArrowShots(points), 3);
}

TEST_F(Testing, t10)
{
    vector<vector<int>> points = {
        {100, 200}, {150, 250}, {180, 220}, {210, 230}};
    EXPECT_EQ(s.findMinArrowShots(points), 2);
}

TEST_F(Testing, t11)
{
    vector<vector<int>> points = {
        {-50, -40}, {-30, -20}, {-10, 0}, {10, 20}, {30, 40}};
    EXPECT_EQ(s.findMinArrowShots(points), 5);
}

TEST_F(Testing, t12)
{
    vector<vector<int>> points = {
        {500, 510}, {520, 530}, {540, 550}, {560, 570}, {580, 590}};
    EXPECT_EQ(s.findMinArrowShots(points), 5);
}

TEST_F(Testing, t13)
{
    vector<vector<int>> points = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
    EXPECT_EQ(s.findMinArrowShots(points), 3);
}

TEST_F(Testing, t14)
{
    vector<vector<int>> points = {
        {10, 20}, {30, 40}, {50, 60}, {70, 80}, {90, 100}};
    EXPECT_EQ(s.findMinArrowShots(points), 5);
}

// [[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]
// [[1,10],[3,9],[4,11],[6,7],[6,9],[8,12],[9,12]]
TEST_F(Testing, t15)
{
    vector<vector<int>> points = {{9, 12}, {1, 10}, {4, 11}, {8, 12},
                                  {3, 9},  {6, 9},  {6, 7}};
    EXPECT_EQ(s.findMinArrowShots(points), 2);
}

// [[0,6],[0,9],[2,8],[2,9],[3,8],[3,9],[3,9],[6,8],[7,12],[9,10]]
TEST_F(Testing, t16)
{
    vector<vector<int>> points = {{3, 9}, {7, 12}, {3, 8}, {6, 8}, {9, 10},
                                  {2, 9}, {0, 9},  {3, 9}, {0, 6}, {2, 8}};
    EXPECT_EQ(s.findMinArrowShots(points), 2);
}
