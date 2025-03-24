#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
public:
    inline void solver(vector<int> &nums, vector<bool> &visited,
                       vector<int> &combination, vector<vector<int>> &res)
    {
        if (combination.size() == nums.size()) {
            res.push_back(combination);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            combination.push_back(nums[i]);
            solver(nums, visited, combination, res);
            combination.pop_back();
            visited[i] = false;
        }
        return;
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> combination;
        vector<bool> visited(nums.size(), false);
        solver(nums, visited, combination, res);
        return res;
    }
};

TEST(permute, case1)
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = s.permute(nums);
    vector<vector<int>> expected = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                                    {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
    EXPECT_EQ(res, expected);
}

TEST(permute, case2)
{
    Solution s;
    vector<int> nums = {0, 1};
    vector<vector<int>> res = s.permute(nums);
    vector<vector<int>> expected = {{0, 1}, {1, 0}};
    EXPECT_EQ(res, expected);
}

TEST(permute, case3)
{
    Solution s;
    vector<int> nums = {1};
    vector<vector<int>> res = s.permute(nums);
    vector<vector<int>> expected = {{1}};
    EXPECT_EQ(res, expected);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
