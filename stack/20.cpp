#include <gtest/gtest.h>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isValid(string s)
    {
        if (s.size() % 2 != 0) {
            return false;
        }
        unordered_map<char, char> m = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> st;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                if (st.empty() || st.top() != m[c]) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

class Testing : public testing::Test {
public:
    Solution s;
    void SetUp() {}
    void TearDown() {}
};

TEST_F(Testing, testisValid1) { EXPECT_EQ(s.isValid("()"), true); }

TEST_F(Testing, testisValid2) { EXPECT_EQ(s.isValid("()[]{}"), true); }

TEST_F(Testing, testisValid3) { EXPECT_EQ(s.isValid("(]"), false); }

TEST_F(Testing, testisValid4) { EXPECT_EQ(s.isValid("([)]"), false); }

TEST_F(Testing, testisValid5) { EXPECT_EQ(s.isValid("{[]}"), true); }

TEST_F(Testing, testisValid6) { EXPECT_EQ(s.isValid("["), false); }
