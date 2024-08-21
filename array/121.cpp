#include <cassert>
#include <climits>
#include <gtest/gtest.h>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int min_price = INT_MAX;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            }
            else if (prices[i] - min_price > profit) {
                profit = prices[i] - min_price;
            }
        }
        return profit;
    }
};

class Testing : public testing::Test {
public:
    Solution solution;
    void SetUp() {}

    void TearDown() {}
};

TEST_F(Testing, Case1)
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = 5;
    EXPECT_EQ(solution.maxProfit(prices), result);
}

TEST_F(Testing, Case2)
{
    vector<int> prices = {7, 6, 4, 3, 1};
    int result = 0;
    EXPECT_EQ(solution.maxProfit(prices), result);
}

TEST_F(Testing, Case3)
{
    vector<int> prices = {2, 4, 1};
    int result = 2;
    EXPECT_EQ(solution.maxProfit(prices), result);
}

TEST_F(Testing, Case4)
{
    vector<int> prices = {2, 1, 2, 1, 0, 1, 2};
    int result = 2;
    EXPECT_EQ(solution.maxProfit(prices), result);
}

TEST_F(Testing, Case5)
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int result = 4;
    EXPECT_EQ(solution.maxProfit(prices), result);
}

TEST_F(Testing, Case6)
{
    vector<int> prices = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
    int result = 8;
    EXPECT_EQ(solution.maxProfit(prices), result);
}

TEST_F(Testing, Case7)
{
    vector<int> prices = {1};
    int result = 0;
    EXPECT_EQ(solution.maxProfit(prices), result);
}

TEST_F(Testing, Case8)
{
    vector<int> prices = {10000, 10000, 10000, 10000,
                          10000, 10000, 10000, 10000};
    int result = 0;
    EXPECT_EQ(solution.maxProfit(prices), result);
}

TEST_F(Testing, Case9)
{
    vector<int> prices = {
        0,   6,   7,   534, 4,  4,   4,   455,  4,   4,    4,   44,  3,   1343,
        2,   343, 654, 763, 57, 65,  876, 34,   436, 6,    435, 45,  54,  87,
        656, 4,   4,   45,  32, 65,  2,   6466, 43,  75,   765, 235, 547, 34,
        45,  7,   34,  760, 0,  0,   0,   45,   45,  5,    12,  365, 697, 433,
        45,  4,   5,   43,  5,  323, 86,  65,   8,   5624, 57};
    int result = 6466;
    EXPECT_EQ(solution.maxProfit(prices), result);
}
