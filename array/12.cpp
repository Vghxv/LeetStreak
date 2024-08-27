#include <gtest/gtest.h>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    string intToRoman(int num)
    {
        static const vector<pair<int, string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};

        string result;

        for (const auto &it : roman) {
            int value = it.first;
            const string &symbol = it.second;
            while (num >= value) {
                num -= value;
                result += symbol;
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
    EXPECT_EQ(s.intToRoman(3), "III");
    EXPECT_EQ(s.intToRoman(4), "IV");
    EXPECT_EQ(s.intToRoman(9), "IX");
    EXPECT_EQ(s.intToRoman(58), "LVIII");
    EXPECT_EQ(s.intToRoman(1994), "MCMXCIV");
}
