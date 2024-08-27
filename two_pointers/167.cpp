#include <gtest/gtest.h>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        map<int, int> m;
        for (int i = 0; i < numbers.size(); i++) {
            if (m.find(numbers[i]) != m.end()) {
                return {m[numbers[i]], i + 1};
            }
            else {
                m[target - numbers[i]] = i + 1;
            }
        }
        return {};
    }
};

class Testing : public testing::Test {
public:
    Solution s;
};

TEST_F(Testing, BasicTest)
{
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = s.twoSum(numbers, target);
    vector<int> expected = {1, 2};
    EXPECT_EQ(result, expected);
}

TEST_F(Testing, NoSolution)
{
    vector<int> numbers = {1, 2, 3, 4};
    int target = 8;
    vector<int> result = s.twoSum(numbers, target);
    vector<int> expected = {};
    EXPECT_EQ(result, expected);
}

TEST_F(Testing, MultipleSolutions)
{
    vector<int> numbers = {1, 3, 3, 4};
    int target = 6;
    vector<int> result = s.twoSum(numbers, target);
    vector<int> expected = {2, 3};
    EXPECT_EQ(result, expected);
}

TEST_F(Testing, NegativeNumbers)
{
    vector<int> numbers = {-1, -2, -3, -4};
    int target = -6;
    vector<int> result = s.twoSum(numbers, target);
    vector<int> expected = {2, 4};
    EXPECT_EQ(result, expected);
}

TEST_F(Testing, SingleElementArray)
{
    vector<int> numbers = {5};
    int target = 5;
    vector<int> result = s.twoSum(numbers, target);
    vector<int> expected = {};
    EXPECT_EQ(result, expected);
}

TEST_F(Testing, EmptyArray)
{
    vector<int> numbers = {};
    int target = 0;
    vector<int> result = s.twoSum(numbers, target);
    vector<int> expected = {};
    EXPECT_EQ(result, expected);
}
