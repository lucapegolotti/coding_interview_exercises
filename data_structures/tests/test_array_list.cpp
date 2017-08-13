#include <iostream>
#include <string>

#include <test.hpp>
#include "../array_list/array_list.hpp"

void subTest1(Test& test)
{
  ArrayList<int> array;
  test.assert(array.getSize() == 0);
}

void subTest2(Test& test)
{
  ArrayList<int> array(10);
  test.assert(array.getSize() == 0);
}

void subTest3(Test& test)
{
  ArrayList<int> array(10);

  array.insert(4);
  test.assert(array[0] == 4);
}

void subTest4(Test& test)
{
  ArrayList<int> array(10);
  test.assert(array.getMaxSize() == 10);

  for (int i = 0; i < 11; i++)
  {
    array.insert(i);
  }

  test.assert(array.getMaxSize() == 20);

}

int main()
{
  Test test("ArrayListTest");

  test.addSubTest(*subTest1);
  test.addSubTest(*subTest2);
  test.addSubTest(*subTest3);
  test.addSubTest(*subTest4);

  test.run();

  return 0;
}
