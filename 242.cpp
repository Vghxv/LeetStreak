#include <gtest/gtest.h>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size()) {
            return false;
        }
        int count[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

class TestSolution : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(TestSolution, t1)
{
    EXPECT_EQ(sol.isAnagram("anagram", "nagaram"), true);
    EXPECT_EQ(sol.isAnagram("rat", "car"), false);
}

TEST_F(TestSolution, t2)
{
    EXPECT_EQ(sol.isAnagram("a", "b"), false);
    EXPECT_EQ(sol.isAnagram("a", "a"), true);
}
