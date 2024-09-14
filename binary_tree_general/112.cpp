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
#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
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
class Solution {
public:
    inline bool aux(TreeNode *root, int targetSum, int value)
    {
        if (root == nullptr) {
            return false;
        }
        value += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return value == targetSum;
        }
        return aux(root->left, targetSum, value) ||
               aux(root->right, targetSum, value);
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        int value = 0;
        return aux(root, targetSum, value);
    }
};