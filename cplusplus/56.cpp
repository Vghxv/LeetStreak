#include <algorithm>
#include <gtest/gtest.h>
#include <vector>
using namespace std;
class Solution {
public:
    inline static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 1) {
            return intervals;
        }
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), compare);
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (res.back()[1] >= intervals[i][0]) {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

class Testing : public testing::Test {
public:
    Solution s;
    void SetUp() {}
    void TearDown() {}
};

TEST_F(Testing, testmerge)
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> res = s.merge(intervals);
    vector<vector<int>> expected = {{1, 6}, {8, 10}, {15, 18}};
    EXPECT_EQ(res, expected);
}

TEST_F(Testing, testmerge2)
{
    vector<vector<int>> intervals = {{1, 4}, {4, 5}};
    vector<vector<int>> res = s.merge(intervals);
    vector<vector<int>> expected = {{1, 5}};
    EXPECT_EQ(res, expected);
}

TEST_F(Testing, testmerge3)
{
    vector<vector<int>> intervals = {{1, 4}, {0, 4}};
    vector<vector<int>> res = s.merge(intervals);
    vector<vector<int>> expected = {{0, 4}};
    EXPECT_EQ(res, expected);
}
