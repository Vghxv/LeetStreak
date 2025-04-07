#include <algorithm>
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include <system_error>
using namespace std;
class Solution {
public:
    inline pair<int, int> calCor(int n, int size)
    {
        int i = size - (n - 1) / size - 1;
        int j = (n - 1) / size % 2 == 0 ? (n - 1) % size
                                        : size - 1 - (n - 1) % size;
        return {i, j};
    }

    inline int solver(vector<vector<int>> &board, queue<int> &q,
                      vector<bool> &visited)
    {
        int size = board.size();
        int step = 0;

        while (!q.empty()) {
            int q_size = q.size();
            for (int k = 0; k < q_size; ++k) {
                int n = q.front();
                q.pop();

                for (int i = 1; i <= 6; ++i) {
                    int next = n + i;
                    if (next > size * size)
                        break;

                    next = evaluate(board, next);

                    if (next == size * size) {
                        return step + 1;
                    }

                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            step++;
        }

        return -1;
    }

    inline int evaluate(vector<vector<int>> &board, int n)
    {
        int i, j;
        tie(i, j) = calCor(n, board.size());
        if (board[i][j] != -1) {
            return board[i][j];
        }
        return n;
    }

    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        queue<int> q;
        vector<bool> visited(n * n + 1, false);

        q.push(1);
        visited[1] = true;

        return solver(board, q, visited);
    }
};
