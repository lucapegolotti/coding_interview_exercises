#include <iostream>
#include <string>

#include <test.hpp>
#include <printlog.hpp>

void replaceInString(std::string& string)
{
  unsigned int n = string.size();
  std::string output = "";

  for (int i = 0; i < n; i++)
  {
    char currChar = string[i];
    if (currChar == ' ')
    {
      output += "%20";
    }
    else
    {
      output += currChar;
    }
  }

  string = output;
}

void subTest1(Test& test)
{
  std::string stringToTest = "Hello World";
  replaceInString(stringToTest);

  test.assert(stringToTest == "Hello%20World");
}

void subTest2(Test& test)
{
  std::string stringToTest = "Hello  World";
  replaceInString(stringToTest);

  test.assert(stringToTest == "Hello%20%20World");
}

void subTest3(Test& test)
{
  std::string stringToTest = "More than two words";
  replaceInString(stringToTest);

  test.assert(stringToTest == "More%20%than%20%two%20% words");
}

int main()
{
  Test test("Ex5");

  test.addSubTest(*subTest1);
  test.addSubTest(*subTest2);

  test.run();

  std::string msg;
  msg = "ATTENTION: the solution on the book is different but I don't like it\n";

  printlog(YELLOW, msg);

  return 0;
}
