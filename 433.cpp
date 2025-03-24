#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
public:
    inline int editDistance(string &a, string &b)
    {
        int distance = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                distance++;
            }
        }
        return distance;
    }
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        if (find(bank.begin(), bank.end(), endGene) == bank.end()) {
            return -1;
        }
        int level = 0;
        queue<string> q;
        vector<bool> visited(bank.size(), false);
        q.push(startGene);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string gene = q.front();
                q.pop();
                if (editDistance(gene, endGene) == 0) {
                    return level;
                }
                for (int j = 0; j < bank.size(); ++j) {
                    if (!visited[j] && editDistance(gene, bank[j]) == 1) {
                        visited[j] = true;
                        q.push(bank[j]);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
TEST(graph_bfs, start_equals_end)
{
    Solution s;
    vector<string> bank = {"AACCGGTA"};
    ASSERT_EQ(-1, s.minMutation("AACCGGTT", "AACCGGTT", bank));
}

TEST(graph_bfs, end_gene_not_in_bank)
{
    Solution s;
    vector<string> bank = {"AACCGGTA", "AACCGCTA"};
    ASSERT_EQ(-1, s.minMutation("AACCGGTT", "AAACGGTA", bank));
}

TEST(graph_bfs, circular_mutation_path)
{
    Solution s;
    vector<string> bank = {"AACCGGTA", "AACCGGTT"};
    ASSERT_EQ(1, s.minMutation("AACCGGTT", "AACCGGTA", bank));
}

TEST(graph_bfs, multiple_paths_shortest_required)
{
    Solution s;
    vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA", "AACCGGTG",
                           "AAACGGTC"};
    ASSERT_EQ(2, s.minMutation("AACCGGTT", "AAACGGTA", bank));
}

TEST(graph_bfs, larger_bank_multiple_mutations)
{
    Solution s;
    vector<string> bank = {"AAAACCCC", "AAACCCCC", "AACCCCCC", "AAAAAACC",
                           "AAACCACC"};
    ASSERT_EQ(3, s.minMutation("AAAAACCC", "AACCCCCC", bank));
}

TEST(graph_bfs, isolated_gene_in_bank)
{
    Solution s;
    vector<string> bank = {"AACCGGTA", "TTTTGGGG", "CCCCGGGG"};
    ASSERT_EQ(-1, s.minMutation("AACCGGTT", "AAACGGTA", bank));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}