#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
public:
    inline void backtrack(vector<int> &candidates, int target, int start,
                          vector<int> &conbination, vector<vector<int>> &res)
    {
        if (target == 0) {
            res.push_back(conbination);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (target - candidates[i] < 0) {
                break;
            }
            conbination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, conbination, res);
            conbination.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> conbination;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, conbination, res);
        return res;
    }
};

TEST(backtracking, case1)
{
    Solution solution;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> res = solution.combinationSum(candidates, target);
    vector<vector<int>> expect = {{2, 2, 3}, {7}};
    EXPECT_EQ(res, expect);
}

TEST(backtracking, case2)
{
    Solution solution;
    vector<int> candidates = {2, 3, 5};
    int target = 8;
    vector<vector<int>> res = solution.combinationSum(candidates, target);
    vector<vector<int>> expect = {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}};
    EXPECT_EQ(res, expect);
}

TEST(backtracking, case3)
{
    Solution solution;
    vector<int> candidates = {2};
    int target = 1;
    vector<vector<int>> res = solution.combinationSum(candidates, target);
    vector<vector<int>> expect = {};
    EXPECT_EQ(res, expect);
}

TEST(backtracking, case4)
{
    Solution solution;
    vector<int> candidates = {1};
    int target = 1;
    vector<vector<int>> res = solution.combinationSum(candidates, target);
    vector<vector<int>> expect = {{1}};
    EXPECT_EQ(res, expect);
}

TEST(backtracking, case5)
{
    Solution solution;
    vector<int> candidates = {1};
    int target = 2;
    vector<vector<int>> res = solution.combinationSum(candidates, target);
    vector<vector<int>> expect = {{1, 1}};
    EXPECT_EQ(res, expect);
}

TEST(backtracking, case6)
{
    Solution solution;
    vector<int> candidates = {3, 4, 5};
    int target = 9;
    vector<vector<int>> res = solution.combinationSum(candidates, target);
    vector<vector<int>> expect = {{3, 3, 3}, {4, 5}};
    EXPECT_EQ(res, expect);
}

TEST(backtracking, case7)
{
    Solution solution;
    vector<int> candidates = {2, 3, 7};
    int target = 14;
    vector<vector<int>> res = solution.combinationSum(candidates, target);
    vector<vector<int>> expect = {{2, 2, 2, 2, 2, 2, 2},
                                  {2, 2, 2, 2, 3, 3},
                                  {2, 2, 3, 7},
                                  {2, 3, 3, 3, 3},
                                  {7, 7}};
    EXPECT_EQ(res, expect);
}

TEST(backtracking, case8)
{
    Solution solution;
    vector<int> candidates = {10};
    int target = 10;
    vector<vector<int>> res = solution.combinationSum(candidates, target);
    vector<vector<int>> expect = {{10}};
    EXPECT_EQ(res, expect);
}

TEST(backtracking, case9)
{
    Solution solution;
    vector<int> candidates = {2, 3, 6};
    int target = 5;
    vector<vector<int>> res = solution.combinationSum(candidates, target);
    vector<vector<int>> expect = {{2, 3}};
    EXPECT_EQ(res, expect);
}

TEST(backtracking, case10)
{
    Solution solution;
    vector<int> candidates = {2, 4, 6, 8};
    int target = 8;
    vector<vector<int>> res = solution.combinationSum(candidates, target);
    vector<vector<int>> expect = {{2, 2, 2, 2}, {2, 2, 4}, {2, 6}, {4, 4}, {8}};
    EXPECT_EQ(res, expect);
}

TEST(backtracking, case11)
{
    Solution solution;
    vector<int> candidates = {1, 2};
    int target = 4;
    vector<vector<int>> res = solution.combinationSum(candidates, target);
    vector<vector<int>> expect = {{1, 1, 1, 1}, {1, 1, 2}, {2, 2}};
    EXPECT_EQ(res, expect);
}

TEST(backtracking, case12)
{
    Solution solution;
    vector<int> candidates = {5, 10};
    int target = 15;
    vector<vector<int>> res = solution.combinationSum(candidates, target);
    vector<vector<int>> expect = {{5, 5, 5}, {5, 10}};
    EXPECT_EQ(res, expect);
}

TEST(backtracking, case13)
{
    Solution solution;
    vector<int> candidates = {2, 3, 5};
    int target = 0;
    vector<vector<int>> res = solution.combinationSum(candidates, target);
    vector<vector<int>> expect = {{}};
    EXPECT_EQ(res, expect);
}
