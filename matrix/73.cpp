#include <gtest/gtest.h>
#include <vector>

using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<pair<int, int>> zeros;
        // find all zeros
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    zeros.push_back({i, j});
                }
            }
        }
        // set zeros
        for (auto zero : zeros) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][zero.second] = 0;
            }
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[zero.first][j] = 0;
            }
        }
    }
    void setZeroes2(vector<vector<int>> &matrix)
    {
        bool firstRow = false;
        bool firstCol = false;
        // check first row and first col
        int maxSize = max(matrix.size(), matrix[0].size());
        int i = 0;
        while (i < maxSize) {
            if (i < matrix.size() && matrix[i][0] == 0 && !firstCol) {
                firstCol = true;
            }
            if (i < matrix[0].size() && matrix[0][i] == 0 && !firstRow) {
                firstRow = true;
            }
            if (firstRow && firstCol) {
                break;
            }
            i++;
        }
        // mark zeros on first row and first col
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // set zeros
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if ((matrix[i][0] == 0 || matrix[0][j] == 0) &&
                    matrix[i][j] != 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // set first row and first col
        if (firstRow) {
            fill(matrix[0].begin(), matrix[0].end(), 0);
        }
        if (firstCol) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

class Testing : public testing::Test {
public:
    Solution s;
};

class Testing2 : public testing::Test {
public:
    Solution s;
};

TEST_F(Testing, Case1)
{
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
    };
    s.setZeroes(matrix);
    vector<vector<int>> expect = {
        {1, 0, 1},
        {0, 0, 0},
        {1, 0, 1},
    };
    ASSERT_EQ(matrix, expect);
}

TEST_F(Testing, Case2)
{
    vector<vector<int>> matrix = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5},
    };
    s.setZeroes(matrix);
    vector<vector<int>> expect = {
        {0, 0, 0, 0},
        {0, 4, 5, 0},
        {0, 3, 1, 0},
    };
    ASSERT_EQ(matrix, expect);
}

TEST_F(Testing, Case3)
{
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {0, 1, 2},
    };
    s.setZeroes(matrix);
    vector<vector<int>> expect = {
        {0, 1, 1},
        {0, 0, 0},
    };
    ASSERT_EQ(matrix, expect);
}

TEST_F(Testing, Case4)
{
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 0},
    };
    s.setZeroes(matrix);
    vector<vector<int>> expect = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 0},
    };
    ASSERT_EQ(matrix, expect);
}

TEST_F(Testing2, Case1)
{
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
    };
    s.setZeroes2(matrix);
    vector<vector<int>> expect = {
        {1, 0, 1},
        {0, 0, 0},
        {1, 0, 1},
    };
    ASSERT_EQ(matrix, expect);
}

TEST_F(Testing2, Case2)
{
    vector<vector<int>> matrix = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5},
    };
    s.setZeroes2(matrix);
    vector<vector<int>> expect = {
        {0, 0, 0, 0},
        {0, 4, 5, 0},
        {0, 3, 1, 0},
    };
    ASSERT_EQ(matrix, expect);
}

TEST_F(Testing2, Case3)
{
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {0, 1, 2},
    };
    s.setZeroes2(matrix);
    vector<vector<int>> expect = {
        {0, 1, 1},
        {0, 0, 0},
    };
    ASSERT_EQ(matrix, expect);
}

TEST_F(Testing2, Case4)
{
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 0},
    };
    s.setZeroes2(matrix);
    vector<vector<int>> expect = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 0},
    };
    ASSERT_EQ(matrix, expect);
}
