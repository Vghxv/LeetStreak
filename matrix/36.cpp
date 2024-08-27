#include <gtest/gtest.h>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    inline bool isValid(const vector<char> &v)
    {
        set<char> s(v.begin(), v.end());
        return s.size() == v.size();
    }

    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<char> v;
        for (int i = 0; i < 9; i++) {
            v.clear();
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    v.push_back(board[i][j]);
                }
            }
            if (!isValid(v)) {
                return false;
            }
            v.clear();
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    v.push_back(board[j][i]);
                }
            }
            if (!isValid(v)) {
                return false;
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                v.clear();
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        if (board[k][l] != '.') {
                            v.push_back(board[k][l]);
                        }
                    }
                }
                if (!isValid(v)) {
                    return false;
                }
            }
        }
        return true;
    }
};

class Testing : public testing::Test {
public:
    Solution s;
};

TEST_F(Testing, Case1)
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    EXPECT_EQ(s.isValidSudoku(board), true);
}

TEST_F(Testing, Case2)
{
    vector<vector<char>> board = {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    EXPECT_EQ(s.isValidSudoku(board), false);
}

TEST_F(Testing, Case3)
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '6'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    EXPECT_EQ(s.isValidSudoku(board), false);
}
