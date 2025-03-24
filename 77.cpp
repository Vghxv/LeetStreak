#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    void solve(int n, int k, int start, vector<int> &combination,
               vector<vector<int>> &res)
    {
        if (k == 0) {
            res.push_back(combination);
            return;
        }
        for (int i = start; i <= n; i++) {
            combination.push_back(i);
            solve(n, k - 1, i + 1, combination, res);
            combination.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> combination;
        solve(n, k, 1, combination, res);
        return res;
    }
};

TEST(CombineTest, HandlesBaseCase)
{
    Solution solution;
    vector<vector<int>> expected = {{}};
    EXPECT_EQ(solution.combine(0, 0), expected);
}

TEST(CombineTest, HandlesSingleElement)
{
    Solution solution;
    vector<vector<int>> expected = {{1}};
    EXPECT_EQ(solution.combine(1, 1), expected);
}

TEST(CombineTest, HandlesMultipleCombinations)
{
    Solution solution;
    vector<vector<int>> expected = {{1, 2}, {1, 3}, {2, 3}};
    EXPECT_EQ(solution.combine(3, 2), expected);
}

TEST(CombineTest, HandlesAllElements)
{
    Solution solution;
    vector<vector<int>> expected = {{1, 2, 3}};
    EXPECT_EQ(solution.combine(3, 3), expected);
}

TEST(CombineTest, HandlesLargerSet)
{
    Solution solution;
    vector<vector<int>> expected = {{1, 2}, {1, 3}, {1, 4},
                                    {2, 3}, {2, 4}, {3, 4}};
    EXPECT_EQ(solution.combine(4, 2), expected);
}