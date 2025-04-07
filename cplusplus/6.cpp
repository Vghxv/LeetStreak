#include <gtest/gtest.h>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows)
    {
        string result;
        if (numRows == 1) {
            return s;
        }
        for (int i = 0; i < s.size(); i++) {
            if (i % ((numRows - 1) << 1) == 0) {
                result += s[i];
            }
        }
        for (int k = 1; k < numRows - 1; k++) {
            for (int i = 0; i < s.size(); i++) {
                if (i % ((numRows - 1) << 1) == k ||
                    i % ((numRows - 1) << 1) == ((numRows - 1) << 1) - k) {
                    result += s[i];
                }
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (i % ((numRows - 1) << 1) == numRows - 1) {
                result += s[i];
            }
        }
        return result;
    }
};

class Testing : public testing::Test {
public:
    Solution s;
};

TEST_F(Testing, Case)
{
    EXPECT_EQ(s.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
    EXPECT_EQ(s.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
    EXPECT_EQ(s.convert("A", 1), "A");
}
