#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= citations.size() - i) {
                return citations.size() - i;
            }
        }
        return 0;
    }
};

class Testing : public testing::Test {
public:
    Solution s;
    void SetUp() {}

    void TearDown() {}
};

TEST_F(Testing, Case1)
{
    vector<int> citations = {3, 0, 6, 1, 5};
    EXPECT_EQ(s.hIndex(citations), 3);
}

TEST_F(Testing, Case2)
{
    vector<int> citations = {1, 3, 1};
    EXPECT_EQ(s.hIndex(citations), 1);
}

TEST_F(Testing, Case3)
{
    vector<int> citations = {1, 1, 1};
    EXPECT_EQ(s.hIndex(citations), 1);
}

TEST_F(Testing, Case4)
{
    vector<int> citations = {1};
    EXPECT_EQ(s.hIndex(citations), 1);
}

TEST_F(Testing, Case5)
{
    vector<int> citations = {1, 1, 1, 1};
    EXPECT_EQ(s.hIndex(citations), 1);
}

TEST_F(Testing, Case6)
{
    vector<int> citations = {7, 7, 7, 7};
    EXPECT_EQ(s.hIndex(citations), 4);
}

TEST_F(Testing, Case7)
{
    vector<int> citations = {9, 9, 8, 8, 7, 7, 6, 6, 5};
    EXPECT_EQ(s.hIndex(citations), 6);
}

TEST_F(Testing, Case8)
{
    vector<int> citations = {0, 0, 0, 0, 0, 9, 9, 9, 7, 7, 1, 1, 1, 1,
                             1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 9, 9, 9,
                             7, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    EXPECT_EQ(s.hIndex(citations), 7);
}

TEST_F(Testing, Case9)
{
    vector<int> citations = {0, 0, 1, 1, 1, 3, 3, 3, 3, 3, 3, 7, 7, 7, 8, 8,
                             4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6};
    EXPECT_EQ(s.hIndex(citations), 6);
}

TEST_F(Testing, Case10)
{
    vector<int> citations = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 3, 5, 5, 2, 5};
    EXPECT_EQ(s.hIndex(citations), 4);
}
