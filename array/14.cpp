#include <algorithm>
#include <cassert>
#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0) {
            return "";
        }
        if (strs[0].size() == 0) {
            return "";
        }
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[0][i] != strs[j][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
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
    vector<string> strs = {"flower", "flow", "flight"};
    string expected = "fl";
    EXPECT_EQ(solution.longestCommonPrefix(strs), expected);
}

TEST_F(Testing, Case2)
{
    vector<string> strs = {"dog", "racecar", "car"};
    string expected = "";
    EXPECT_EQ(solution.longestCommonPrefix(strs), expected);
}

TEST_F(Testing, Case3)
{
    vector<string> strs = {"", "racecar", "car"};
    string expected = "";
    EXPECT_EQ(solution.longestCommonPrefix(strs), expected);
}

TEST_F(Testing, Case4)
{
    vector<string> strs = {"flower", "flower", "flower"};
    string expected = "flower";
    EXPECT_EQ(solution.longestCommonPrefix(strs), expected);
}

TEST_F(Testing, Case5)
{
    vector<string> strs = {"flower", "flower", "flower", "flow"};
    string expected = "flow";
    EXPECT_EQ(solution.longestCommonPrefix(strs), expected);
}
