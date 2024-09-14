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
};

TEST(SolutionTest, BothNullTrees)
{
    Solution sol;
    TreeNode *p = nullptr;
    TreeNode *q = nullptr;
    EXPECT_TRUE(sol.isSameTree(p, q));
}

TEST(SolutionTest, OneNullTree)
{
    Solution sol;
    TreeNode *p = new TreeNode(1);
    TreeNode *q = nullptr;
    EXPECT_FALSE(sol.isSameTree(p, q));
}

TEST(SolutionTest, SameStructureAndValues)
{
    Solution sol;
    TreeNode *p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode *q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    EXPECT_TRUE(sol.isSameTree(p, q));
}

TEST(SolutionTest, DifferentStructure)
{
    Solution sol;
    TreeNode *p = new TreeNode(1, new TreeNode(2), nullptr);
    TreeNode *q = new TreeNode(1, nullptr, new TreeNode(2));
    EXPECT_FALSE(sol.isSameTree(p, q));
}

TEST(SolutionTest, DifferentValues)
{
    Solution sol;
    TreeNode *p = new TreeNode(1, new TreeNode(2), new TreeNode(1));
    TreeNode *q = new TreeNode(1, new TreeNode(1), new TreeNode(2));
    EXPECT_FALSE(sol.isSameTree(p, q));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
