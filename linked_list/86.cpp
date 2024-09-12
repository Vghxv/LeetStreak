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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *dummy1 = new ListNode(0, head);
        ListNode *dummy2 = new ListNode();
        ListNode *curr2 = dummy2;
        ListNode *curr = head;
        ListNode *prev = dummy1;
        while (curr != nullptr) {
            if (curr->val < x) {
                ListNode *next = curr->next;
                curr2 = curr2->next = curr;
                curr = prev->next = next;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        curr2->next = dummy1->next;
        ListNode *result = dummy2->next;
        delete dummy1;
        delete dummy2;
        return result;
    }
};

class Testing : public ::testing::Test {
protected:
    Solution solution;

    // Builder function to create a linked list from a vector
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

    // Helper function to convert a linked list to a vector for easy comparison
    std::vector<int> listToVector(ListNode *head)
    {
        std::vector<int> result;
        while (head) {
            result.push_back(head->val);
            head = head->next;
        }
        return result;
    }

    // Clean up allocated memory to prevent memory leaks
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
TEST_F(Testing, Partition_EmptyList)
{
    ListNode *head = buildList({});
    ListNode *result = solution.partition(head, 3);
    EXPECT_EQ(result, nullptr);
}

TEST_F(Testing, Partition_AllLessThanX)
{
    ListNode *head = buildList({1, 2, 2});
    ListNode *result = solution.partition(head, 3);
    std::vector<int> expected = {1, 2, 2};
    EXPECT_EQ(listToVector(result), expected);
    deleteList(result); // Cleanup
}

TEST_F(Testing, Partition_AllGreaterThanX)
{
    ListNode *head = buildList({4, 5, 6});
    ListNode *result = solution.partition(head, 3);
    std::vector<int> expected = {4, 5, 6};
    EXPECT_EQ(listToVector(result), expected);
    deleteList(result); // Cleanup
}

TEST_F(Testing, Partition_MixedValues)
{
    ListNode *head = buildList({1, 4, 3, 2, 5, 2});
    ListNode *result = solution.partition(head, 3);
    std::vector<int> expected = {1, 2, 2, 4, 3, 5};
    EXPECT_EQ(listToVector(result), expected);
    deleteList(result); // Cleanup
}

TEST_F(Testing, Partition_XInMiddle)
{
    ListNode *head = buildList({1, 4, 3, 2, 5, 2});
    ListNode *result = solution.partition(head, 4);
    std::vector<int> expected = {1, 3, 2, 2, 4, 5};
    EXPECT_EQ(listToVector(result), expected);
    deleteList(result); // Cleanup
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
