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
    inline TreeNode *build(vector<int> &preorder, vector<int> &inorder,
                           int rootIndex, int left, int right)
    {
        int index = left;
        while (inorder[index] != preorder[rootIndex]) {
            index++;
        }
        return new TreeNode(preorder[rootIndex],
                            index > left ? build(preorder, inorder,
                                                 rootIndex + 1, left, index - 1)
                                         : nullptr,
                            index < right ? build(preorder, inorder,
                                                  rootIndex + index - left + 1,
                                                  index + 1, right)
                                          : nullptr);
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0) {
            return nullptr;
        }
        return build(preorder, inorder, 0, 0, inorder.size() - 1);
    }
};