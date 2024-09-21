#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    struct Node {
        string _string;
        vector<pair<Node *, double>> neighbors;
        Node() {}
        Node(string str) : _string(str) {}
    };
    inline Node *ingraph(Node *graph, string &str, vector<Node *> &visited)
    {
        if (graph == nullptr) {
            return nullptr;
        }
        if (graph->_string == str) {
            return graph;
        }
        visited.push_back(graph);
        for (auto &neighbor : graph->neighbors) {
            if (find(visited.begin(), visited.end(), neighbor.first) !=
                visited.end()) {
                continue;
            }
            Node *result = ingraph(neighbor.first, str, visited);
            if (result != nullptr) {
                return result;
            }
        }
        return nullptr;
    }
    inline bool dfs(Node *graph, string &str, Node *node, double &res,
                    vector<Node *> &visited)
    {
        if (node == nullptr) {
            return false;
        }
        if (node->_string == str) {
            return true;
        }
        visited.push_back(node);
        for (auto &neighbor : node->neighbors) {
            if (find(visited.begin(), visited.end(), neighbor.first) !=
                visited.end()) {
                continue;
            }
            res *= neighbor.second;
            if (dfs(graph, str, neighbor.first, res, visited)) {
                return true;
            }
            res /= neighbor.second;
        }
        return false;
    }

    inline Node *builder(vector<vector<string>> &equations,
                         vector<double> &values)
    {
        auto itE = equations.begin();
        auto itV = values.begin();
        Node *graph = new Node("🐛");
        vector<Node *> visited;
        while (itE != equations.end() || itV != values.end()) {
            visited.clear();
            bool flag1 = false;
            bool flag2 = false;
            Node *node1 = ingraph(graph, (*itE)[0], visited);
            if (node1 == nullptr) {
                Node *node = new Node();
                node->_string = (*itE)[0];
                node1 = node;
                flag1 = true;
            }
            visited.clear();
            Node *node2 = ingraph(graph, (*itE)[1], visited);
            if (node2 == nullptr) {
                Node *node = new Node();
                node->_string = (*itE)[1];
                node2 = node;
                flag2 = true;
            }
            if (flag1 && flag2) {
                graph->neighbors.push_back({node1, 1});
            }
            node1->neighbors.push_back({node2, *itV});
            node2->neighbors.push_back({node1, 1 / *itV});

            ++itE;
            ++itV;
        }
        return graph;
    }
    inline vector<double> solver(Node *graph, vector<vector<string>> &queries)
    {
        vector<double> result;
        vector<Node *> visited;
        for (auto &query : queries) {
            string &str1 = query[0];
            string &str2 = query[1];
            visited.clear();
            Node *node = ingraph(graph, str1, visited);
            if (node == nullptr) {
                result.push_back(-1);
                continue;
            }
            double res = 1;
            visited.clear();
            if (!dfs(graph, str2, node, res, visited)) {
                res = -1;
            }
            result.push_back(res);
        }
        return result;
    }
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries)
    {
        Node *graph = builder(equations, values);
        vector<double> result = solver(graph, queries);
        return result;
    }
};

TEST(calcEquation, case1)
{
    Solution s;
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {
        {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    vector<double> output = {6.0, 0.5, -1.0, 1.0, -1.0};
    EXPECT_EQ(s.calcEquation(equations, values, queries), output);
}

TEST(calcEquation, case2)
{
    Solution s;
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}, {"bc", "cd"}};
    vector<double> values = {1.5, 2.5, 5.0};
    vector<vector<string>> queries = {
        {"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}};
    vector<double> output = {3.75000, 0.40000, 5.00000, 0.20000};
    EXPECT_EQ(s.calcEquation(equations, values, queries), output);
}