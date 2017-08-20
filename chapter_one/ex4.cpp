#include <iostream>
#include <string>

#include <test.hpp>
#include <printlog.hpp>

bool areAnagrams(const std::string& string1, const std::string& string2)
{
  unsigned int n1,n2;
  int check[256];

  n1 = string1.size();
  n2 = string2.size();
  if (n1 != n2)
  {
    return false;
  }

  for (int i = 0; i < 256; i++) check[i] = false;

  for (int i = 0; i < n1; i++)
  {
    check[string1[i]]++;
    check[string2[i]]--;
  }

  for (int i = 0; i < 256; i++)
  {
    if (check[i] != 0)
      return false;
  }

  return true;
}

void subTest1(Test& test)
{
  std::string str1 = "hello";
  std::string str2 = "lohel";

  test.assert(areAnagrams(str1,str2));
}

void subTest2(Test& test)
{
  std::string str1 = "hello";
  std::string str2 = "lohel4";

  test.assert(!areAnagrams(str1,str2));

  str1 = "hello";
  str2 = "tleov";

  test.assert(!areAnagrams(str1,str2));
}

void subTest3(Test& test)
{
  std::string str1 = "";
  std::string str2 = "";

  test.assert(areAnagrams(str1,str2));
}

void subTest4(Test& test)
{
  std::string str1 = "llll";
  std::string str2 = "tttt";

  test.assert(!areAnagrams(str1,str2));
}

int main()
{
  Test test("Ex1.4");

  test.addSubTest(*subTest1);
  test.addSubTest(*subTest2);
  test.addSubTest(*subTest3);
  test.addSubTest(*subTest4);

  test.run();

  return 0;
}
