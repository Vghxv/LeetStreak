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
    void inorder(TreeNode *root, int k, int &i, int &res)
    {
        if (root == NULL) {
            return;
        }
        inorder(root->left, k, i, res);
        if (i == k - 1) {
            res = root->val;
        }
        i++;
        inorder(root->right, k, i, res);
        return;
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int res = 0;
        int i = 0;
        inorder(root, k, i, res);
        return res;
    }
};
