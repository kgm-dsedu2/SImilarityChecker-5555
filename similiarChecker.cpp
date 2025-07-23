#include <iostream>
#include <string>

using namespace std;

class similiarChecker
{
public:
  int scoreStringLengthCheck(string str1, string str2)
  {
    int score;
    int longLen;
    int shortLen;
    if (str1.length() > str2.length())
    {
      longLen = str1.length();
      shortLen = str2.length();
    }
    else
    {
      longLen = str2.length();
      shortLen = str1.length();
    }
    score = 60 - ((longLen - shortLen) * 60 / shortLen);

    return score;
  }
};