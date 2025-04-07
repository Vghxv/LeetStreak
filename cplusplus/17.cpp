#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        vector<string> v = {"abc", "def",  "ghi", "jkl",
                            "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        for (auto &c : digits) {
            int num = c - '0';
            if (res.empty()) {
                for (auto &c : v[num - 2]) {
                    res.push_back(string(1, c));
                }
            }
            else {
                vector<string> tmp;
                for (auto &c : v[num - 2]) {
                    for (auto &s : res) {
                        tmp.push_back(s + c);
                    }
                }
                res = tmp;
            }
        }
        return res;
    }
};

TEST(letterCombinations, a)
{
    Solution s;
    vector<string> res = s.letterCombinations("23");

    vector<string> expected = {"ad", "bd", "cd", "ae", "be",
                               "ce", "af", "bf", "cf"};
    EXPECT_EQ(res, expected);
}

TEST(letterCombinations, b)
{
    Solution s;
    vector<string> res = s.letterCombinations("");

    vector<string> expected = {};
    EXPECT_EQ(res, expected);
}

TEST(letterCombinations, c)
{
    Solution s;
    vector<string> res = s.letterCombinations("2");

    vector<string> expected = {"a", "b", "c"};
    EXPECT_EQ(res, expected);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
