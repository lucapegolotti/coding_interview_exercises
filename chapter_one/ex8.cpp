#include <iostream>
#include <string>
#include <math.h>

#include <test.hpp>
#include <printlog.hpp>

// checks if string2 is substring of string1
bool isSubstring(std::string string1, std::string string2)
{
  unsigned int n1 = string1.length();
  unsigned int n2 = string2.length();

  if (n2 > n1)
    return false;

  unsigned int count;

  for (int i = 0; i < n1-n2+1; i++)
  {
    count = 0;

    while (count < n2 && string1[i+count] == string2[count])
    {
      count++;
    }

    if (count == n2)
      return true;
  }

  return false;
}

// checks if string2 is rotation of string1
bool isRotation(std::string string1, std::string string2)
{
  if (string1.length() != string2.length())
    return false;

  std::string doubleString2 = string2 + string2;

  return isSubstring(doubleString2, string1);
}

void subTest1(Test& test)
{
  std::string string1 = "Hello World";
  std::string string2 = "Hello";

  test.assert(isSubstring(string1, string2));
}

void subTest2(Test& test)
{
  std::string string1 = "Hello World";
  std::string string2 = "lo Wo";

  test.assert(isSubstring(string1, string2));
}

void subTest3(Test& test)
{
  std::string string1 = "Hello World";
  std::string string2 = "lo Wo1";

  test.assert(!isSubstring(string1, string2));
}

void subTest4(Test& test)
{
  std::string string1 = "5";
  std::string string2 = "lo Wo1";

  test.assert(!isSubstring(string1, string2));
}

void subTest5(Test& test)
{
  std::string string1 = "waterbottle";
  std::string string2 = "erbottlewat";

  test.assert(isRotation(string1, string2));
}

void subTest6(Test& test)
{
  std::string string1 = "watebrbottle";
  std::string string2 = "erbottlewat";

  test.assert(!isRotation(string1, string2));
}

void subTest7(Test& test)
{
  std::string string1 = "Mickey Mouse";
  std::string string2 = "y MouseMicke";

  test.assert(isRotation(string1, string2));
}

int main()
{
  Test test("Ex8");

  test.addSubTest(*subTest1);
  test.addSubTest(*subTest2);
  test.addSubTest(*subTest3);
  test.addSubTest(*subTest4);
  test.addSubTest(*subTest5);
  test.addSubTest(*subTest6);
  test.addSubTest(*subTest7);

  test.run();

  return 0;
}
