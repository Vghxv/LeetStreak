/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};
#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 1) {
            return new TreeNode(nums[0]);
        }
        int mid = nums[nums.size() / 2];
        vector<int> left(nums.begin(), nums.begin() + nums.size() / 2);
        vector<int> right(nums.begin() + nums.size() / 2 + 1, nums.end());
        if (left.size() == 0) {
            return new TreeNode(mid, nullptr, sortedArrayToBST(right));
        }
        if (right.size() == 0) {
            return new TreeNode(mid, sortedArrayToBST(left), nullptr);
        }
        return new TreeNode(mid, sortedArrayToBST(left),
                            sortedArrayToBST(right));
    }
};

TEST(Testing, test1)
{
    vector<int> nums = {1, 3};
    Solution s;
    s.sortedArrayToBST(nums);
}

TEST(Testing, test2)
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution s;
    s.sortedArrayToBST(nums);
}

TEST(Testing, test3)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Solution s;
    s.sortedArrayToBST(nums);
}

TEST(Testing, test4)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    Solution s;
    s.sortedArrayToBST(nums);
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
