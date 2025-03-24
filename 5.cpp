#include <gtest/gtest.h>
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s)
    {
        int longest = 0;
        int start = 0;
        int i = 0;
        while (s[i] != '\0') {
            int exp = 0;
            while (i - exp > -1 && s[i + exp] != '\0') {
                if (s[i - exp] == s[i + exp]) {
                    exp++;
                }
                else {
                    break;
                }
            }
            exp -= 1;
            if (exp * 2 + 1 > longest) {
                longest = exp * 2 + 1;
                start = i - exp;
            }
            exp = 0;
            while (i - exp > -1 && s[i + 1 + exp] != '\0') {
                if (s[i - exp] == s[i + 1 + exp]) {
                    exp++;
                }
                else {
                    break;
                }
            }
            exp -= 1;
            if (exp * 2 + 2 > longest) {
                longest = exp * 2 + 2;
                start = i - exp;
            }
            i++;
        }
        return s.substr(start, longest);
    }
};

class Testing : public testing::Test {
public:
    Solution s;
};

TEST_F(Testing, Case1)
{
    string input = "babad";
    string output = "bab";
    EXPECT_EQ(s.longestPalindrome(input), output);
}

TEST_F(Testing, Case2)
{
    string input = "cbbd";
    string output = "bb";
    EXPECT_EQ(s.longestPalindrome(input), output);
}

TEST_F(Testing, Case3)
{
    string input = "a";
    string output = "a";
    EXPECT_EQ(s.longestPalindrome(input), output);
}

TEST_F(Testing, Case4)
{
    string input = "ac";
    string output = "a";
    EXPECT_EQ(s.longestPalindrome(input), output);
}

TEST_F(Testing, Case5)
{
    string input = "bb";
    string output = "bb";
    EXPECT_EQ(s.longestPalindrome(input), output);
}

TEST_F(Testing, Case6)
{
    string input = "ccc";
    string output = "ccc";
    EXPECT_EQ(s.longestPalindrome(input), output);
}

TEST_F(Testing, Case7)
{
    string input = "aaaa";
    string output = "aaaa";
    EXPECT_EQ(s.longestPalindrome(input), output);
}
