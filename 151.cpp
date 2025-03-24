#include <algorithm>
#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string reverseWords(string s)
    {
        vector<string> words;
        istringstream iss(s);
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        string result;
        for (const auto &word : words) {
            result += word + " ";
        }
        result.pop_back();
        return result;
    }
};

class Testing : public testing::Test {
public:
    Solution s;
};

TEST_F(Testing, Case)
{
    EXPECT_EQ(s.reverseWords("the sky is blue"), "blue is sky the");
    EXPECT_EQ(s.reverseWords("  hello world  "), "world hello");
    EXPECT_EQ(s.reverseWords("a good   example"), "example good a");
}
