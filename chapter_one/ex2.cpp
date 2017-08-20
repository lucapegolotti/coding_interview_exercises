#include <iostream>
#include <string>

#include <test.hpp>
#include <printlog.hpp>

void reverseCString(char* string, const unsigned int& size)
{
  // ... because last character is \0
  unsigned int realSize = size-1;
  for (int i = 0; i < realSize/2; i++)
  {
    char aux = string[i];
    string[i] = string[realSize-1-i];
    string[realSize-1-i] = aux;
  }
}

void reverseCString(char* string)
{
  char* end = string;
  char aux;

  while (*end != '\0')
    end++;
  end--;

  while (string < end)
  {
    aux = *string;
    *string = *end;
    *end = aux;
    string++;
    end--;
  }
}

void subTest1(Test& test)
{
  char str[12] = "hello world";
  reverseCString(str, 12);

  std::string out(str);
  std::string check = "dlrow olleh";
  test.assert(out == check);
}

void subTest2(Test& test)
{
  char str[] = "Snow";
  reverseCString(str, 5);

  std::string out(str);
  std::string check = "wonS";
  test.assert(out == check);
}

void subTest3(Test& test)
{
  char str[12] = "hello world";
  reverseCString(str);

  std::string out(str);
  std::string check = "dlrow olleh";
  test.assert(out == check);
}

void subTest4(Test& test)
{
  char str[] = "Snow";
  reverseCString(str);

  std::string out(str);
  std::string check = "wonS";
  test.assert(out == check);
}


int main()
{
  Test test("Ex1.2");

  test.addSubTest(*subTest1);
  test.addSubTest(*subTest2);
  test.addSubTest(*subTest3);
  test.addSubTest(*subTest4);

  test.run();

  return 0;
}
