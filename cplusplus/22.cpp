#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
public:
    inline void solve(vector<string> &res, string comb, int n, int count)
    {
        if (comb.size() == (n << 1)) {
            res.push_back(comb);
            return;
        }
        if (count == 0) {
            solve(res, comb + "(", n, count + 1);
        }
        else if (count == n) {
            solve(res, comb + ")", n, count - 1);
        }
        else {
            if ((n << 1) - comb.size() <= count) {
                solve(res, comb + ")", n, count - 1);
            }
            else {
                solve(res, comb + "(", n, count + 1);
                solve(res, comb + ")", n, count - 1);
            }
        }

        return;
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string comb = "";
        solve(res, comb, n, 0);
        return res;
    }
};

TEST(backtracking, case1)
{
    Solution solution;
    int n = 3;
    vector<string> res = solution.generateParenthesis(n);
    vector<string> expect = {"((()))", "(()())", "(())()", "()(())", "()()()"};
    EXPECT_EQ(res, expect);
}

TEST(backtracking, case2)
{
    Solution solution;
    int n = 1;
    vector<string> res = solution.generateParenthesis(n);
    vector<string> expect = {"()"};
    EXPECT_EQ(res, expect);
}

TEST(backtracking, case3)
{
    Solution solution;
    int n = 2;
    vector<string> res = solution.generateParenthesis(n);
    vector<string> expect = {"(())", "()()"};
    EXPECT_EQ(res, expect);
}
