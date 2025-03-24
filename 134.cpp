#include <gtest/gtest.h>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        if (gas.size() == 1) {
            return gas[0] >= cost[0] ? 0 : -1;
        }
        for (int i = 0; i < gas.size(); i++) {
            gas[i] -= cost[i];
        }
        if (accumulate(gas.begin(), gas.end(), 0) < 0) {
            return -1;
        }
        int sum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            sum += gas[i];
            if (sum < 0) {
                sum = 0;
                start = i + 1;
            }
        }
        return start;
    }
};

class Testing : public testing::Test {
public:
    Solution sol;
    void SetUp() {}
    void TearDown() {}
};

TEST_F(Testing, test_1)
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    // -2 -2 -2 3 3
    EXPECT_EQ(sol.canCompleteCircuit(gas, cost), 3);
}

TEST_F(Testing, test_2)
{
    vector<int> gas = {2, 3, 4};
    vector<int> cost = {3, 4, 3};
    EXPECT_EQ(sol.canCompleteCircuit(gas, cost), -1);
}

TEST_F(Testing, test_3)
{
    vector<int> gas = {5, 1, 2, 3, 4};
    vector<int> cost = {4, 4, 1, 5, 1};
    // 1 -3 1 -2 3
    EXPECT_EQ(sol.canCompleteCircuit(gas, cost), 4);
}

TEST_F(Testing, test_4)
{
    vector<int> gas = {5, 8, 2, 8};
    vector<int> cost = {6, 5, 6, 6};
    EXPECT_EQ(sol.canCompleteCircuit(gas, cost), 3);
}

TEST_F(Testing, test_5)
{
    vector<int> gas(100000, 0);
    vector<int> cost(100000, 0);
    gas[99999] = 2;
    cost[99998] = 1;
    EXPECT_EQ(sol.canCompleteCircuit(gas, cost), 99999);
}

TEST_F(Testing, test_6)
{
    vector<int> gas(100000, 1);
    vector<int> cost(100000, 1);
    cost[50000] = 2;
    EXPECT_EQ(sol.canCompleteCircuit(gas, cost), -1);
}
