// **Problem Description: Group Isomorphic Strings**

// Given a list of strings, your task is to group the strings that are
// isomorphic to each other. Two strings are considered isomorphic if the
// characters in one string can be replaced to get the other string, maintaining
// the order and structure of characters. Each character must map to exactly one
// character, and no two characters can map to the same character.

// ### Example

// 1. **Input:** `["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"]`
//    - **Output:** `[["abc", "bcd", "xyz"], ["acef"], ["az", "ba"], ["a",
//    "z"]]`
//    - **Explanation:** "abc", "bcd", and "xyz" are isomorphic because they
//    follow the same character pattern. Similarly, "az" and "ba" are
//    isomorphic.

// 2. **Input:** `["a", "b", "c", "d"]`
//    - **Output:** `[["a", "b", "c", "d"]]`
//    - **Explanation:** Each string is a single character, so they are all
//    isomorphic to each other.

// 3. **Input:** `["aa", "bb", "cc", "dd", "ee"]`
//    - **Output:** `[["aa", "bb", "cc", "dd", "ee"]]`
//    - **Explanation:** All strings have the same repeated character pattern,
//    making them isomorphic.

#include <algorithm>
#include <cmath>
#include <gtest/gtest.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

public:
    inline string signature(string s)
    {
        string result;
        unordered_map<char, int> m;
        int unique = 0;
        for (const auto &c : s) {
            if (m.find(c) == m.end()) {
                m[c] = unique;
                unique++;
            }
            result.push_back(m[c]);
        }
        return result;
    }
    vector<vector<string>> groupIsomorphicStrings(vector<string> &strings)
    {
        unordered_map<string, vector<string>> m;
        for (const auto &s : strings) {
            m[signature(s)].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto &p : m) {
            result.push_back(p.second);
        }
        return result;
    }
};

class Testing : public testing::Test {
public:
    Solution s;
    void assertNestedVectorEq(vector<vector<string>> &a,
                              vector<vector<string>> &b)
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        ASSERT_EQ(a.size(), b.size());
        for (int i = 0; i < a.size(); i++) {
            ASSERT_EQ(a[i], b[i]);
        }
    }
};
// the answer ignores the order of the strings in the group

TEST_F(Testing, t1)
{
    vector<string> strings = {"abc", "bcd", "acef", "xyz",
                              "az",  "ba",  "a",    "z"};
    vector<vector<string>> result = s.groupIsomorphicStrings(strings);
    vector<vector<string>> expected = {
        {"abc", "bcd", "xyz"}, {"acef"}, {"az", "ba"}, {"a", "z"}};
    assertNestedVectorEq(result, expected);
}
TEST_F(Testing, singleCharacterStrings)
{
    vector<string> strings = {"a", "b", "c", "d"};
    vector<vector<string>> result = s.groupIsomorphicStrings(strings);
    vector<vector<string>> expected = {{"a", "b", "c", "d"}};
    assertNestedVectorEq(result, expected);
}

TEST_F(Testing, repeatingPatterns)
{
    vector<string> strings = {"aa", "bb", "cc", "dd", "ee"};
    vector<vector<string>> result = s.groupIsomorphicStrings(strings);
    vector<vector<string>> expected = {{"aa", "bb", "cc", "dd", "ee"}};
    assertNestedVectorEq(result, expected);
}

TEST_F(Testing, mixedLengthStrings)
{
    vector<string> strings = {"abc", "de", "fg", "hij", "klm"};
    vector<vector<string>> result = s.groupIsomorphicStrings(strings);
    vector<vector<string>> expected = {{"abc", "hij", "klm"}, {"de", "fg"}};
    assertNestedVectorEq(result, expected);
}

TEST_F(Testing, emptyStrings)
{
    vector<string> strings = {"", "", "a", "b"};
    vector<vector<string>> result = s.groupIsomorphicStrings(strings);
    vector<vector<string>> expected = {{"", ""}, {"a", "b"}};
    assertNestedVectorEq(result, expected);
}

TEST_F(Testing, longIsomorphicStrings)
{
    vector<string> strings = {"aabbcc", "ddeeff", "gghhiijj", "kkllmmnn"};
    vector<vector<string>> result = s.groupIsomorphicStrings(strings);
    vector<vector<string>> expected = {{"aabbcc", "ddeeff"},
                                       {"gghhiijj", "kkllmmnn"}};
    assertNestedVectorEq(result, expected);
}

TEST_F(Testing, longNonIsomorphicStrings)
{
    vector<string> strings = {"abcdefghijklmnopqrstuvwxyz",
                              "abcdefghijklmnopqrstuvwxycf"};
    vector<vector<string>> result = s.groupIsomorphicStrings(strings);
    vector<vector<string>> expected = {{"abcdefghijklmnopqrstuvwxyz"},
                                       {"abcdefghijklmnopqrstuvwxycf"}};
    assertNestedVectorEq(result, expected);
}