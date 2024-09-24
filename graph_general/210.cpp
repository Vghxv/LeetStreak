#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> neighbors(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<int> result;
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
            result.push_back(node);
            zeroDegree.pop();
            visitedNodes++;
            for (int neighbor : neighbors[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    zeroDegree.push(neighbor);
                }
            }
        }
        return visitedNodes == numCourses ? result : vector<int>();
    }
};