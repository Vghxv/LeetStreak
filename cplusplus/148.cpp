#include <gtest/gtest.h>
#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        inline ListNode *merge(ListNode *l1, ListNode *l2)
        {
            if (l1 == nullptr) {
                return l2;
            }
            if (l2 == nullptr) {
                return l1;
            }
            if (l1->val < l2->val) {
                l1->next = merge(l1->next, l2);
                return l1;
            }
            else {
                l2->next = merge(l1, l2->next);
                return l2;
            }
        }
        ListNode *sortList(ListNode *head)
        {
            if (!head || !head->next) {
                return head;
            }
            ListNode *fast, *slow, *prev;
            fast = slow = prev = head;
            while (fast && fast->next) {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            prev->next = nullptr;
            ListNode *l1 = sortList(head);
            ListNode *l2 = sortList(slow);
            return merge(l1, l2);
        }
    };

TEST(Testing, test)
{
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    Solution s;
    s.sortList(head);
}

TEST(Testing, test2)
{
    ListNode *head = new ListNode(-1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(0);
    Solution s;
    s.sortList(head);
}