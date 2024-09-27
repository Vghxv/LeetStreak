#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include <sstream>
using namespace std;
struct Node {
    char _c;
    bool _isWord;
    bool _isStart;
    vector<Node *> childs;
    Node() {}
    Node(char c) : _c(c)
    {
        _isWord = false;
        _isStart = false;
    }
    Node(char c, bool isWord, bool isStart)
        : _c(c), _isWord(isWord), _isStart(isStart)
    {
    }
};

class Trie {
    Node *root;

public:
    Trie() { root = new Node('#', false, false); }

    void insert(string word)
    {
        Node *node = root;
        for (char &c : word) {
            bool found = false;
            for (auto &child : node->childs) {
                if (child->_c == c) {
                    node = child;
                    found = true;
                    break;
                }
            }
            if (!found) {
                Node *newNode = new Node(c);
                node->childs.push_back(newNode);
                node = newNode;
            }
        }
        node->_isWord = true;
        return;
    }

    inline Node *searchForWord(string word)
    {
        Node *node = root;
        for (char &c : word) {
            bool found = false;
            for (auto &child : node->childs) {
                if (child->_c == c) {
                    node = child;
                    found = true;
                    break;
                }
            }
            if (!found) {
                return nullptr;
            }
        }
        return node;
    }
    bool search(string word)
    {
        Node *node = searchForWord(word);

        return node != nullptr ? node->_isWord : false;
    }

    bool startsWith(string prefix) { return searchForWord(prefix) != nullptr; }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

TEST(Trie, TC1)
{
    Trie trie;
    trie.insert("apple");
    EXPECT_EQ(trie.search("apple"), true);
    EXPECT_EQ(trie.search("app"), false);
    EXPECT_EQ(trie.startsWith("app"), true);
    trie.insert("app");
    EXPECT_EQ(trie.search("app"), true);
}

// Test Case 2: Inserting Duplicate Words
TEST(Trie, TC2_DuplicateInsertion)
{
    Trie trie;
    trie.insert("banana");
    trie.insert("banana"); // Insert duplicate
    EXPECT_EQ(trie.search("banana"), true);
    EXPECT_EQ(trie.startsWith("ban"), true);
}

// Test Case 3: Searching for Non-Existent Words and Prefixes
TEST(Trie, TC3_NonExistent)
{
    Trie trie;
    trie.insert("cat");
    trie.insert("car");
    EXPECT_EQ(trie.search("cap"), false);
    EXPECT_EQ(trie.startsWith("ca"), true);
    EXPECT_EQ(trie.startsWith("cb"), false);
    EXPECT_EQ(trie.search("carp"), false);
}

// Test Case 4: ["Trie","insert","startsWith"] [[],["hotdog"],["dog"]]
TEST(Trie, TC4)
{
    Trie trie;
    trie.insert("hotdog");
    EXPECT_EQ(trie.startsWith("dog"), false);
}

// Test Case 5: Single Character Words
TEST(Trie, TC5_SingleCharacter)
{
    Trie trie;
    trie.insert("a");
    trie.insert("b");
    trie.insert("c");
    EXPECT_EQ(trie.search("a"), true);
    EXPECT_EQ(trie.search("b"), true);
    EXPECT_EQ(trie.search("c"), true);
    EXPECT_EQ(trie.search("d"), false);
    EXPECT_EQ(trie.startsWith("a"), true);
    EXPECT_EQ(trie.startsWith("d"), false);
}

// Test Case 6: Words with Common Prefixes
TEST(Trie, TC6_CommonPrefixes)
{
    Trie trie;
    trie.insert("test");
    trie.insert("tester");
    trie.insert("testing");
    trie.insert("team");
    trie.insert("toast");

    EXPECT_EQ(trie.search("test"), true);
    EXPECT_EQ(trie.search("tester"), true);
    EXPECT_EQ(trie.search("testing"), true);
    EXPECT_EQ(trie.search("team"), true);
    EXPECT_EQ(trie.search("toast"), true);
    EXPECT_EQ(trie.search("te"), false);
    EXPECT_EQ(trie.startsWith("te"), true);
    EXPECT_EQ(trie.startsWith("tes"), true);
    EXPECT_EQ(trie.startsWith("toast"), true);
    EXPECT_EQ(trie.startsWith("toaster"), false);
}

// Test Case 7: Case Sensitivity
TEST(Trie, TC7_CaseSensitivity)
{
    Trie trie;
    trie.insert("Dog");
    trie.insert("dog");
    EXPECT_EQ(trie.search("Dog"), true);
    EXPECT_EQ(trie.search("dog"), true);
    EXPECT_EQ(trie.search("DOg"), false);
    EXPECT_EQ(trie.startsWith("Do"), true);
    EXPECT_EQ(trie.startsWith("do"), true);
    EXPECT_EQ(trie.startsWith("DO"), false);
}

// Test Case 8: Inserting and Searching Multiple Words
TEST(Trie, TC8_MultipleWords)
{
    Trie trie;
    vector<string> words = {"hello",     "helium", "hero",
                            "heroplane", "heat",   "heap"};
    for (const auto &word : words) {
        trie.insert(word);
    }

    for (const auto &word : words) {
        EXPECT_EQ(trie.search(word), true);
    }

    EXPECT_EQ(trie.search("hell"), false);
    EXPECT_EQ(trie.startsWith("he"), true);
    EXPECT_EQ(trie.startsWith("her"), true);
    EXPECT_EQ(trie.startsWith("hez"), false);
}

// Test Case 9: Long Words
TEST(Trie, TC9_LongWords)
{
    Trie trie;
    string longWord = "abcdefghijklmnopqrstuvwxyz";
    trie.insert(longWord);
    EXPECT_EQ(trie.search(longWord), true);
    EXPECT_EQ(trie.startsWith("abcdefghijklmnop"), true);
    EXPECT_EQ(trie.startsWith("abcdefghijklmnoz"), false);
    EXPECT_EQ(trie.search("abcdefghijklmnopqrstuvwxy"), false);
}

// Test Case 10: Mixed Insertions and Searches
TEST(Trie, TC10_MixedOperations)
{
    Trie trie;
    trie.insert("flower");
    trie.insert("flow");
    trie.insert("flight");
    trie.insert("flask");
    trie.insert("flute");

    EXPECT_EQ(trie.search("flow"), true);
    EXPECT_EQ(trie.search("flower"), true);
    EXPECT_EQ(trie.search("flight"), true);
    EXPECT_EQ(trie.search("flask"), true);
    EXPECT_EQ(trie.search("flute"), true);
    EXPECT_EQ(trie.search("fl"), false);
    EXPECT_EQ(trie.startsWith("fl"), true);
    EXPECT_EQ(trie.startsWith("flo"), true);
    EXPECT_EQ(trie.startsWith("fli"), true);
    EXPECT_EQ(trie.startsWith("flu"), true);
    EXPECT_EQ(trie.startsWith("fly"), false);
}

// ["Trie","insert","insert","insert","insert","insert","insert","search","search","search","search","search","search","search","search","search","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith"]
// [[],["app"],["apple"],["beer"],["add"],["jam"],["rental"],["apps"],["app"],["ad"],["applepie"],["rest"],["jan"],["rent"],["beer"],["jam"],["apps"],["app"],["ad"],["applepie"],["rest"],["jan"],["rent"],["beer"],["jam"]]

TEST(Trie, TC11)
{
    Trie trie;
    trie.insert("app");
    trie.insert("apple");
    trie.insert("beer");
    trie.insert("add");
    trie.insert("jam");
    trie.insert("rental");
    EXPECT_EQ(trie.search("apps"), false);
    EXPECT_EQ(trie.search("app"), true);
    EXPECT_EQ(trie.search("ad"), false);
    EXPECT_EQ(trie.search("applepie"), false);
    EXPECT_EQ(trie.search("rest"), false);
    EXPECT_EQ(trie.search("jan"), false);
    EXPECT_EQ(trie.search("rent"), false);
    EXPECT_EQ(trie.search("beer"), true);
    EXPECT_EQ(trie.search("jam"), true);
    EXPECT_EQ(trie.startsWith("apps"), false);
    EXPECT_EQ(trie.startsWith("app"), true);
    EXPECT_EQ(trie.startsWith("ad"), true);
    EXPECT_EQ(trie.startsWith("applepie"), false);
    EXPECT_EQ(trie.startsWith("rest"), false);
    EXPECT_EQ(trie.startsWith("jan"), false);
    EXPECT_EQ(trie.startsWith("rent"), true);
    EXPECT_EQ(trie.startsWith("beer"), true);
    EXPECT_EQ(trie.startsWith("jam"), true);
}

// Main function to run all tests
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
