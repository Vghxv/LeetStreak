#include <gtest/gtest.h>
#include <vector>
using namespace std;
class Solution {
public:
    inline void addToResult(vector<vector<int>> &result,
                            const vector<int> &newInterval)
    {
        if (result.empty() || result.back()[1] < newInterval[0]) {
            result.push_back(newInterval);
        }
        else {
            result.back()[1] = max(result.back()[1], newInterval[1]);
        }
    }
    vector<vector<int>> insert(vector<vector<int>> &intervals,
                               vector<int> &newInterval)
    {
        vector<vector<int>> result;
        if (intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        bool flag = true;
        for (const auto &interval : intervals) {
            if (flag && interval[0] > newInterval[0]) {
                addToResult(result, newInterval);
                flag = false;
            }
            if (flag) {
                result.push_back(interval);
            }
            else {
                addToResult(result, interval);
            }
        }
        if (flag) {
            addToResult(result, newInterval);
        }
        return result;
    }
};

class Testing : public testing::Test {
public:
    Solution s;
};

TEST_F(Testing, Case1)
{
    vector<vector<int>> intervals = {
        {1, 3}, {6, 9}, {11, 15}, {18, 20}, {21, 25}};
    vector<int> newInterval = {17, 19};
    vector<vector<int>> result = s.insert(intervals, newInterval);
    vector<vector<int>> expected = {
        {1, 3}, {6, 9}, {11, 15}, {17, 20}, {21, 25}};
    EXPECT_EQ(result, expected);
}

TEST_F(Testing, Case2)
{
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval = {4, 8};
    vector<vector<int>> result = s.insert(intervals, newInterval);
    vector<vector<int>> expected = {{1, 2}, {3, 10}, {12, 16}};
    EXPECT_EQ(result, expected);
}

TEST_F(Testing, Case3)
{
    vector<vector<int>> intervals = {};
    vector<int> newInterval = {5, 7};
    vector<vector<int>> result = s.insert(intervals, newInterval);
    vector<vector<int>> expected = {{5, 7}};
    EXPECT_EQ(result, expected);
}

TEST_F(Testing, Case4)
{
    vector<vector<int>> intervals = {{1, 5}};
    vector<int> newInterval = {2, 3};
    vector<vector<int>> result = s.insert(intervals, newInterval);
    vector<vector<int>> expected = {{1, 5}};
    EXPECT_EQ(result, expected);
}

TEST_F(Testing, Case5)
{
    vector<vector<int>> intervals = {{1, 5}};
    vector<int> newInterval = {6, 8};
    vector<vector<int>> result = s.insert(intervals, newInterval);
    vector<vector<int>> expected = {{1, 5}, {6, 8}};
    EXPECT_EQ(result, expected);
}

TEST_F(Testing, Case6)
{
    vector<vector<int>> intervals = {{1, 5}, {6, 8}};
    vector<int> newInterval = {0, 9};
    vector<vector<int>> result = s.insert(intervals, newInterval);
    vector<vector<int>> expected = {{0, 9}};
    EXPECT_EQ(result, expected);
}

TEST_F(Testing, Case7)
{
    vector<vector<int>> intervals = {{1, 3}, {4, 7}};
    vector<int> newInterval = {2, 5};
    vector<vector<int>> result = s.insert(intervals, newInterval);
    vector<vector<int>> expected = {{1, 7}};
    EXPECT_EQ(result, expected);
}
