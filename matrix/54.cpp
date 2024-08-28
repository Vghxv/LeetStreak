#include <algorithm>
#include <gtest/gtest.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<pair<int, int>> record;
    bool isValid(int n, int m, int x, int y, int direction)
    {
        int nx = x + directions[direction].first;
        int ny = y + directions[direction].second;
        return nx >= 0 && nx < n && ny >= 0 && ny < m &&
               (find(record.begin(), record.end(), make_pair(nx, ny)) ==
                record.end());
    }
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        int x = 0, y = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int direction = 0;
        record.push_back({x, y});
        result.push_back(matrix[x][y]);
        while (record.size() < n * m) {
            if (isValid(n, m, x, y, direction)) {
                x += directions[direction].first;
                y += directions[direction].second;
                record.push_back({x, y});
                result.push_back(matrix[x][y]);
            }
            else {
                direction = (direction + 1) % 4;
            }
        }
        return result;
    }
};

class TestSolution : public ::testing::Test {
public:
    Solution solution;
};

TEST_F(TestSolution, t1)
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = solution.spiralOrder(matrix);
    vector<int> expected = {1, 2, 3, 6, 9, 8, 7, 4, 5};
    ASSERT_EQ(result, expected);
}

TEST_F(TestSolution, t2)
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> result = solution.spiralOrder(matrix);
    vector<int> expected = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    ASSERT_EQ(result, expected);
}

TEST_F(TestSolution, t3)
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}};
    vector<int> result = solution.spiralOrder(matrix);
    vector<int> expected = {1, 2, 3, 4};
    ASSERT_EQ(result, expected);
}

TEST_F(TestSolution, t4)
{
    vector<vector<int>> matrix = {{1}, {2}, {3}, {4}};
    vector<int> result = solution.spiralOrder(matrix);
    vector<int> expected = {1, 2, 3, 4};
    ASSERT_EQ(result, expected);
}
