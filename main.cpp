#include "gmock/gmock.h"
#include "similiarChecker.cpp"
#include "main.h"

using namespace testing;

class SimiliarCheckerFIxture : public testing::Test
{
public:
  similiarChecker checker;

  void CheckStringLengthScore(const string str1, const string str2, int expected)
  {
    int real = checker.scoreStringLengthCheck(str1, str2);
    EXPECT_EQ(expected, real);
  }
};

TEST_F(SimiliarCheckerFIxture, checkStringLength_60)
{
  CheckStringLengthScore("ASD", "DSA", 60);
}


TEST_F(SimiliarCheckerFIxture, checkStringLength_0)
{
  CheckStringLengthScore("A", "BB", 0);
}

TEST_F(SimiliarCheckerFIxture, checkStringLength_middle)
{
  CheckStringLengthScore("AAABB", "BAA", 20);
}

TEST_F(SimiliarCheckerFIxture, checkStringLength_middle2)
{
  CheckStringLengthScore("AA", "AAE", 30);
}


int main()
{
  ::testing::InitGoogleMock();
  return RUN_ALL_TESTS();
}