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
class BSTIterator {
    stack<TreeNode *> st;
    void pushLeft(TreeNode *root)
    {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }

public:
    int value = INT_MIN;
    TreeNode *root;

    BSTIterator(TreeNode *root)
    {
        this->root = root;
        pushLeft(root);
    }
    int next()
    {
        TreeNode *node = st.top();
        st.pop();
        pushLeft(node->right);
        return node->val;
    }

    bool hasNext() { return !st.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */