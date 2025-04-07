#include <vector>
#include <gtest/gtest.h>
using namespace std;

class Solution {
    public:
        int candy(vector<int>& ratings) {
            vector<int> ans (ratings.size(), 1);
            for (int i = 1; i < ratings.size(); i++) {
                if (ratings[i] > ratings[i - 1]) {
                    ans[i] = ans[i - 1] + 1;
                }
            }
            for (int i = ratings.size() - 2; i >= 0; i--) {
                if (ratings[i] > ratings[i + 1]) {
                    ans[i] = max(ans[i], ans[i + 1] + 1);
                }
            }
            int sum = 0;
            for (int i = 0; i < ans.size(); i++) {
                sum += ans[i];
            }
            return sum;
        }
    };

class SolutionTest : public ::testing::Test {
    protected:
        Solution solution;
};

TEST_F(SolutionTest, Test1) {
    vector<int> ratings = {1, 0, 2};
    EXPECT_EQ(solution.candy(ratings), 5);
}

TEST_F(SolutionTest, Test2) {
    vector<int> ratings = {1, 2, 2};
    EXPECT_EQ(solution.candy(ratings), 4);
}



int main (int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}