#include <gtest/gtest.h>
#include <sstream>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    string simplifyPath(string path)
    {
        if (path.size() == 1) {
            return path;
        }
        stack<string> st;
        string tmp;
        char delimiter = '/';
        int prev = 0;
        int pos = 0;
        while (pos != string::npos) {
            pos = path.find(delimiter, prev);
            tmp = path.substr(prev, pos - prev);
            if (tmp == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            }
            else if (tmp == "." || tmp == "") {
            }
            else {
                st.push(tmp);
            }
            prev = pos + 1;
        }
        string result;
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }
        return result.empty() ? "/" : result;
    }
    string simplifyPath2(string path)
    {
        stack<string> st;
        string tmp;
        stringstream ss(path);
        while (getline(ss, tmp, '/')) {
            if (tmp == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            }
            else if (!tmp.empty() && tmp != ".") {
                st.push(tmp);
            }
        }
        string result;
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }
        return result.empty() ? "/" : result;
    }
};

class Testing : public testing::Test {
protected:
    int testnum = 1;

public:
    Solution s;
    string (Solution::*func[2])(string) = {&Solution::simplifyPath,
                                           &Solution::simplifyPath2};
};

TEST_F(Testing, t1) { EXPECT_EQ((s.*func[testnum])("/home/"), "/home"); }

TEST_F(Testing, t2) { EXPECT_EQ((s.*func[testnum])("/../"), "/"); }

TEST_F(Testing, t3)
{
    EXPECT_EQ((s.*func[testnum])("/home//foo/"), "/home/foo");
}

TEST_F(Testing, t4) { EXPECT_EQ((s.*func[testnum])("/a/./b/../../c/"), "/c"); }

TEST_F(Testing, t5)
{
    EXPECT_EQ((s.*func[testnum])("/a/../../b/../c//.//"), "/c");
}

TEST_F(Testing, t6)
{
    EXPECT_EQ((s.*func[testnum])("/a//b////c/d//././/.."), "/a/b/c");
}
