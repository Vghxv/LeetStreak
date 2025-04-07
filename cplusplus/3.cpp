#include <gtest/gtest.h>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> hash;
        int max_length = 0;
        int start = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (hash.find(c) != hash.end() && start <= hash[c]) {
                start = hash[c] + 1;
            }
            else {
                max_length = max(max_length, i - start + 1);
            }
            hash[c] = i;
        }

        return max_length;
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
    EXPECT_EQ(solution.lengthOfLongestSubstring("abcabcbb"), 3);
}

TEST_F(Testing, Case2)
{
    EXPECT_EQ(solution.lengthOfLongestSubstring("bbbbb"), 1);
}

TEST_F(Testing, Case3)
{
    EXPECT_EQ(solution.lengthOfLongestSubstring("pwwkew"), 3);
}

TEST_F(Testing, Case4) { EXPECT_EQ(solution.lengthOfLongestSubstring(""), 0); }

TEST_F(Testing, Case5) { EXPECT_EQ(solution.lengthOfLongestSubstring(" "), 1); }

TEST_F(Testing, Case6)
{
    EXPECT_EQ(solution.lengthOfLongestSubstring("au"), 2);
}

TEST_F(Testing, Case7)
{
    EXPECT_EQ(solution.lengthOfLongestSubstring("aab"), 2);
}

TEST_F(Testing, Case8)
{
    EXPECT_EQ(solution.lengthOfLongestSubstring("dvdf"), 3);
}

TEST_F(Testing, Case9)
{
    EXPECT_EQ(solution.lengthOfLongestSubstring("tmmzuxt"), 5);
}
