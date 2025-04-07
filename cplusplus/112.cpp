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
TEST(SolutionTest, EmptyTree)
{
    Solution sol;
    TreeNode *root = nullptr;
    int targetSum = 0;
    EXPECT_FALSE(sol.hasPathSum(root, targetSum));
}

TEST(SolutionTest, SingleNodeMatchingSum)
{
    Solution sol;
    TreeNode *root = new TreeNode(5);
    int targetSum = 5;
    EXPECT_TRUE(sol.hasPathSum(root, targetSum));
    deleteTree(root);
}

TEST(SolutionTest, SingleNodeNonMatchingSum)
{
    Solution sol;
    TreeNode *root = new TreeNode(5);
    int targetSum = 10;
    EXPECT_FALSE(sol.hasPathSum(root, targetSum));
    deleteTree(root);
}

TEST(SolutionTest, PathExists)
{
    Solution sol;
    /*
          5
         / \
        4   8
       /   / \
      11 13   4
     /  \      \
    7    2      1
    Target Sum = 22
    */
    TreeNode *root = new TreeNode(
        5,
        new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)),
                     nullptr),
        new TreeNode(8, new TreeNode(13),
                     new TreeNode(4, nullptr, new TreeNode(1))));
    int targetSum = 22;
    EXPECT_TRUE(sol.hasPathSum(root, targetSum));
    deleteTree(root);
}

TEST(SolutionTest, NegativeValuesPathExists)
{
    Solution sol;
    /*
          -2
            \
            -3
    Target Sum = -5
    */
    TreeNode *root = new TreeNode(-2, nullptr, new TreeNode(-3));
    int targetSum = -5;
    EXPECT_TRUE(sol.hasPathSum(root, targetSum));
    deleteTree(root);
}

TEST(SolutionTest, ZeroTargetSum)
{
    Solution sol;
    /*
          1
         / \
        2  -3
    Target Sum = 0
    */
    TreeNode *root = new TreeNode(1, new TreeNode(2), new TreeNode(-3));
    int targetSum = 0;
    EXPECT_FALSE(sol.hasPathSum(root, targetSum));
    deleteTree(root);
}

TEST(SolutionTest, MultiplePaths)
{
    Solution sol;
    /*
          1
         / \
        2   3
    Target Sum = 3
    */
    TreeNode *root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    int targetSum = 3;
    EXPECT_TRUE(sol.hasPathSum(root, targetSum));
    deleteTree(root);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}