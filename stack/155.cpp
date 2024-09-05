#include <gtest/gtest.h>
#include <stack>
using namespace std;
class MinStack {
    stack<pair<int, int>> st;
    int minVal = INT_MAX;

public:
    MinStack() {}

    void push(int val)
    {
        minVal = min(minVal, val);
        st.push({val, minVal});
    }

    void pop()
    {
        st.pop();
        if (st.empty()) {
            minVal = INT_MAX;
        }
        else {
            minVal = st.top().second;
        }
    }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class Testing : public ::testing::Test {
public:
    MinStack *obj;
    Testing() { obj = new MinStack(); }
    ~Testing() { delete obj; }
};

TEST_F(Testing, TC1)
{
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    EXPECT_EQ(obj->getMin(), -3);
    obj->pop();
    EXPECT_EQ(obj->top(), 0);
    EXPECT_EQ(obj->getMin(), -2);
}

TEST_F(Testing, TC2)
{
    obj->push(0);
    obj->push(1);
    obj->push(0);
    EXPECT_EQ(obj->getMin(), 0);
    obj->pop();
    EXPECT_EQ(obj->getMin(), 0);
}

TEST_F(Testing, TC3)
{
    obj->push(2);
    obj->push(2);
    obj->push(1);
    EXPECT_EQ(obj->getMin(), 1);
    obj->pop();
    EXPECT_EQ(obj->getMin(), 2);
    obj->pop();
    EXPECT_EQ(obj->getMin(), 2);
    obj->pop();
}

TEST_F(Testing, TC4)
{
    obj->push(3);
    obj->push(4);
    obj->push(5);
    obj->pop();
    EXPECT_EQ(obj->getMin(), 3);
    EXPECT_EQ(obj->top(), 4);
}

TEST_F(Testing, TC5)
{
    obj->push(-1);
    obj->push(-2);
    obj->push(-3);
    obj->push(0);
    EXPECT_EQ(obj->getMin(), -3);
    obj->pop();
    EXPECT_EQ(obj->getMin(), -3);
    obj->pop();
    EXPECT_EQ(obj->getMin(), -2);
    obj->pop();
    EXPECT_EQ(obj->getMin(), -1);
    obj->pop();
}

TEST_F(Testing, TC6)
{
    obj->push(1);
    obj->push(1);
    obj->push(1);
    EXPECT_EQ(obj->getMin(), 1);
    obj->pop();
    EXPECT_EQ(obj->getMin(), 1);
    obj->pop();
    EXPECT_EQ(obj->getMin(), 1);
    obj->pop();
}

TEST_F(Testing, TC7)
{
    obj->push(INT_MAX);
    obj->push(INT_MIN);
    EXPECT_EQ(obj->getMin(), INT_MIN);
    obj->pop();
    EXPECT_EQ(obj->getMin(), INT_MAX);
    obj->pop();
}

TEST_F(Testing, TC8)
{
    obj->push(10);
    EXPECT_EQ(obj->getMin(), 10);
    obj->push(20);
    EXPECT_EQ(obj->top(), 20);
    EXPECT_EQ(obj->getMin(), 10);
    obj->pop();
    EXPECT_EQ(obj->top(), 10);
    EXPECT_EQ(obj->getMin(), 10);
    obj->pop();
}

TEST_F(Testing, TC9)
{
    obj->push(2147483646);
    obj->push(2147483646);
    obj->push(2147483647);
    EXPECT_EQ(obj->top(), 2147483647);
    obj->pop();
    EXPECT_EQ(obj->getMin(), 2147483646);
    obj->pop();
    EXPECT_EQ(obj->getMin(), 2147483646);
    obj->pop();
    obj->push(2147483647);
    EXPECT_EQ(obj->top(), 2147483647);
    EXPECT_EQ(obj->getMin(), 2147483647);
    obj->push(-2147483648);
    EXPECT_EQ(obj->top(), -2147483648);
    EXPECT_EQ(obj->getMin(), -2147483648);
    obj->pop();
    EXPECT_EQ(obj->getMin(), 2147483647);
}

// ["MinStack","push","push","getMin","getMin"
// [[],[-10],[14],[],[],

// ,"push","get Min","getMin","top","getMin",
// [-20],[],[],[],[],

// "pop","push","push","getMin","push",
// [],[10],[-7],[],[-7],

// "pop","top","getMin","pop"]
// [],[],[],[]]

TEST_F(Testing, TC10)
{
    obj->push(-10);
    obj->push(14);
    EXPECT_EQ(obj->getMin(), -10);
    EXPECT_EQ(obj->getMin(), -10);
    obj->push(-20);
    EXPECT_EQ(obj->getMin(), -20);
    EXPECT_EQ(obj->getMin(), -20);
    EXPECT_EQ(obj->top(), -20);
    EXPECT_EQ(obj->getMin(), -20);
    obj->pop();
    obj->push(10);
    obj->push(-7);
    EXPECT_EQ(obj->getMin(), -10);
    obj->push(-7);
    obj->pop();
    EXPECT_EQ(obj->top(), -7);
    EXPECT_EQ(obj->getMin(), -10);
    obj->pop();
}