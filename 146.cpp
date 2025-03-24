#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
struct Node {
public:
    int key;
    int value;
    Node *next;
    Node *prev;
    Node() : key(0), value(0), next(nullptr), prev(nullptr) {}
    Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};

class NodeQueue {
    Node *head;
    Node *tail;

public:
    NodeQueue()
    {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    ~NodeQueue()
    {
        Node *p = head;
        while (p != nullptr) {
            Node *tmp = p;
            p = p->next;
            delete tmp;
        }
    }

    void push(Node *node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    Node *pop()
    {
        if (tail->prev == head) {
            return nullptr;
        }
        Node *prev = tail->prev;
        prev->prev->next = tail;
        tail->prev = prev->prev;
        return prev;
    }

    void update(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }
};

class LRUCache {
    NodeQueue _queue;
    unordered_map<int, Node *> _map;
    int _capacity;
    int _length;

public:
    LRUCache(int capacity)
    {
        _capacity = capacity;
        _length = 0;
    }

    int get(int key)
    {
        if (_map.find(key) == _map.end()) {
            return -1;
        }
        Node *node = _map[key];
        _queue.update(node);
        return node->value;
    }

    void put(int key, int value)
    {
        if (_map.find(key) != _map.end()) {
            Node *node = _map[key];
            node->value = value;
            _queue.update(node);
            return;
        }
        Node *node = new Node(key, value);
        _map[key] = node;
        _queue.push(node);
        if (_length == _capacity) {
            Node *last = _queue.pop();
            if (last == nullptr) {
                return;
            }
            _map.erase(last->key);
            delete last;
        }
        else {
            _length++;
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class Testing : public ::testing::Test {
protected:
    LRUCache *cache;

    // Setup before each test
    void SetUp() override
    {
        // Initialize LRUCache with capacity 2 for testing
        cache = new LRUCache(2);
    }

    // Teardown after each test
    void TearDown() override
    {
        // Clean up to avoid memory leaks
        delete cache;
    }
};

// Test cases
TEST_F(Testing, TestPutAndGet)
{
    cache->put(1, 1);
    cache->put(2, 2);
    EXPECT_EQ(cache->get(1), 1);  // returns 1
    cache->put(3, 3);             // evicts key 2
    EXPECT_EQ(cache->get(2), -1); // returns -1 (not found)
    cache->put(4, 4);             // evicts key 1
    EXPECT_EQ(cache->get(1), -1); // returns -1 (not found)
    EXPECT_EQ(cache->get(3), 3);  // returns 3
    EXPECT_EQ(cache->get(4), 4);  // returns 4
}

TEST_F(Testing, TestOverwrite)
{
    cache->put(1, 1);
    cache->put(1, 10);            // update the value of key 1
    EXPECT_EQ(cache->get(1), 10); // returns 10
}

TEST_F(Testing, TestCapacity)
{
    cache->put(1, 1);
    cache->put(2, 2);
    cache->put(3, 3);             // evicts key 1
    EXPECT_EQ(cache->get(1), -1); // returns -1 (not found)
    EXPECT_EQ(cache->get(2), 2);  // returns 2
    EXPECT_EQ(cache->get(3), 3);  // returns 3
}

TEST_F(Testing, TestGetNonExistent)
{
    EXPECT_EQ(cache->get(5), -1); // returns -1 (not found)
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
