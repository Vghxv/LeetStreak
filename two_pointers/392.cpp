#include <gtest/gtest.h>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        if (s.empty()) {
            return true;
        }
        if (t.empty()) {
            if (s.empty()) {
                return true;
            }
            return false;
        }
        for (auto const &c : s) {
            auto pos = t.find(c);
            if (pos == string::npos) {
                return false;
            }
            t = t.substr(pos + 1);
        }
        return true;
    }
};

class Testing : public testing::Test {
public:
    Solution s;
};

TEST_F(Testing, EmptyString) { EXPECT_TRUE(s.isSubsequence("", "")); }

TEST_F(Testing, SingleCharacter) { EXPECT_TRUE(s.isSubsequence("a", "a")); }

TEST_F(Testing, SimpleSubsequence)
{
    EXPECT_TRUE(s.isSubsequence("abc", "ahbgdc"));
}

TEST_F(Testing, NonSubsequence)
{
    EXPECT_FALSE(s.isSubsequence("axc", "ahbgdc"));
}

TEST_F(Testing, SubsequenceWithDuplicates)
{
    EXPECT_TRUE(s.isSubsequence("abc", "ahbgdc"));
}
