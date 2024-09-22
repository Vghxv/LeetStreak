#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
public:
    inline void fill_graph(vector<vector<int>> &prerequisites,
                           vector<vector<int>> &graph)
    {
        for (auto &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }
    }
    inline bool dfs(int node, vector<vector<int>> &graph, vector<bool> &visited,
                    vector<bool> &stack)
    {
        if (!visited[node]) {
            visited[node] = true;
            stack[node] = true;
            for (int neighbor : graph[node]) {
                if (!visited[neighbor] &&
                    dfs(neighbor, graph, visited, stack)) {
                    return true;
                }
                else if (stack[neighbor]) {
                    return true;
                }
            }
        }
        stack[node] = false;
        return false;
    }
    inline bool solve(int numCourses, vector<vector<int>> &graph)
    {
        vector<bool> visited(numCourses, false);
        vector<bool> stack(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && dfs(i, graph, visited, stack)) {
                return false;
            }
        }
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        fill_graph(prerequisites, graph);
        return solve(numCourses, graph);
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
