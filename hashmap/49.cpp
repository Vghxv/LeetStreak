#include <gtest/gtest.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    inline string signature(string s)
    {
        int count[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }
        string sig;
        for (int i = 0; i < 26; i++) {
            sig += count[i];
        }
        return sig;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map;
        for (auto &s : strs) {
            map[signature(s)].push_back(s);
        }
        for (auto &[_, v] : map) {
            result.push_back(v);
        }
        return result;
    }
    vector<vector<string>> groupAnagrams2(vector<string> &strs)
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map;
        for (auto &s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            map[tmp].push_back(s);
        }
        for (auto &[_, v] : map) {
            result.push_back(v);
        }
        return result;
    }
};

class TestSolution : public ::testing::Test {
    int testnum = 1;

protected:
    Solution sol;
    vector<vector<string>> (Solution::*func[2])(vector<string> &) = {
        &Solution::groupAnagrams, &Solution::groupAnagrams2};
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
    void runTest(vector<string> &strs, vector<vector<string>> &expected)
    {
        vector<vector<string>> output = (sol.*func[testnum])(strs);
        assertNestedVectorEq(output, expected);
    }
};

TEST_F(TestSolution, t1)
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> expected = {
        {"eat", "tea", "ate"}, {"tan", "nat"}, {"bat"}};
    runTest(strs, expected);
}

TEST_F(TestSolution, t2)
{
    vector<string> strs = {""};
    vector<vector<string>> expected = {{
        "",
    }};
    runTest(strs, expected);
}

TEST_F(TestSolution, t3)
{
    vector<string> strs = {"a"};
    vector<vector<string>> expected = {{"a"}};
    runTest(strs, expected);
}

TEST_F(TestSolution, t4)
{
    vector<string> strs = {"", ""};

    vector<vector<string>> expected = {
        {"", ""},
    };
    runTest(strs, expected);
}

TEST_F(TestSolution, t5)
{
    vector<string> strs = {"abc", "bca", "cab", "xyz", "zyx", "yxz", "aba"};
    vector<vector<string>> expected = {
        {"abc", "bca", "cab"}, {"xyz", "zyx", "yxz"}, {"aba"}};
    runTest(strs, expected);
}

TEST_F(TestSolution, t6)
{
    vector<string> strs = {"listen", "silent", "enlist", "tinsel",
                           "rat",    "tar",    "art"};
    vector<vector<string>> expected = {{"listen", "silent", "enlist", "tinsel"},
                                       {"rat", "tar", "art"}};
    runTest(strs, expected);
}

TEST_F(TestSolution, t7)
{
    vector<string> strs = {"aabbcc", "baccab", "ccbbaa", "abcabc", "cbaabc"};
    vector<vector<string>> expected = {
        {"aabbcc", "baccab", "ccbbaa", "abcabc", "cbaabc"}};
    runTest(strs, expected);
}

TEST_F(TestSolution, t8)
{
    vector<string> strs = {"abcd", "dcba", "bcda", "dacb", "efgh"};
    vector<vector<string>> expected = {{"abcd", "dcba", "bcda", "dacb"},
                                       {"efgh"}};
    runTest(strs, expected);
}

TEST_F(TestSolution, t9)
{
    vector<string> strs = {"ab", "ba", "abc", "cba", "bca", "acb", "cab"};
    vector<vector<string>> expected = {{"ab", "ba"},
                                       {"abc", "cba", "bca", "acb", "cab"}};
    runTest(strs, expected);
}

TEST_F(TestSolution, t10)
{
    vector<string> strs = {"aa", "aaa", "aaaa", "a", "aaaaa"};
    vector<vector<string>> expected = {
        {"aa"}, {"aaa"}, {"aaaa"}, {"a"}, {"aaaaa"}};
    runTest(strs, expected);
}
