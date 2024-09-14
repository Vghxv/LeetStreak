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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// Test cases
TEST(SolutionTest, EmptyTree)
{
    Solution sol;
    TreeNode *root = nullptr;
    EXPECT_EQ(sol.maxDepth(root), 0);
}

TEST(SolutionTest, SingleNodeTree)
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    EXPECT_EQ(sol.maxDepth(root), 1);
    delete root;
}

TEST(SolutionTest, LeftSkewedTree)
{
    Solution sol;
    // Tree: 1 -> 2 -> 3 (left-skewed)
    TreeNode *root =
        new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr);
    EXPECT_EQ(sol.maxDepth(root), 3);
    // Clean up
    delete root->left->left;
    delete root->left;
    delete root;
}

TEST(SolutionTest, RightSkewedTree)
{
    Solution sol;
    // Tree: 1 -> 2 -> 3 (right-skewed)
    TreeNode *root =
        new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
    EXPECT_EQ(sol.maxDepth(root), 3);
    // Clean up
    delete root->right->right;
    delete root->right;
    delete root;
}

TEST(SolutionTest, BalancedTree)
{
    Solution sol;
    // Tree:
    //       1
    //     /   \
    //    2     3
    //   / \   / \
    //  4   5 6   7
    TreeNode *root =
        new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)),
                     new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    EXPECT_EQ(sol.maxDepth(root), 3);
    // Clean up
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;
}

TEST(SolutionTest, UnbalancedTree)
{
    Solution sol;
    // Tree:
    //     1
    //    /
    //   2
    //  /
    // 3
    //  \
    //   4
    TreeNode *root = new TreeNode(
        1, new TreeNode(2, new TreeNode(3, nullptr, new TreeNode(4)), nullptr),
        nullptr);
    EXPECT_EQ(sol.maxDepth(root), 4);
    // Clean up
    delete root->left->left->right;
    delete root->left->left;
    delete root->left;
    delete root;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
