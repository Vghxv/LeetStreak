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
    inline TreeNode *invertTree(TreeNode *root)
    {
        if (root != nullptr) {
            if (root->left != nullptr || root->right != nullptr) {
                TreeNode *temp = root->left;
                root->left = root->right;
                root->right = temp;
                invertTree(root->left);
                invertTree(root->right);
            }
        }
        return root;
    }
    inline bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr || q == nullptr || p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr) {
            return true;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return true;
        }
        if (root->left == nullptr || root->right == nullptr) {
            return false;
        }
        root->right = invertTree(root->right);
        return isSameTree(root->left, root->right);
    }
};