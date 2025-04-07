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
    inline TreeNode *build(vector<int> &inorder, vector<int> &postorder,
                           int rootIndex, int left, int right)
    {
        if (left > right) {
            return nullptr;
        }
        int index = left;
        while (inorder[index] != postorder[rootIndex]) {
            index++;
        }
        return new TreeNode(
            postorder[rootIndex],
            build(inorder, postorder, rootIndex - 1 - right + index, left,
                  index - 1),
            build(inorder, postorder, rootIndex - 1, index + 1, right));
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return build(inorder, postorder, postorder.size() - 1, 0,
                     inorder.size() - 1);
    }
};

// Helper function to check if two trees are the same
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr) {
        return true;
    }
    if (p == nullptr || q == nullptr || p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// Helper function to delete a tree and free memory
void deleteTree(TreeNode *root)
{
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Test cases
TEST(SolutionTest, EmptyInput)
{
    Solution sol;
    vector<int> inorder;
    vector<int> postorder;
    TreeNode *result = sol.buildTree(inorder, postorder);
    EXPECT_EQ(result, nullptr);
}

TEST(SolutionTest, SingleNode)
{
    Solution sol;
    vector<int> inorder = {1};
    vector<int> postorder = {1};
    TreeNode *result = sol.buildTree(inorder, postorder);
    TreeNode *expected = new TreeNode(1);
    EXPECT_TRUE(isSameTree(result, expected));
    deleteTree(result);
    deleteTree(expected);
}

TEST(SolutionTest, LeftSkewedTree)
{
    Solution sol;
    vector<int> inorder = {1, 2, 3};
    vector<int> postorder = {1, 2, 3};
    TreeNode *result = sol.buildTree(inorder, postorder);
    TreeNode *expected =
        new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), nullptr);
    EXPECT_TRUE(isSameTree(result, expected));
    deleteTree(result);
    deleteTree(expected);
}

TEST(SolutionTest, RightSkewedTree)
{
    Solution sol;
    vector<int> inorder = {1, 2, 3};
    vector<int> postorder = {3, 2, 1};
    TreeNode *result = sol.buildTree(inorder, postorder);
    TreeNode *expected =
        new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
    EXPECT_TRUE(isSameTree(result, expected));
    deleteTree(result);
    deleteTree(expected);
}

TEST(SolutionTest, BalancedTree)
{
    Solution sol;
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode *result = sol.buildTree(inorder, postorder);
    TreeNode *expected =
        new TreeNode(3, new TreeNode(9),
                     new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    EXPECT_TRUE(isSameTree(result, expected));
    deleteTree(result);
    deleteTree(expected);
}

TEST(SolutionTest, ComplexTree)
{
    Solution sol;
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode *result = sol.buildTree(inorder, postorder);
    TreeNode *expected =
        new TreeNode(3, new TreeNode(9),
                     new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    EXPECT_TRUE(isSameTree(result, expected));
    deleteTree(result);
    deleteTree(expected);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}