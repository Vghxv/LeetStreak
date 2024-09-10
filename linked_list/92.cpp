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
#include <gtest/gtest.h>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right) {
            return head;
        }
        ListNode *curr = head;
        ListNode *prev = curr;
        int count = 1;
        ListNode *start = nullptr;
        ListNode *target = nullptr;
        ListNode *end = nullptr;
        while (curr != nullptr) {
            if (count == left) {
                start = prev;
                target = curr;
            }
            else if (count == right) {
                end = curr->next;
                curr->next = nullptr;
            }
            prev = curr;
            curr = curr->next;
            count++;
        }
        ListNode *newMid = reverseList(target);
        if (start == target) {
            head = newMid;
        }
        else {
            start->next = newMid;
        }
        target->next = end;
        return head;
    }
};

ListNode *builder(vector<int> v)
{
    ListNode *head = new ListNode(v[0]);
    ListNode *curr = head;
    for (int i = 1; i < v.size(); i++) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }
    return head;
}

bool compare(ListNode *l1, ListNode *l2)
{
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val != l2->val) {
            return false;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1 == nullptr && l2 == nullptr;
}

class Testing : public testing::Test {
public:
    Solution s;
};

TEST_F(Testing, Case1)
{
    ListNode *head = builder({1, 2, 3, 4, 5});
    ListNode *result = s.reverseBetween(head, 2, 4);
    vector<int> v = {1, 4, 3, 2, 5};
    ListNode *expected = builder(v);
    ASSERT_TRUE(compare(result, expected));
}

TEST_F(Testing, Case2)
{
    ListNode *head = builder({5});
    ListNode *result = s.reverseBetween(head, 1, 1);
    vector<int> v = {5};
    ListNode *expected = builder(v);
    ASSERT_TRUE(compare(result, expected));
}

TEST_F(Testing, Case3)
{
    ListNode *head = builder({1, 2, 3, 4, 5});
    ListNode *result = s.reverseBetween(head, 1, 5);
    vector<int> v = {5, 4, 3, 2, 1};
    ListNode *expected = builder(v);
    ASSERT_TRUE(compare(result, expected));
}

TEST_F(Testing, Case4)
{
    ListNode *head = builder({3, 5});
    ListNode *result = s.reverseBetween(head, 1, 2);
    vector<int> v = {5, 3};
    ListNode *expected = builder(v);
    ASSERT_TRUE(compare(result, expected));
}