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
class TreeNode {
public:
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
    TreeNode *aux(TreeNode *root)
    {
        if (root == nullptr) {
            return root;
        }
        TreeNode *left = aux(root->left);
        TreeNode *right = aux(root->right);
        root->right = left;
        root->left = nullptr;
        TreeNode *cur = root;
        while (cur->right) {
            cur = cur->right;
        }
        cur->right = right;
        return root;
    }

    void flatten(TreeNode *root) { aux(root); }
};