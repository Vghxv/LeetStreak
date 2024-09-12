/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
public:
    void removeNext(ListNode *prev)
    {
        ListNode *target = prev->next;
        prev->next = target->next;
        delete target;
    }
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        ListNode *curr = head;
        unordered_set<int> white;
        unordered_set<int> black;
        while (curr != nullptr) {
            if (white.find(curr->val) != white.end()) {
                black.insert(curr->val);
            }
            else {
                white.insert(curr->val);
            }
            curr = curr->next;
        }
        curr = head;
        while (curr != nullptr) {
            ListNode *next = curr->next;
            if (black.find(curr->val) != black.end()) {
                removeNext(prev);
                curr = next;
            }
            else {
                prev = curr;
                curr = next;
            }
        }
        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};

class Testing : public testing::Test {
public:
    Solution sol;
    void test(vector<int> arr, vector<int> expect)
    {
        ListNode *head = builder(arr);
        ListNode *expectNode = builder(expect);
        ListNode *result = sol.deleteDuplicates(head);
        bool isSame = compare(expectNode, result);
        EXPECT_TRUE(isSame);
        tearDown(result);
        tearDown(expectNode);
    }

    ListNode *builder(vector<int> arr)
    {
        ListNode *head = new ListNode(arr[0]);
        ListNode *current = head;
        for (int i = 1; i < arr.size(); i++) {
            current->next = new ListNode(arr[i]);
            current = current->next;
        }
        return head;
    }

    bool compare(ListNode *l1, ListNode *l2)
    {
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;
        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->val != curr2->val) {
                return false;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return curr1 == nullptr && curr2 == nullptr;
    }

    void tearDown(ListNode *head)
    {
        ListNode *current = head;
        while (current != nullptr) {
            ListNode *next = current->next;
            delete current;
            current = next;
        }
    }
};

TEST_F(Testing, Case0) { test({1, 2, 3, 3, 4, 4, 5}, {1, 2, 5}); }

TEST_F(Testing, Case1) { test({1, 1, 1, 2, 3}, {2, 3}); }

TEST_F(Testing, Case2) { test({1, 1, 1, 1, 1, 1, 1}, {}); }

TEST_F(Testing, Case3) { test({1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}); }

TEST_F(Testing, Case4) { test({1, 1, 1, 2, 2, 3}, {3}); }

TEST_F(Testing, Case5) { test({1, 2, 3, 3, 4, 4, 5}, {1, 2, 5}); }

TEST_F(Testing, Case6) { test({1, 1, 1, 2, 3}, {2, 3}); }

TEST_F(Testing, Case7) { test({1, 1, 1, 1, 1, 1, 1}, {}); }

TEST_F(Testing, Case8) { test({1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}); }

TEST_F(Testing, Case9) { test({1, 1, 1, 2, 2, 3}, {3}); }
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
