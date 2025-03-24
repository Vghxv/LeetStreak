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
    bool inorder(TreeNode *root, int *&prev)
    {
        if (root == NULL) {
            return true;
        }
        bool l = inorder(root->left, prev);
        bool mid = true;
        if (prev == nullptr) {
            mid = true;
        }
        else {
            if (*prev >= root->val) {
                mid = false;
            }
        }
        prev = &root->val;
        bool r = inorder(root->right, prev);
        return l && r && mid;
    }
    bool isValidBST(TreeNode *root)
    {
        int *prev = nullptr;
        return inorder(root, prev);
    }
};

TEST(SolutionTest, Case1)
{
    Solution s;
    TreeNode *root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    ASSERT_EQ(s.isValidBST(root), true);
}
TEST(SolutionTest, Case2)
{
    Solution s;
    TreeNode *root = new TreeNode(
        5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6)));
    ASSERT_EQ(s.isValidBST(root), false);
}
TEST(SolutionTest, Case3)
{
    Solution s;
    TreeNode *root = new TreeNode(-2147483648);
    ASSERT_EQ(s.isValidBST(root), true);
}
TEST(SolutionTest, Case4)
{
    Solution s;
    TreeNode *root = new TreeNode(2, new TreeNode(2), new TreeNode(2));
    ASSERT_EQ(s.isValidBST(root), false);
}
TEST(SolutionTest, Case5)
{
    Solution s;
    TreeNode *root =
        new TreeNode(-2147483648, nullptr, new TreeNode(-2147483648));
    ASSERT_EQ(s.isValidBST(root), false);
}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}