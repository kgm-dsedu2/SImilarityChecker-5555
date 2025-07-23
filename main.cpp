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
  CheckStringLengthScore("QQQQQQ", "DSRDSR", 60);
  CheckStringLengthScore("ASDAJJW", "ADSAASD", 60);
  CheckStringLengthScore("A", "D", 60);
}


TEST_F(SimiliarCheckerFIxture, checkStringLength_0)
{
  CheckStringLengthScore("A", "BB", 0);
  CheckStringLengthScore("AB", "EDASW", 0);
  CheckStringLengthScore("TQQQ", "F", 0);
}

TEST_F(SimiliarCheckerFIxture, checkStringLength_middlescore)
{
  CheckStringLengthScore("AAABB", "BAA", 20);
  CheckStringLengthScore("AA", "AAE", 30);
  CheckStringLengthScore("AAAVSWE", "QQQWWWAAE", 43);
}

int main()
{
  ::testing::InitGoogleMock();
  return RUN_ALL_TESTS();
}