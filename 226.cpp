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
    TreeNode *invertTree(TreeNode *root)
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
TEST(SolutionTest, EmptyTree)
{
    Solution sol;
    TreeNode *root = nullptr;
    TreeNode *inverted = sol.invertTree(root);
    EXPECT_EQ(inverted, nullptr);
}

TEST(SolutionTest, SingleNodeTree)
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    TreeNode *inverted = sol.invertTree(root);
    TreeNode *expected = new TreeNode(1);
    EXPECT_TRUE(isSameTree(inverted, expected));
    deleteTree(root);
    deleteTree(expected);
}

TEST(SolutionTest, TwoLevelTree)
{
    Solution sol;
    // Original Tree:
    //     1
    //    / \
    //   2   3
    TreeNode *root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    // Expected Inverted Tree:
    //     1
    //    / \
    //   3   2
    TreeNode *expected = new TreeNode(1, new TreeNode(3), new TreeNode(2));
    TreeNode *inverted = sol.invertTree(root);
    EXPECT_TRUE(isSameTree(inverted, expected));
    deleteTree(expected);
    deleteTree(root); // inverted tree is the same as root
}

TEST(SolutionTest, LeftSkewedTree)
{
    Solution sol;
    // Original Tree: 1 -> 2 -> 3 (left-skewed)
    TreeNode *root =
        new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr);
    // Expected Inverted Tree: 1 -> 2 -> 3 (right-skewed)
    TreeNode *expected =
        new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
    TreeNode *inverted = sol.invertTree(root);
    EXPECT_TRUE(isSameTree(inverted, expected));
    deleteTree(expected);
    deleteTree(root);
}

TEST(SolutionTest, RightSkewedTree)
{
    Solution sol;
    // Original Tree: 1 -> 2 -> 3 (right-skewed)
    TreeNode *root =
        new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
    // Expected Inverted Tree: 1 -> 2 -> 3 (left-skewed)
    TreeNode *expected =
        new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr);
    TreeNode *inverted = sol.invertTree(root);
    EXPECT_TRUE(isSameTree(inverted, expected));
    deleteTree(expected);
    deleteTree(root);
}

TEST(SolutionTest, ComplexTree)
{
    Solution sol;
    // Original Tree:
    //         4
    //       /   \
    //      2     7
    //     / \   / \
    //    1   3 6   9
    TreeNode *root =
        new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)),
                     new TreeNode(7, new TreeNode(6), new TreeNode(9)));
    // Expected Inverted Tree:
    //         4
    //       /   \
    //      7     2
    //     / \   / \
    //    9   6 3   1
    TreeNode *expected =
        new TreeNode(4, new TreeNode(7, new TreeNode(9), new TreeNode(6)),
                     new TreeNode(2, new TreeNode(3), new TreeNode(1)));
    TreeNode *inverted = sol.invertTree(root);
    EXPECT_TRUE(isSameTree(inverted, expected));
    deleteTree(expected);
    deleteTree(root);
}

TEST(SolutionTest, SymmetricTree)
{
    Solution sol;
    // Original Tree:
    //         1
    //       /   \
    //      2     2
    //     / \   / \
    //    3   4 4   3
    TreeNode *root =
        new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)),
                     new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    // Expected Inverted Tree (should be the same as original due to symmetry)
    TreeNode *expected =
        new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)),
                     new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    TreeNode *inverted = sol.invertTree(root);
    EXPECT_TRUE(isSameTree(inverted, expected));
    deleteTree(expected);
    deleteTree(root);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}