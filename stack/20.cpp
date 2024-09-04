#include <gtest/gtest.h>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s)
    {
        if (s.size() % 2 != 0) {
            return false;
        }
        stack<char> st;
        for (const char &c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            else {
                if (st.empty()) {
                    return false;
                }
                if (c == ')' && st.top() != '(') {
                    return false;
                }
                if (c == ']' && st.top() != '[') {
                    return false;
                }
                if (c == '}' && st.top() != '{') {
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
};

TEST_F(Testing, t1) { EXPECT_EQ(s.isValid("()"), true); }

TEST_F(Testing, t2) { EXPECT_EQ(s.isValid("()[]{}"), true); }

TEST_F(Testing, t3) { EXPECT_EQ(s.isValid("(]"), false); }

TEST_F(Testing, t4) { EXPECT_EQ(s.isValid("([)]"), false); }

TEST_F(Testing, t5) { EXPECT_EQ(s.isValid("{[]}"), true); }

TEST_F(Testing, t6) { EXPECT_EQ(s.isValid("["), false); }
