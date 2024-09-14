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
    inline bool isMirror(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left == nullptr || right == nullptr) {
            return false;
        }
        return (left->val == right->val) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
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
        return isMirror(root->left, root->right);
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
    EXPECT_TRUE(sol.isSymmetric(root));
}

TEST(SolutionTest, SingleNodeTree)
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    EXPECT_TRUE(sol.isSymmetric(root));
    deleteTree(root);
}

TEST(SolutionTest, SymmetricTree)
{
    Solution sol;
    // Constructing the following symmetric tree:
    //        1
    //      /   \
    //     2     2
    //    / \   / \
    //   3   4 4   3
    TreeNode *root =
        new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)),
                     new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    EXPECT_TRUE(sol.isSymmetric(root));
    deleteTree(root);
}

TEST(SolutionTest, AsymmetricTree)
{
    Solution sol;
    // Constructing the following asymmetric tree:
    //        1
    //      /   \
    //     2     2
    //      \      \
    //       3      3
    TreeNode *root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(3)),
                                  new TreeNode(2, nullptr, new TreeNode(3)));
    EXPECT_FALSE(sol.isSymmetric(root));
    deleteTree(root);
}

TEST(SolutionTest, LeftSkewedTree)
{
    Solution sol;
    // Constructing the following left-skewed tree:
    //     1
    //    /
    //   2
    //  /
    // 3
    TreeNode *root =
        new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr);
    EXPECT_FALSE(sol.isSymmetric(root));
    deleteTree(root);
}

TEST(SolutionTest, RightSkewedTree)
{
    Solution sol;
    // Constructing the following right-skewed tree:
    // 1
    //  \
    //   2
    //    \
    //     3
    TreeNode *root =
        new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
    EXPECT_FALSE(sol.isSymmetric(root));
    deleteTree(root);
}

TEST(SolutionTest, ComplexSymmetricTree)
{
    Solution sol;
    // Constructing a complex symmetric tree:
    //          1
    //        /   \
    //       2     2
    //      / \   / \
    //     3   5 5   3
    //    /         \
    //   4           4
    TreeNode *root =
        new TreeNode(1,
                     new TreeNode(2, new TreeNode(3, new TreeNode(4), nullptr),
                                  new TreeNode(5)),
                     new TreeNode(2, new TreeNode(5),
                                  new TreeNode(3, nullptr, new TreeNode(4))));
    EXPECT_TRUE(sol.isSymmetric(root));
    deleteTree(root);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}