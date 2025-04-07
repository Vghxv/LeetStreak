#include <gtest/gtest.h>
#include <vector>
using namespace std;
class Solution {
public:
    int countLiveNeighbors(const vector<vector<int>> &board, int row, int col)
    {
        int count = 0;
        for (const auto &i : {-1, 0, 1}) {
            for (const auto &j : {-1, 0, 1}) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (row + i >= 0 && row + i < board.size() && col + j >= 0 &&
                    col + j < board[0].size()) {
                    count += board[row + i][col + j];
                }
            }
        }
        return count;
    }
    void gameOfLife(vector<vector<int>> &board)
    {
        vector<vector<int>> result(board.size(),
                                   vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int count = countLiveNeighbors(board, i, j);
                if (board[i][j] == 1) {
                    if (count < 2 || count > 3) {
                        result[i][j] = 0;
                    }
                    else {
                        result[i][j] = 1;
                    }
                }
                else {
                    if (count == 3) {
                        result[i][j] = 1;
                    }
                }
            }
        }
        board = result;
        return;
    }
};