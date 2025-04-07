/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
struct Node {
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
public:
    inline Node *clone(Node *node, unordered_map<Node *, Node *> &map)
    {
        if (node == nullptr) {
            return nullptr;
        }
        if (map.find(node) == map.end()) {
            Node *newNode = new Node(node->val);
            map[node] = newNode;
            for (auto &n : node->neighbors) {
                if (map.find(n) == map.end()) {
                    newNode->neighbors.push_back(clone(n, map));
                }
                else {
                    newNode->neighbors.push_back(map[n]);
                }
            }
            return newNode;
        }
        else {
            return map[node];
        }
    }
    Node *cloneGraph(Node *node)
    {
        unordered_map<Node *, Node *> map;
        return clone(node, map);
    }
};

TEST(graph_general, 133)
{
    Solution s;
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);
    Node *node = s.cloneGraph(node1);
    EXPECT_EQ(node->val, 1);
    EXPECT_EQ(node->neighbors[0]->val, 2);
    EXPECT_EQ(node->neighbors[1]->val, 4);
    EXPECT_EQ(node->neighbors[0]->neighbors[0]->val, 1);
    EXPECT_EQ(node->neighbors[0]->neighbors[1]->val, 3);
    EXPECT_EQ(node->neighbors[1]->neighbors[0]->val, 1);
    EXPECT_EQ(node->neighbors[1]->neighbors[1]->val, 3);
}