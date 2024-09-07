/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <gtest/gtest.h>
#include <unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL) {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        fast = fast->next;
        while (fast != NULL && fast->next != NULL) {
            if (slow == fast) {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};

class Testing : public testing::Test {
public:
    Solution s;
    int pos;
    ListNode *cycleNode = NULL;
    ListNode *head;
    ListNode *vector2list(vector<int> vec, int position)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        for (int i = 0; i < vec.size(); i++) {
            p->next = new ListNode(vec[i]);
            p = p->next;
            if (i == position) {
                cycleNode = p;
            }
        }
        if (position != -1) {
            p->next = cycleNode;
        }
        ListNode *actualHead = dummy->next;
        delete dummy;
        return actualHead;
    }

    void deleteList(ListNode *head)
    {
        ListNode *current = head;
        bool cycle = false;
        while (current != NULL) {
            if (current == cycleNode) {
                if (cycle) {
                    break;
                }
                cycle = true;
            }
            ListNode *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
    void SetUp(vector<int> vec, int position)
    {
        head = vector2list(vec, position);
        pos = position;
    }
    void TearDown()
    {
        deleteList(head);
        head = nullptr;
    }
    void test(vector<int> vec, int position, bool expected)
    {
        SetUp(vec, position);
        EXPECT_EQ(s.hasCycle(head), expected);
        TearDown();
    }
};

TEST_F(Testing, Case1) { test({3, 2, 0, -4}, 1, true); }

TEST_F(Testing, Case2) { test({1, 2}, 0, true); }

TEST_F(Testing, Case3) { test({1}, -1, false); }

TEST_F(Testing, Case4) { test({1, 2}, -1, false); }

TEST_F(Testing, Case5) { test({1, 2, 3, 4, 5}, -1, false); }

TEST_F(Testing, Case6) { test({1, 2, 3, 4, 5}, 0, true); }

TEST_F(Testing, Case7) { test({1, 2, 3, 4, 5}, 4, true); }

TEST_F(Testing, Case8) { test({1, 2, 3, 4, 5}, 2, true); }

TEST_F(Testing, Case9) { test({1, 2, 3, 4, 5}, 1, true); }

TEST_F(Testing, Case10) { test({1, 2, 3, 4, 5}, 3, true); }