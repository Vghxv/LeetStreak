#include <gtest/gtest.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> map;
        for (int i = 0; i < s.size(); i++) {
            if (map.find(s[i]) == map.end()) {
                map[s[i]] = t[i];
            }
            else {
                if (map[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        map.clear();
        for (int i = 0; i < t.size(); i++) {
            if (map.find(t[i]) == map.end()) {
                map[t[i]] = s[i];
            }
            else {
                if (map[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isIsomorphic2(string s, string t)
    {
        unordered_map<char, char> map;
        for (int i = 0; i < s.size(); i++) {
            if (map.find(s[i]) == map.end()) {
                map[s[i]] = t[i];
            }
            else {
                if (map[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        // check if the values of map are unique
        unordered_set<char> values;
        for (const auto &[key, value] : map) {
            values.insert(value);
        }
        if (values.size() != map.size()) {
            return false;
        }
        return true;
    }

    bool isIsomorphic3(string s, string t)
    {
        vector<int> map1(256, -1);
        vector<int> map2(256, -1);
        for (int i = 0; i < s.size(); i++) {
            if (map1[s[i]] != map2[t[i]]) {
                return false;
            }
            map1[s[i]] = i;
            map2[t[i]] = i;
        }
        return true;
    }
};

class Testing : public testing::Test {
public:
    Solution sol;
};

TEST_F(Testing, sol1)
{
    Solution sol;
    EXPECT_TRUE(sol.isIsomorphic("egg", "add"));
    EXPECT_FALSE(sol.isIsomorphic("foo", "bar"));
    EXPECT_TRUE(sol.isIsomorphic("paper", "title"));
    EXPECT_FALSE(sol.isIsomorphic("ab", "aa"));
}

TEST_F(Testing, sol2)
{
    Solution sol;
    EXPECT_TRUE(sol.isIsomorphic2("egg", "add"));
    EXPECT_FALSE(sol.isIsomorphic2("foo", "bar"));
    EXPECT_TRUE(sol.isIsomorphic2("paper", "title"));
    EXPECT_FALSE(sol.isIsomorphic2("ab", "aa"));
}

TEST_F(Testing, sol3)
{
    Solution sol;
    EXPECT_TRUE(sol.isIsomorphic3("egg", "add"));
    EXPECT_FALSE(sol.isIsomorphic3("foo", "bar"));
    EXPECT_TRUE(sol.isIsomorphic3("paper", "title"));
    EXPECT_FALSE(sol.isIsomorphic3("ab", "aa"));
}
