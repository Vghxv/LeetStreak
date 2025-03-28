#include <gtest/gtest.h>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

typedef priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
    min_heap;

class Solution {
public:
    inline bool isValid(int x, int y, vector<vector<int>> &grid)
    {
        return (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size());
    }

    inline vector<int> bfs(vector<vector<int>> grid, vector<pair<int, int>> q_order)
    {
        min_heap que;
        vector<vector<bool>> visited(grid.size(),
                                     vector<bool>(grid[0].size(), false));
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        vector<int> ans(q_order.size(), 0);
        int count = 0;
        que.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        for (auto &[q, i] : q_order) {
            while (!que.empty()) {
                auto [ele, x, y] = que.top();
                if (ele >= q) {
                    break;
                }
                que.pop();
                count++;
                for (auto &dir : directions) {
                    int new_x = x + dir[0];
                    int new_y = y + dir[1];
                    if (isValid(new_x, new_y, grid) && !visited[new_x][new_y]) {
                        visited[new_x][new_y] = true;
                        que.push({grid[new_x][new_y], new_x, new_y});
                    }
                }
            }
            ans[i] = count;
        }
        return ans;
    }
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        vector<pair<int, int>> q_order(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            q_order[i] = {queries[i], i};
        }
        sort(q_order.begin(), q_order.end());

        return bfs(grid, q_order);
    }
};

class Testing : public testing::Test {
public:
    Solution sol;
};

TEST_F(Testing, tc1)
{
    vector<vector<int>> grid = {{1, 2, 3}, {2, 5, 7}, {3, 5, 1}};
    vector<int> queries = {5, 6, 2};
    vector<int> expected = {5, 8, 1};
    EXPECT_EQ(sol.maxPoints(grid, queries), expected);
}
