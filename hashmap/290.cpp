#include <algorithm>
#include <gtest/gtest.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> map;
        unordered_set<string> set;
        int i = 0;
        int j = 0;
        string token;
        while (i < s.size()) {
            token = s.substr(i, s.find(' ', i) - i);
            if (map.find(pattern[j]) == map.end()) {
                map[pattern[j]] = token;
            }
            else {
                if (map[pattern[j]] != token) {
                    return false;
                }
            }
            i += token.size() + 1;
            j++;
        }
        for (const auto &[key, value] : map) {
            set.insert(value);
        }
        return set.size() == map.size() && j == pattern.size() &&
               i - 1 == s.size();
    }
};

class TestSolution : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(TestSolution, t1)
{
    EXPECT_EQ(sol.wordPattern("abba", "dog cat cat dog"), true);
    EXPECT_EQ(sol.wordPattern("abba", "dog cat cat fish"), false);
    EXPECT_EQ(sol.wordPattern("aaaa", "dog cat cat dog"), false);
    EXPECT_EQ(sol.wordPattern("abba", "dog dog dog dog"), false);
}

TEST_F(TestSolution, t2)
{
    EXPECT_EQ(sol.wordPattern("ab", "dog dog"), false);
    EXPECT_EQ(sol.wordPattern("ab", "dog"), false);
    EXPECT_EQ(sol.wordPattern("ab", "dog cat"), true);
}