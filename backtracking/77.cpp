#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    inline vector<vector<int>> solve(int n, int k, int start)
    {
        if (k == 0) {
            return {{}};
        }
        vector<vector<int>> res;
        for (int i = start; i <= n; i++) {
            for (auto &v : solve(n, k - 1, i + 1)) {
                v.insert(v.begin(), i);
                res.push_back(v);
            }
        }
        return res;
    }
    vector<vector<int>> combine(int n, int k) { return solve(n, k, 1); }
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