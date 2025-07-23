#include <iostream>
#include <string>

using namespace std;

struct LongNShortLength
{
  int LongLen;
  int ShortLen;
};

class similiarChecker
{
public:
  int scoreStringLengthCheck(string str1, string str2)
  {
    int score;
    score = scoreLengthThroughLengths(GetLongNShortLength(str1, str2));

    return score;
  }
  LongNShortLength GetLongNShortLength(std::string& str1, std::string& str2)
  {
    LongNShortLength lengths;
    if (str1.length() > str2.length())
    {
      lengths.LongLen = str1.length();
      lengths.ShortLen = str2.length();
    }
    else
    {
      lengths.LongLen = str2.length();
      lengths.ShortLen = str1.length();
    }

    return lengths;
  }
  int scoreLengthThroughLengths(LongNShortLength lengths)
  {
    int score = 120 - (60 * lengths.LongLen / lengths.ShortLen);
    if (score < 0)
    {
      score = 0;
    }

    return score;
  }
};