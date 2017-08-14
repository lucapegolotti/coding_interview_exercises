#include <iostream>
#include <string>

#include <test.hpp>
#include <printlog.hpp>

void eliminateDuplicates(std::string& input)
{
  unsigned int size = input.size();

  for (int i = 0; i < size; i++)
  {
    for (int j = i+1; j < size; j++)
    {
      if (input[i] == input[j])
      {
        size--;
        for (int k = j; k < size; k++)
        {
          // translates one position left
          input[k] = input[k+1];
        }
        j--;
      }
    }
  }
  input = input.substr(0,size);
}

void subTest1(Test& test)
{
  std::string hello = "Hello";

  eliminateDuplicates(hello);
  test.assert(hello == "Helo");
}

void subTest2(Test& test)
{
  std::string ls = "llllllllllllllll";

  eliminateDuplicates(ls);
  test.assert(ls == "l");
}

void subTest3(Test& test)
{
  std::string ls = "llloooooolllll";

  eliminateDuplicates(ls);
  test.assert(ls == "lo");
}

void subTest4(Test& test)
{
  std::string ls = "1234567890";

  eliminateDuplicates(ls);
  test.assert(ls == "1234567890");
}


int main()
{
  Test test("Ex3");

  test.addSubTest(*subTest1);
  test.addSubTest(*subTest2);
  test.addSubTest(*subTest3);
  test.addSubTest(*subTest4);

  test.run();

  printlog(YELLOW, "ATTENTION: the solution on the book is more efficient");

  return 0;
}
