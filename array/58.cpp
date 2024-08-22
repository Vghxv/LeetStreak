#include <gtest/gtest.h>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s)
    {
        if (s.size() == 1) {
            return 1;
        }
        int i = s.size() - 1;
        while (s[i] == ' ') {
            i--;
        }
        int counter = 0;
        while (i > -1) {
            if (s[i] != ' ') {
                counter++;
                i--;
            }
            else {
                break;
            }
        }
        return counter;
    }
};

class Testing : public testing::Test {
public:
    Solution s;
    void SetUp() {}
    void TearDown(){};
};

TEST_F(Testing, case1)
{
    string str = "Hello World";
    EXPECT_EQ(s.lengthOfLastWord(str), 5);
}

TEST_F(Testing, case2)
{
    string str = "ABV sdsd";
    EXPECT_EQ(s.lengthOfLastWord(str), 4);
}

TEST_F(Testing, case3)
{
    string str = "a";
    EXPECT_EQ(s.lengthOfLastWord(str), 1);
}

TEST_F(Testing, case4)
{
    string str = "a ";
    EXPECT_EQ(s.lengthOfLastWord(str), 1);
}

TEST_F(Testing, case5)
{
    string str = " a";
    EXPECT_EQ(s.lengthOfLastWord(str), 1);
}

TEST_F(Testing, case6)
{
    string str = " a ";
    EXPECT_EQ(s.lengthOfLastWord(str), 1);
}

TEST_F(Testing, case7)
{
    string str = "a b";
    EXPECT_EQ(s.lengthOfLastWord(str), 1);
}

TEST_F(Testing, case8)
{
    string str = "   fly me   to   the moon  ";
    EXPECT_EQ(s.lengthOfLastWord(str), 4);
}

TEST_F(Testing, case9)
{
    string str = "luffy is still joyboy";
    EXPECT_EQ(s.lengthOfLastWord(str), 6);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}