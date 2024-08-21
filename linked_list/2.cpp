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

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *dummyHead = new ListNode();
        ListNode *current = dummyHead;

        while (l1 != nullptr || l2 != nullptr || carry) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return dummyHead->next;
    }
};

class Testing : public testing::Test {
public:
    ListNode *builder(vector<int> &arr)
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
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val != l2->val) {
                return false;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return l1 == nullptr && l2 == nullptr;
    }
    Solution solution;
    void SetUp() {}
    void TearDown() {}
};

TEST_F(Testing, Case1)
{
    vector<int> arr1 = {2, 4, 3};
    vector<int> arr2 = {5, 6, 4};
    ListNode *l1 = builder(arr1);
    ListNode *l2 = builder(arr2);
    vector<int> result = {7, 0, 8};
    ListNode *expected = builder(result);
    EXPECT_EQ(compare(solution.addTwoNumbers(l1, l2), expected), true);
}

TEST_F(Testing, Case2)
{
    vector<int> arr1 = {0};
    vector<int> arr2 = {0};
    ListNode *l1 = builder(arr1);
    ListNode *l2 = builder(arr2);
    vector<int> result = {0};
    ListNode *expected = builder(result);
    EXPECT_EQ(compare(solution.addTwoNumbers(l1, l2), expected), true);
}

TEST_F(Testing, Case3)
{
    vector<int> arr1 = {9, 9, 9, 9, 9, 9, 9};
    vector<int> arr2 = {9, 9, 9, 9};
    ListNode *l1 = builder(arr1);
    ListNode *l2 = builder(arr2);
    vector<int> result = {8, 9, 9, 9, 0, 0, 0, 1};
    ListNode *expected = builder(result);
    EXPECT_EQ(compare(solution.addTwoNumbers(l1, l2), expected), true);
}
