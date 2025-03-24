#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
public:
    inline bool solve(vector<vector<char>> &board, string word, int i, int j,
                      int index)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != word[index]) {
            return false;
        }
        if (board[i][j] == word[index] && index == word.size() - 1) {
            return true;
        }
        if (board[i][j] == word[index]) {
            char tmp = board[i][j];
            board[i][j] = '.';
            bool up = solve(board, word, i - 1, j, index + 1);
            bool down = solve(board, word, i + 1, j, index + 1);
            bool left = solve(board, word, i, j - 1, index + 1);
            bool right = solve(board, word, i, j + 1, index + 1);
            board[i][j] = tmp;
            if (up || down || left || right) {
                return true;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    if (solve(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

TEST(Testing, test1)
{
    Solution s;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    EXPECT_EQ(s.exist(board, word), true);
}

TEST(Testing, test2)
{
    Solution s;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "SEE";
    EXPECT_EQ(s.exist(board, word), true);
}

TEST(Testing, test3)
{
    Solution s;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCB";
    EXPECT_EQ(s.exist(board, word), false);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}