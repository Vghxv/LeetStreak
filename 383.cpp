#include <gtest/gtest.h>
#include <string>
#include <sys/types.h>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> mapm;
        unordered_map<char, int> mapr;
        for (const auto &c : magazine) {
            mapm[c]++;
        }
        for (const auto &c : ransomNote) {
            mapr[c]++;
        }
        for (const auto &p : mapr) {
            if (mapm[p.first] < p.second) {
                return false;
            }
        }

        return true;
    }
    bool canConstruct2(string ransomNote, string magazine)
    {
        vector<int> map(26, 0);
        for (const auto &c : magazine) {
            map[c - 'a']++;
        }
        for (const auto &c : ransomNote) {
            if (map[c - 'a'] == 0) {
                return false;
            }
            map[c - 'a']--;
        }
        return true;
    }
};

class Testing : public testing::Test {
public:
    Solution sol;
};

TEST(Testing, CanConstruct)
{
    Solution sol;
    EXPECT_TRUE(sol.canConstruct("a", "a"));
    EXPECT_FALSE(sol.canConstruct("a", "b"));
    EXPECT_TRUE(sol.canConstruct("aa", "aab"));
    EXPECT_FALSE(sol.canConstruct("aa", "ab"));
}

TEST(Testing, CanConstruct2)
{
    Solution sol;
    EXPECT_TRUE(sol.canConstruct2("a", "a"));
    EXPECT_FALSE(sol.canConstruct2("a", "b"));
    EXPECT_TRUE(sol.canConstruct2("aa", "aab"));
    EXPECT_FALSE(sol.canConstruct2("aa", "ab"));
}