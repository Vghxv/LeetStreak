#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
struct Node {
    char _c;
    bool isEnd = false;
    vector<Node *> childs;
    Node() {}
    Node(char c) : _c(c) {}
};

class WordDictionary {
    Node *root;
    bool search(string &word, int idx, Node *cur)
    {
        if (idx == word.size()) {
            return cur->isEnd;
        }
        if (word[idx] == '.') {
            for (Node *child : cur->childs) {
                if (search(word, idx + 1, child)) {
                    return true;
                }
            }
            return false;
        }
        else {
            for (Node *child : cur->childs) {
                if (child->_c == word[idx]) {
                    return search(word, idx + 1, child);
                }
            }
            return false;
        }
    }

public:
    WordDictionary() { root = new Node('#'); }

    void addWord(string word)
    {
        Node *cur = root;
        for (char &c : word) {
            bool found = false;
            for (Node *child : cur->childs) {
                if (child->_c == c) {
                    cur = child;
                    found = true;
                    break;
                }
            }
            if (!found) {
                Node *newNode = new Node(c);
                cur->childs.push_back(newNode);
                cur = newNode;
            }
        }
        cur->isEnd = true;
    }

    bool search(string word) { return search(word, 0, root); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

TEST(WordDictionary, addWord)
{
    WordDictionary *obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    EXPECT_EQ(obj->search("pad"), false);
    EXPECT_EQ(obj->search("bad"), true);
    EXPECT_EQ(obj->search(".ad"), true);
    EXPECT_EQ(obj->search("b.."), true);
}
TEST(WordDictionary, AdditionalTests)
{
    WordDictionary *obj = new WordDictionary();

    // Adding words
    obj->addWord("cat");
    obj->addWord("car");
    obj->addWord("bat");
    obj->addWord("bar");
    obj->addWord("rat");
    obj->addWord("ran");

    // Test exact matches
    EXPECT_EQ(obj->search("cat"), true);
    EXPECT_EQ(obj->search("car"), true);
    EXPECT_EQ(obj->search("bat"), true);
    EXPECT_EQ(obj->search("bar"), true);
    EXPECT_EQ(obj->search("rat"), true);
    EXPECT_EQ(obj->search("ran"), true);

    // Test for words not added
    EXPECT_EQ(obj->search("can"), false);
    EXPECT_EQ(obj->search("rar"), false);
    EXPECT_EQ(obj->search("tab"), false);

    // Test with single wildcard
    EXPECT_EQ(obj->search("c.t"), true);
    EXPECT_EQ(obj->search("b.r"), true);
    EXPECT_EQ(obj->search("r.t"), true);

    // Test with multiple wildcards
    EXPECT_EQ(obj->search("..t"), true); // matches "cat", "bat", "rat"
    EXPECT_EQ(obj->search("c.."), true); // matches "cat", "car"
    EXPECT_EQ(obj->search("..."), true); // matches all three-letter words

    // Test edge cases (empty and very short words)
    WordDictionary *obj2 = new WordDictionary();
    obj2->addWord("");
    EXPECT_EQ(obj2->search(""), true); // Empty word is in the dictionary

    obj2->addWord("a");
    EXPECT_EQ(obj2->search("a"), true);  // Single character match
    EXPECT_EQ(obj2->search("."), true);  // Single wildcard match
    EXPECT_EQ(obj2->search("b"), false); // Single character mismatch
}

// ["WordDictionary","addWord","addWord","search","search","search","search","search","search"]
// [[],["a"],["a"],["."],["a"],["aa"],["a"],[".a"],["a."]]

TEST(WordDictionary, AdditionalTests2)
{
    WordDictionary *obj = new WordDictionary();
    obj->addWord("a");
    obj->addWord("a");
    EXPECT_EQ(obj->search("."), true);
    EXPECT_EQ(obj->search("a"), true);
    EXPECT_EQ(obj->search("aa"), false);
    EXPECT_EQ(obj->search("a"), true);
    EXPECT_EQ(obj->search(".a"), false);
    EXPECT_EQ(obj->search("a."), false);
}
// ["WordDictionary","addWord","addWord","addWord","addWord","search","search","addWord","search","search","search","search","search","search"]
// [[],["at"],["and"],["an"],["add"],["a"],[".at"],["bat"],[".at"],["an."],["a.d."],["b."],["a.d"],["."]]

TEST(WordDictionary, AdditionalTests3)
{
    WordDictionary *obj = new WordDictionary();
    obj->addWord("at");
    obj->addWord("and");
    obj->addWord("an");
    obj->addWord("add");
    EXPECT_EQ(obj->search("a"), false);
    EXPECT_EQ(obj->search(".at"), false);
    obj->addWord("bat");
    EXPECT_EQ(obj->search(".at"), true);
    EXPECT_EQ(obj->search("an."), true);
    EXPECT_EQ(obj->search("a.d."), false);
    EXPECT_EQ(obj->search("b."), false);
    EXPECT_EQ(obj->search("a.d"), true);
    EXPECT_EQ(obj->search("."), false);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}