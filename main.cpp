#include "gmock/gmock.h"
#include "similiarChecker.cpp"

using namespace testing;

class SimiliarCheckerFIxture : public testing::Test
{
public:
  similiarChecker checker;
};

TEST_F(SimiliarCheckerFIxture, checkStringLength_60)
{
  int expected = 60;
  int real = checker.scoreStringLengthCheck("ASD", "DSA");

  EXPECT_EQ(expected, real);
}

TEST_F(SimiliarCheckerFIxture, checkStringLength_0)
{
  int expected = 0;
  int real = checker.scoreStringLengthCheck("A", "BB");

  EXPECT_EQ(expected, real);
}

TEST_F(SimiliarCheckerFIxture, checkStringLength_middle)
{
  int expected = 20;
  int real = checker.scoreStringLengthCheck("AAABB", "BAA");

  EXPECT_EQ(expected, real);
}

TEST_F(SimiliarCheckerFIxture, checkStringLength_middle2)
{
  int expected = 30;
  int real = checker.scoreStringLengthCheck("AA", "AAE");

  EXPECT_EQ(expected, real);
}


int main()
{
  ::testing::InitGoogleMock();
  return RUN_ALL_TESTS();
}