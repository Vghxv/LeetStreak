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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        unordered_map<int, ListNode *> map;
        ListNode *curr = head;
        int size = 0;
        while (curr != NULL) {
            map[size] = curr;
            curr = curr->next;
            size++;
        }
        if (size - n == 0) {
            ListNode *next = head->next;
            return next;
        }
        ListNode *target = map[size - n - 1];
        ListNode *next = target->next;
        target->next = next->next;
        delete next;
        return head;
    }
};

class Testing : public testing::Test {
public:
    Solution sol;
    void test(vector<int> arr, int n, vector<int> expect)
    {
        ListNode *head = builder(arr);
        ListNode *copiedHead = head;
        ListNode *expectNode = builder(expect);
        ListNode *result = sol.removeNthFromEnd(head, n);
        bool isSame = compare(expectNode, result);
        EXPECT_TRUE(isSame);
        tearDown(copiedHead);
        tearDown(expectNode);
    }

    ListNode *builder(vector<int> arr)
    {
        if (arr.size() == 0) {
            return nullptr;
        }
        ListNode *head = new ListNode(arr[0]);
        ListNode *curr = head;
        for (int i = 1; i < arr.size(); i++) {
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }
        return head;
    }
    bool compare(ListNode *a, ListNode *b)
    {
        while (a != nullptr && b != nullptr) {
            if (a->val != b->val) {
                return false;
            }
            a = a->next;
            b = b->next;
        }
        return a == nullptr && b == nullptr;
    }

    void tearDown(ListNode *head)
    {
        while (head != nullptr) {
            ListNode *next = head->next;
            delete head;
            head = next;
        }
    }
};

TEST_F(Testing, Case1) { test({1, 2, 3, 4, 5}, 2, {1, 2, 3, 5}); }

TEST_F(Testing, Case2) { test({1}, 1, {}); }

TEST_F(Testing, Case3) { test({1, 2}, 1, {1}); }

TEST_F(Testing, Case4) { test({1, 2}, 2, {2}); }

TEST_F(Testing, Case5) { test({1, 2, 3, 4, 5}, 5, {2, 3, 4, 5}); }

TEST_F(Testing, Case6) { test({1, 2, 3, 4, 5}, 1, {1, 2, 3, 4}); }
