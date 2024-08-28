#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i; j < n - 1 - i; j++) {
                swap(matrix[i][j], matrix[n - 1 - j][i]);
                swap(matrix[n - 1 - j][i], matrix[n - 1 - i][n - 1 - j]);
                swap(matrix[n - 1 - i][n - 1 - j], matrix[j][n - 1 - i]);
            }
        }
    }
};

class TestSolution : public ::testing::Test {
public:
    Solution solution;
};

TEST_F(TestSolution, t1)
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    solution.rotate(matrix);
    vector<vector<int>> expected = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
    ASSERT_EQ(matrix, expected);
}

TEST_F(TestSolution, t2)
{
    vector<vector<int>> matrix = {
        {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    solution.rotate(matrix);
    vector<vector<int>> expected = {
        {15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};
    ASSERT_EQ(matrix, expected);
}

TEST_F(TestSolution, singleElement)
{
    vector<vector<int>> matrix = {{1}};
    solution.rotate(matrix);
    vector<vector<int>> expected = {{1}};
    ASSERT_EQ(matrix, expected);
}

TEST_F(TestSolution, twoByTwo)
{
    vector<vector<int>> matrix = {{1, 2}, {3, 4}};
    solution.rotate(matrix);
    vector<vector<int>> expected = {{3, 1}, {4, 2}};
    ASSERT_EQ(matrix, expected);
}

TEST_F(TestSolution, emptyMatrix)
{
    vector<vector<int>> matrix = {};
    solution.rotate(matrix);
    vector<vector<int>> expected = {};
    ASSERT_EQ(matrix, expected);
}

TEST_F(TestSolution, largeMatrix)
{
    vector<vector<int>> matrix = {{1, 2, 3, 4, 5},
                                  {6, 7, 8, 9, 10},
                                  {11, 12, 13, 14, 15},
                                  {16, 17, 18, 19, 20},
                                  {21, 22, 23, 24, 25}};
    solution.rotate(matrix);
    vector<vector<int>> expected = {{21, 16, 11, 6, 1},
                                    {22, 17, 12, 7, 2},
                                    {23, 18, 13, 8, 3},
                                    {24, 19, 14, 9, 4},
                                    {25, 20, 15, 10, 5}};
    ASSERT_EQ(matrix, expected);
}

TEST_F(TestSolution, largeOddMatrix)
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5, 6, 7},        {8, 9, 10, 11, 12, 13, 14},
        {15, 16, 17, 18, 19, 20, 21}, {22, 23, 24, 25, 26, 27, 28},
        {29, 30, 31, 32, 33, 34, 35}, {36, 37, 38, 39, 40, 41, 42},
        {43, 44, 45, 46, 47, 48, 49}};
    solution.rotate(matrix);
    vector<vector<int>> expected = {
        {43, 36, 29, 22, 15, 8, 1},  {44, 37, 30, 23, 16, 9, 2},
        {45, 38, 31, 24, 17, 10, 3}, {46, 39, 32, 25, 18, 11, 4},
        {47, 40, 33, 26, 19, 12, 5}, {48, 41, 34, 27, 20, 13, 6},
        {49, 42, 35, 28, 21, 14, 7}};
    ASSERT_EQ(matrix, expected);
}
