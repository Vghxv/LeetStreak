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

#include <bits/stdc++.h>
#include <gtest/gtest.h>
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
    ListNode *reverse(ListNode *head)
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
    int length(ListNode *head)
    {
        int count = 0;
        ListNode *curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        int len = length(head);
        if (len == 0) {
            return nullptr;
        }
        k = k % len;
        if (k == 0) {
            return head;
        }
        ListNode *reversed = reverse(head);
        int i = 0;
        ListNode *curr = reversed;
        ListNode *reversed_first = nullptr;
        ListNode *reversed_second = nullptr;
        while (curr != nullptr) {
            if (i == k - 1) {
                ListNode *second_head = curr->next;
                curr->next = nullptr;
                reversed_first = reverse(reversed);
                reversed_second = reverse(second_head);
                reversed->next = reversed_second;
                break;
            }
            curr = curr->next;
            i++;
        }
        if (reversed_first == nullptr) {
            return reversed_second;
        }
        return reversed_first;
    }
};
class Testing : public ::testing::Test {
protected:
    Solution solution;

    // Builder function for ListNode from vector
    ListNode *buildList(const std::vector<int> &values)
    {
        if (values.empty())
            return nullptr;
        ListNode *head = new ListNode(values[0]);
        ListNode *current = head;
        for (size_t i = 1; i < values.size(); ++i) {
            current->next = new ListNode(values[i]);
            current = current->next;
        }
        return head;
    }

    // Function to convert ListNode to vector for easy comparison
    std::vector<int> listToVector(ListNode *head)
    {
        std::vector<int> result;
        while (head) {
            result.push_back(head->val);
            head = head->next;
        }
        return result;
    }

    // Clean up allocated memory
    void deleteList(ListNode *head)
    {
        while (head) {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Setup before each test
    void SetUp() override
    {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    // Teardown after each test
    void TearDown() override
    {
        // Code here will be called immediately after each test (right before
        // the destructor).
    }
};

// Test cases
TEST_F(Testing, RotateRight_EmptyList)
{
    ListNode *head = buildList({});
    ListNode *result = solution.rotateRight(head, 5);
    EXPECT_EQ(result, nullptr);
}

TEST_F(Testing, RotateRight_SingleElement)
{
    ListNode *head = buildList({1});
    ListNode *result = solution.rotateRight(head, 2);
    std::vector<int> expected = {1};
    EXPECT_EQ(listToVector(result), expected);
    deleteList(result); // Cleanup
}

TEST_F(Testing, RotateRight_NoRotation)
{
    ListNode *head = buildList({1, 2, 3, 4, 5});
    ListNode *result = solution.rotateRight(head, 0);
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(listToVector(result), expected);
    deleteList(result); // Cleanup
}

TEST_F(Testing, RotateRight_RotationWithinLength)
{
    ListNode *head = buildList({1, 2, 3, 4, 5});
    ListNode *result = solution.rotateRight(head, 2);
    std::vector<int> expected = {4, 5, 1, 2, 3};
    EXPECT_EQ(listToVector(result), expected);
    deleteList(result); // Cleanup
}

TEST_F(Testing, RotateRight_RotationGreaterThanLength)
{
    ListNode *head = buildList({1, 2, 3, 4, 5});
    ListNode *result =
        solution.rotateRight(head, 7); // Equivalent to rotating by 2
    std::vector<int> expected = {4, 5, 1, 2, 3};
    EXPECT_EQ(listToVector(result), expected);
    deleteList(result); // Cleanup
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}