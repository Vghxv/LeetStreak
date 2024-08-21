#include <gtest/gtest.h>
#include <string>
using namespace std;
class Solution {
public:
    string to_string(int x)
    {
        string s;
        while (x) {
            s += x % 10 + '0';
            x /= 10;
        }
        return s;
    }
    bool isPalindrome(int x)
    {
        if (x < 0) {
            return false;
        }
        string s = to_string(x);
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
};

class Testing : public testing::Test {
public:
    Solution s;
    void SetUp() {}
    void TearDown() {}
};

TEST_F(Testing, testisPalindrome)
{
    int x = 121;
    bool res = s.isPalindrome(x);
    bool expected = true;
    EXPECT_EQ(res, expected);
}

TEST_F(Testing, testisPalindrome2)
{
    int x = -121;
    bool res = s.isPalindrome(x);
    bool expected = false;
    EXPECT_EQ(res, expected);
}

TEST_F(Testing, testisPalindrome3)
{
    int x = 10;
    bool res = s.isPalindrome(x);
    bool expected = false;
    EXPECT_EQ(res, expected);
}
