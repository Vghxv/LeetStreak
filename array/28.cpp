#include <algorithm>
#include <cassert>
#include <gtest/gtest.h>
#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int needle_len = needle.size();
        int haystack_len = haystack.size();
        if (needle_len > haystack_len) {
            return -1;
        }
        for (int i = 0; i <= haystack_len - needle_len; i++) {
            if (haystack.substr(i, needle_len) == needle) {
                return i;
            }
        }
        return -1;
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
    string haystack = "hello";
    string needle = "ll";
    int result = 2;
    EXPECT_EQ(solution.strStr(haystack, needle), result);
}

TEST_F(Testing, Case2)
{
    string haystack = "aaaaa";
    string needle = "bba";
    int result = -1;
    EXPECT_EQ(solution.strStr(haystack, needle), result);
}

TEST_F(Testing, Case3)
{
    string haystack = "";
    string needle = "";
    int result = 0;
    EXPECT_EQ(solution.strStr(haystack, needle), result);
}

TEST_F(Testing, Case4)
{
    string haystack = "a";
    string needle = "a";
    int result = 0;
    EXPECT_EQ(solution.strStr(haystack, needle), result);
}

TEST_F(Testing, Case5)
{
    string haystack = "a";
    string needle = "b";
    int result = -1;
    EXPECT_EQ(solution.strStr(haystack, needle), result);
}
