#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int fib(int n)
    {
        if (n == 0){
            return 0;
        }
        else if (n <= 2) {
            return 1;
        }
        if (n % 2 == 0) {
            int h = n / 2;
            return fib(h) * (2 * fib(h + 1) - fib(h));
        }
        else {
            int h = (n - 1) / 2;
            return fib(h + 1) * fib(h + 1) + fib(h) * fib(h);
        }
    }

    int climbStairs(int n) { return fib(n+1); }
};

class TestSolution : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(TestSolution, TestClimbStairs)
{
    EXPECT_EQ(solution.climbStairs(2), 2);
    EXPECT_EQ(solution.climbStairs(3), 3);
    EXPECT_EQ(solution.climbStairs(4), 5);
    EXPECT_EQ(solution.climbStairs(5), 8);
    EXPECT_EQ(solution.climbStairs(6), 13);
    EXPECT_EQ(solution.climbStairs(7), 21);
    EXPECT_EQ(solution.climbStairs(8), 34);
    EXPECT_EQ(solution.climbStairs(9), 55);
    EXPECT_EQ(solution.climbStairs(10), 89);
}
