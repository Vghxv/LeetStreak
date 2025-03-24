/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <gtest/gtest.h>
#include <unordered_map>
#include <vector>
using namespace std;
class Node {
public:
    int val;
    Node *next;
    Node *random;
    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        Node *cur = head;
        Node *dummy = new Node(-1);
        Node *cur_cp = dummy;
        unordered_map<Node *, int> cur_map;
        unordered_map<int, Node *> cur_p_map;
        int i = 0;
        while (cur != nullptr) {
            Node *cp = new Node(cur->val);
            cur_cp->next = cp;
            cur_map[cur] = i;
            cur_p_map[i] = cp;
            cur_cp = cur_cp->next;
            cur = cur->next;
            i++;
        }
        cur = head;
        cur_cp = dummy->next;
        while (cur != nullptr) {
            if (cur->random != nullptr) {
                int index = cur_map[cur->random];
                cur_cp->random = cur_p_map[index];
            }
            cur_cp = cur_cp->next;
            cur = cur->next;
        }
        Node *ret = dummy->next;
        delete dummy;
        return ret;
    }
    Node *copyRandomList2(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        Node *cur = head;
        while (cur != nullptr) {
            Node *cp = new Node(cur->val);
            Node *cur_next = cur->next;
            cur->next = cp;
            cp->next = cur_next;
            cur = cur_next;
        }
        cur = head;
        while (cur != nullptr) {
            if (cur->random != nullptr) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        cur = head;
        Node *dummyHead = new Node(-1);
        Node *copyCur = dummyHead;
        while (cur != nullptr) {
            Node *origin_next = cur->next->next;
            copyCur->next = cur->next;
            copyCur = copyCur->next;
            cur->next = origin_next;
            cur = cur->next;
        }
        Node *ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};

// Helper function to create a linked list from a vector of pairs [val,
// random_index]
Node *createList(const vector<pair<int, int>> &nodes)
{
    if (nodes.empty())
        return nullptr;

    vector<Node *> node_list;
    for (const auto &[val, _] : nodes) {
        node_list.push_back(new Node(val));
    }

    for (int i = 0; i < nodes.size(); ++i) {
        if (i < nodes.size() - 1) {
            node_list[i]->next = node_list[i + 1];
        }
        if (nodes[i].second != -1) {
            node_list[i]->random = node_list[nodes[i].second];
        }
    }

    return node_list[0];
}

// Helper function to compare two linked lists
bool compareLists(Node *l1, Node *l2)
{
    unordered_map<Node *, int> l1_map, l2_map;
    Node *cur1 = l1;
    Node *cur2 = l2;
    int i = 0;
    while (cur1 && cur2) {
        if (cur1->val != cur2->val)
            return false;
        l1_map[cur1] = i;
        l2_map[cur2] = i;
        cur1 = cur1->next;
        cur2 = cur2->next;
        i++;
    }
    if (cur1 || cur2)
        return false; // Lists have different lengths

    cur1 = l1;
    cur2 = l2;
    while (cur1 && cur2) {
        if (cur1->random == nullptr && cur2->random != nullptr)
            return false;
        if (cur1->random != nullptr && cur2->random == nullptr)
            return false;
        if (cur1->random && cur2->random &&
            l1_map[cur1->random] != l2_map[cur2->random])
            return false;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return true;
}
class Testing : public testing::Test {
public:
    Solution s;
    Node *originalHead = nullptr;
    Node *copiedHead = nullptr;

    // TearDown function to release pointers after each test
    void TearDown() override
    {
        releaseList(originalHead);
        releaseList(copiedHead);
    }

    // Helper function to release memory of a linked list
    void releaseList(Node *head)
    {
        while (head) {
            Node *temp = head->next;
            delete head;
            head = temp;
        }
    }
};

TEST_F(Testing, Example1)
{
    // Input: [[7,null],[13,0],[11,4],[10,2],[1,0]]
    originalHead = createList({{7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}});
    copiedHead = s.copyRandomList(originalHead);
    EXPECT_TRUE(compareLists(originalHead, copiedHead));
}

TEST_F(Testing, Example2)
{
    // Input: [[1,1],[2,1]]
    originalHead = createList({{1, 1}, {2, 1}});
    copiedHead = s.copyRandomList(originalHead);
    EXPECT_TRUE(compareLists(originalHead, copiedHead));
}

TEST_F(Testing, Example3)
{
    // Input: [[3,null],[3,0],[3,null]]
    originalHead = createList({{3, -1}, {3, 0}, {3, -1}});
    copiedHead = s.copyRandomList(originalHead);
    EXPECT_TRUE(compareLists(originalHead, copiedHead));
}

TEST_F(Testing, EmptyList)
{
    // Input: []
    originalHead = createList({});
    copiedHead = s.copyRandomList(originalHead);
    EXPECT_TRUE(compareLists(originalHead, copiedHead));
}

TEST_F(Testing, SingleNodeNoRandom)
{
    // Input: [[1, null]]
    originalHead = createList({{1, -1}});
    copiedHead = s.copyRandomList(originalHead);
    EXPECT_TRUE(compareLists(originalHead, copiedHead));
}

TEST_F(Testing, SingleNodeWithRandom)
{
    // Input: [[1, 0]]
    originalHead = createList({{1, 0}});
    originalHead->random = originalHead; // Manually set random to itself
    copiedHead = s.copyRandomList(originalHead);
    EXPECT_TRUE(compareLists(originalHead, copiedHead));
}

// Tests for copyRandomList2
TEST_F(Testing, CopyRandomList2_Example1)
{
    originalHead = createList({{7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}});
    copiedHead = s.copyRandomList2(originalHead);
    EXPECT_TRUE(compareLists(originalHead, copiedHead));
}

TEST_F(Testing, CopyRandomList2_Example2)
{
    originalHead = createList({{1, 1}, {2, 1}});
    copiedHead = s.copyRandomList2(originalHead);
    EXPECT_TRUE(compareLists(originalHead, copiedHead));
}

TEST_F(Testing, CopyRandomList2_Example3)
{
    originalHead = createList({{3, -1}, {3, 0}, {3, -1}});
    copiedHead = s.copyRandomList2(originalHead);
    EXPECT_TRUE(compareLists(originalHead, copiedHead));
}

TEST_F(Testing, CopyRandomList2_EmptyList)
{
    originalHead = createList({});
    copiedHead = s.copyRandomList2(originalHead);
    EXPECT_TRUE(compareLists(originalHead, copiedHead));
}

TEST_F(Testing, CopyRandomList2_SingleNodeNoRandom)
{
    originalHead = createList({{1, -1}});
    copiedHead = s.copyRandomList2(originalHead);
    EXPECT_TRUE(compareLists(originalHead, copiedHead));
}

TEST_F(Testing, CopyRandomList2_SingleNodeWithRandom)
{
    originalHead = createList({{1, 0}});
    originalHead->random = originalHead; // Manually set random to itself
    copiedHead = s.copyRandomList2(originalHead);
    EXPECT_TRUE(compareLists(originalHead, copiedHead));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}