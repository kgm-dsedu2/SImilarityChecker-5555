#include "gmock/gmock.h"
#include "similiarChecker.cpp"

using namespace testing;

TEST(TS, checkStringLength_60)
{
  similiarChecker app;
  int expected = 60;
  int real = app.scoreStringLengthCheck("ASD", "DSA");

  EXPECT_EQ(expected, real);
}

TEST(TS, checkStringLength_0)
{
  similiarChecker app;
  int score = app.scoreStringLengthCheck("A", "B");
}

TEST(TS, checkStringLength_middle)
{
  similiarChecker app;
  int score = app.scoreStringLengthCheck("AA", "AAE");
}


int main()
{
  ::testing::InitGoogleMock();
  return RUN_ALL_TESTS();
}