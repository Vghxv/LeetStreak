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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        if (list1->val > list2->val) {
            std::swap(list1, list2);
        }

        ListNode *head = list1;
        ListNode *prev1 = nullptr;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                prev1 = list1;
                list1 = list1->next;
            }
            else {
                prev1->next = list2;
                std::swap(list1, list2);
            }
        }

        if (list2 != nullptr) {
            prev1->next = list2;
        }

        return head;
    }
};

class Testing : public testing::Test {
public:
    ListNode *builder(vector<int> &arr)
    {
        if (arr.size() == 0) {
            return nullptr;
        }
        ListNode *head = new ListNode(arr[0]);
        ListNode *current = head;
        for (int i = 1; i < arr.size(); i++) {
            current->next = new ListNode(arr[i]);
            current = current->next;
        }
        return head;
    }
    Solution s;
    void SetUp() {}
    void TearDown() {}
};

TEST_F(Testing, testmergeTwoLists1)
{
    vector<int> arr1 = {1, 2, 4};
    vector<int> arr2 = {1, 3, 4};
    ListNode *list1 = builder(arr1);
    ListNode *list2 = builder(arr2);
    ListNode *res = s.mergeTwoLists(list1, list2);
    vector<int> expected = {1, 1, 2, 3, 4, 4};
    ListNode *current = res;
    for (int i = 0; i < expected.size(); i++) {
        EXPECT_EQ(current->val, expected[i]);
        current = current->next;
    }
}

TEST_F(Testing, testmergeTwoLists2)
{
    vector<int> arr1 = {1, 2, 4};
    vector<int> arr2 = {};
    ListNode *list1 = builder(arr1);
    ListNode *list2 = builder(arr2);
    ListNode *res = s.mergeTwoLists(list1, list2);
    vector<int> expected = {1, 2, 4};
    ListNode *current = res;
    for (int i = 0; i < expected.size(); i++) {

        EXPECT_EQ(current->val, expected[i]);
        current = current->next;
    }
}

TEST_F(Testing, testmergeTwoLists3)
{
    vector<int> arr1 = {};
    vector<int> arr2 = {1, 3, 4};
    ListNode *list1 = builder(arr1);
    ListNode *list2 = builder(arr2);
    ListNode *res = s.mergeTwoLists(list1, list2);
    vector<int> expected = {1, 3, 4};
    ListNode *current = res;
    for (int i = 0; i < expected.size(); i++) {
        EXPECT_EQ(current->val, expected[i]);
        current = current->next;
    }
}

TEST_F(Testing, testmergeTwoLists4)
{
    vector<int> arr1 = {};
    vector<int> arr2 = {};
    ListNode *list1 = builder(arr1);
    ListNode *list2 = builder(arr2);
    ListNode *res = s.mergeTwoLists(list1, list2);
    EXPECT_EQ(res, nullptr);
}

TEST_F(Testing, testmergeTwoLists5)
{
    vector<int> arr1 = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13,
                        14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    vector<int> arr2 = {26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
                        39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
    ListNode *list1 = builder(arr1);
    ListNode *list2 = builder(arr2);
    ListNode *res = s.mergeTwoLists(list1, list2);
    vector<int> expected = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13,
                            14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
                            27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
                            40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
    ListNode *current = res;
    for (int i = 0; i < expected.size(); i++) {
        EXPECT_EQ(current->val, expected[i]);
        current = current->next;
    }
}

TEST_F(Testing, testmergeTwoLists6)
{
    vector<int> arr1 = {-100, -90, -80, -70, -60, -50, -40, -30, -20, -10, 0,
                        10,   20,  30,  40,  50,  60,  70,  80,  90,  100};
    vector<int> arr2 = {-99, -89, -79, -69, -59, -49, -39, -29, -19, -9, 1,
                        11,  21,  31,  41,  51,  61,  71,  81,  91,  101};
    ListNode *list1 = builder(arr1);
    ListNode *list2 = builder(arr2);
    ListNode *res = s.mergeTwoLists(list1, list2);
    vector<int> expected = {
        -100, -99, -90, -89, -80, -79, -70, -69, -60, -59, -50, -49, -40, -39,
        -30,  -29, -20, -19, -10, -9,  0,   1,   10,  11,  20,  21,  30,  31,
        40,   41,  50,  51,  60,  61,  70,  71,  80,  81,  90,  91,  100, 101};
    ListNode *current = res;
    for (int i = 0; i < expected.size(); i++) {
        EXPECT_EQ(current->val, expected[i]);
        current = current->next;
    }
}

TEST_F(Testing, testmergeTwoLists7)
{
    vector<int> arr1 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> arr2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    ListNode *list1 = builder(arr1);
    ListNode *list2 = builder(arr2);
    ListNode *res = s.mergeTwoLists(list1, list2);
    vector<int> expected = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    ListNode *current = res;
    for (int i = 0; i < expected.size(); i++) {
        EXPECT_EQ(current->val, expected[i]);
        current = current->next;
    }
}
TEST_F(Testing, testmergeTwoLists8)
{
    vector<int> arr1 = {1,  3,  5,  7,  9,  11, 13, 15, 17, 19, 21, 23, 25,
                        27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49};
    vector<int> arr2 = {2,  4,  6,  8,  10, 12, 14, 16, 18, 20, 22, 24, 26,
                        28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50};
    ListNode *list1 = builder(arr1);
    ListNode *list2 = builder(arr2);
    ListNode *res = s.mergeTwoLists(list1, list2);
    vector<int> expected = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13,
                            14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
                            27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
                            40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
    ListNode *current = res;
    for (int i = 0; i < expected.size(); i++) {
        EXPECT_EQ(current->val, expected[i]);
        current = current->next;
    }
}
