#include <cassert>
#include <climits>
#include <gtest/gtest.h>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
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
    int result = 7;
    EXPECT_EQ(solution.maxProfit(prices), result);
}

TEST_F(Testing, Case2)
{
    vector<int> prices = {1, 2, 3, 4, 5};
    int result = 4;
    EXPECT_EQ(solution.maxProfit(prices), result);
}

TEST_F(Testing, Case3)
{
    vector<int> prices = {7, 6, 4, 3, 1};
    int result = 0;
    EXPECT_EQ(solution.maxProfit(prices), result);
}
