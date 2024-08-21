#include <algorithm>
#include <cassert>
#include <gtest/gtest.h>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> romanMap = {{'I', 1},   {'V', 5},   {'X', 10},
                                             {'L', 50},  {'C', 100}, {'D', 500},
                                             {'M', 1000}};
        int sum = 0;
        for (int i = 1; i < s.size(); i++) {
            if (romanMap[s[i]] > romanMap[s[i - 1]]) {
                sum += romanMap[s[i]] - 2 * romanMap[s[i - 1]];
            }
            else {
                sum += romanMap[s[i]];
            }
        }
        sum += romanMap[s[0]];
        return sum;
    }
};

class Testing : public testing::Test {
public:
    Solution solution;
    void SetUp() {}

    void TearDown() {}
};

TEST_F(Testing, Case1)
{
    string s = "III";
    int expected = 3;
    EXPECT_EQ(solution.romanToInt(s), expected);
}

TEST_F(Testing, Case2)
{
    string s = "IV";
    int expected = 4;
    EXPECT_EQ(solution.romanToInt(s), expected);
}

TEST_F(Testing, Case3)
{
    string s = "IX";
    int expected = 9;
    EXPECT_EQ(solution.romanToInt(s), expected);
}

TEST_F(Testing, Case4)
{
    string s = "LVIII";
    int expected = 58;
    EXPECT_EQ(solution.romanToInt(s), expected);
}

TEST_F(Testing, Case5)
{
    string s = "MCMXCIV";
    int expected = 1994;
    EXPECT_EQ(solution.romanToInt(s), expected);
}
