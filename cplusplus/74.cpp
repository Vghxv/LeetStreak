#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
    public:
        inline bool solver(vector<vector<int>>& matrix, int target, int left, int right) {
            int mid = left + (right - left) / 2;
            int rows = matrix.size();
            int cols = matrix[0].size();
            int row = mid / cols;
            int col = mid % cols;
            if (left > right) {
                return false;
            }
            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                return solver(matrix, target, mid + 1, right);
            }
            else {
                return solver(matrix, target, left, mid - 1);
            }
        }
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int rows = matrix.size();
            int cols = matrix[0].size();
            return solver(matrix, target, 0, rows * cols - 1);
        }
    };

class Testing : public testing::Test {

    public:
        Solution sol;
};

TEST_F(Testing, tc1) {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    EXPECT_EQ(sol.searchMatrix(matrix, 3), true);
}

TEST_F(Testing, tc2) {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    EXPECT_EQ(sol.searchMatrix(matrix, 13), false);
}

TEST_F(Testing, tc3) {
    vector<vector<int>> matrix = {{1}, {3}, {5}};
    EXPECT_EQ(sol.searchMatrix(matrix, 3), true);
}

TEST_F(Testing, tc4) {
    vector<vector<int>> matrix = {{1}, {3}, {5}};
    EXPECT_EQ(sol.searchMatrix(matrix, 2), false);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
