#include <gtest/gtest.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    inline int digitSquareSum(int n)
    {
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        unordered_map<int, bool> map;
        while (n != 1) {
            if (map.find(n) != map.end()) {
                return false;
            }
            map[n] = true;
            n = digitSquareSum(n);
        }
        return true;
    }
    bool isHappy2(int n)
    {
        int slow = n;
        int fast = digitSquareSum(n);
        while (fast != 1) {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
            if (slow == fast) {
                return false;
            }
        }
        return true;
    }
};

class TestSolution : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(TestSolution, t1)
{
    EXPECT_EQ(sol.isHappy2(19), true);
    EXPECT_EQ(sol.isHappy2(2), false);
    EXPECT_EQ(sol.isHappy2(1), true);
    EXPECT_EQ(sol.isHappy2(7), true);
}
