#include <array>
#include <gtest/gtest.h>
#include <unordered_map>
#include <vector>
using namespace std;
class RandomizedSet {
private:
    unordered_map<int, int> map;
    vector<int> arr;

public:
    RandomizedSet() {}

    bool insert(int val)
    {
        if (map.find(val) != map.end()) {
            return false;
        }
        map[val] = arr.size();
        arr.push_back(val);
        return true;
    }

    bool remove(int val)
    {
        if (map.find(val) != map.end()) {
            int last = arr.back();
            arr[map[val]] = last;
            map[last] = map[val];
            map.erase(val);
            arr.pop_back();
            return true;
        }
        return false;
    }

    int getRandom() { return arr[rand() % arr.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

class Testing : public testing::Test {
public:
    RandomizedSet *obj = new RandomizedSet();
    void setup() {}

    void teardown() { delete obj; }
};

TEST_F(Testing, test_1)
{
    setup();
    EXPECT_EQ(obj->insert(1), true);
    EXPECT_EQ(obj->remove(2), false);
    EXPECT_EQ(obj->insert(2), true);
    EXPECT_EQ(obj->remove(2), true);
    EXPECT_EQ(obj->getRandom(), 1);
    EXPECT_EQ(obj->remove(1), true);
    EXPECT_EQ(obj->insert(2), true);
    EXPECT_EQ(obj->getRandom(), 2);
    teardown();
}

TEST_F(Testing, test_2)
{
    setup();
    EXPECT_EQ(obj->insert(0), true);
    EXPECT_EQ(obj->insert(1), true);
    EXPECT_EQ(obj->remove(0), true);
    EXPECT_EQ(obj->insert(2), true);
    EXPECT_EQ(obj->remove(1), true);
    EXPECT_EQ(obj->getRandom(), 2);
    teardown();
}
