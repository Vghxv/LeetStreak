#include <cctype>
#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s)
    {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while (i < j && !isalnum(s[i])) {
                i++;
            }
            while (i < j && !isalnum(s[j])) {
                j--;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
        }
        return true;
    }
};

class Testing : public testing::Test {
public:
    Solution s;
};

TEST_F(Testing, EmptyString) { EXPECT_TRUE(s.isPalindrome("")); }

TEST_F(Testing, SingleCharacter) { EXPECT_TRUE(s.isPalindrome("a")); }

TEST_F(Testing, SimplePalindrome)
{
    EXPECT_TRUE(s.isPalindrome("A man a plan a canal Panama"));
}

TEST_F(Testing, NonPalindrome) { EXPECT_FALSE(s.isPalindrome("race a car")); }

TEST_F(Testing, PalindromeWithNonAlphanumeric)
{
    EXPECT_TRUE(s.isPalindrome("No 'x' in Nixon"));
}

TEST_F(Testing, MixedCasePalindrome)
{
    EXPECT_TRUE(s.isPalindrome("Able was I, I saw Elba"));
}

TEST_F(Testing, NonPalindromeWithSymbols)
{
    EXPECT_FALSE(s.isPalindrome("This is not a palindrome!"));
}

TEST_F(Testing, PalindromeWithNumbers) { EXPECT_TRUE(s.isPalindrome("12321")); }

TEST_F(Testing, NonPalindromeWithNumbers)
{
    EXPECT_FALSE(s.isPalindrome("12345"));
}
