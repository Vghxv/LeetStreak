#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> neighbors(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (auto &pre : prerequisites) {
            neighbors[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        queue<int> zeroDegree;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                zeroDegree.push(i);
            }
        }

        int visitedNodes = 0;
        while (!zeroDegree.empty()) {
            int node = zeroDegree.front();
            zeroDegree.pop();
            visitedNodes++;
            for (int neighbor : neighbors[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    zeroDegree.push(neighbor);
                }
            }
        }
        return visitedNodes == numCourses;
    }
};

TEST(CanFinishTest, NoPrerequisites)
{
    Solution solution;
    int numCourses = 3;
    vector<vector<int>> prerequisites = {};
    EXPECT_TRUE(solution.canFinish(numCourses, prerequisites));
}

TEST(CanFinishTest, SinglePrerequisite)
{
    Solution solution;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    EXPECT_TRUE(solution.canFinish(numCourses, prerequisites));
}

TEST(CanFinishTest, MultiplePrerequisitesPossible)
{
    Solution solution;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};
    EXPECT_TRUE(solution.canFinish(numCourses, prerequisites));
}

TEST(CanFinishTest, CircularDependencyImpossible)
{
    Solution solution;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    EXPECT_FALSE(solution.canFinish(numCourses, prerequisites));
}

TEST(CanFinishTest, ComplexGraphWithCycle)
{
    Solution solution;
    int numCourses = 5;
    vector<vector<int>> prerequisites = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1}};
    EXPECT_FALSE(solution.canFinish(numCourses, prerequisites));
}

TEST(CanFinishTest, LargeGraphNoCycle)
{
    Solution solution;
    int numCourses = 6;
    vector<vector<int>> prerequisites = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
    EXPECT_TRUE(solution.canFinish(numCourses, prerequisites));
}

TEST(CanFinishTest, IsolatedCourses)
{
    Solution solution;
    int numCourses = 3;
    vector<vector<int>> prerequisites = {{1, 0}};
    EXPECT_TRUE(solution.canFinish(numCourses, prerequisites));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
