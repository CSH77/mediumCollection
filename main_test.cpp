#include "gtest/gtest.h"
#include "main.cpp"

TEST(Solution, testOne)
{
    Solution obj;
    vector<int> input = {1,1,1,2,2,3};
    vector<int> answer = {1,2};
    EXPECT_EQ ( answer, obj.topKFrequent(input, 2) );
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}