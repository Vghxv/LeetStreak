#include <functional>
#include <gtest/gtest.h>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens)
    {
        unordered_map<string, function<int(int, int)>> map = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }}};
        stack<int> st;
        for (const string &token : tokens) {
            if (map.count(token) == 0) {
                st.push(stoi(token));
            }
            else {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                st.push(map[token](num1, num2));
            }
        }
        return st.top();
    }
};

class Testing : public testing::Test {
public:
    Solution soln;
};

TEST_F(Testing, Case1)
{
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    EXPECT_EQ(soln.evalRPN(tokens), 9);
}

TEST_F(Testing, Case2)
{
    vector<string> tokens = {"4", "13", "5", "/", "+"};
    EXPECT_EQ(soln.evalRPN(tokens), 6);
}

TEST_F(Testing, Case3)
{
    vector<string> tokens = {"10", "6", "9",  "3", "/", "-", "11",
                             "*",  "+", "17", "+", "5", "+"};
    EXPECT_EQ(soln.evalRPN(tokens), 65);
}

TEST_F(Testing, Case4)
{
    vector<string> tokens = {"4", "3", "-"};
    EXPECT_EQ(soln.evalRPN(tokens), 1);
}

TEST_F(Testing, Case5)
{
    vector<string> tokens = {"4", "3", "+"};
    EXPECT_EQ(soln.evalRPN(tokens), 7);
}

TEST_F(Testing, Case6)
{
    vector<string> tokens = {"4", "3", "*"};
    EXPECT_EQ(soln.evalRPN(tokens), 12);
}

TEST_F(Testing, Case7)
{
    vector<string> tokens = {"4", "3", "/"};
    EXPECT_EQ(soln.evalRPN(tokens), 1);
}
