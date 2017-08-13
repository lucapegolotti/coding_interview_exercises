#include <iostream>
#include <string>

#include <test.hpp>
#include "../linked_list/linked_list.hpp"

void subTest1(Test& test)
{
  LinkedList<int> list;
  test.assert(list.getSize() == 0);
}

void subTest2(Test& test)
{
  LinkedList<int> list;
  list.add(1);
  test.assert(list.getSize() == 1);
}


int main()
{
  Test test("LinkedListTest");

  test.addSubTest(*subTest1);
  test.addSubTest(*subTest2);

  test.run();

  return 0;
}
