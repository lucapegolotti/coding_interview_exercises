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
  list.insert(1);
  test.assert(list.getSize() == 1);
  list.insert(2);
  test.assert(list.getSize() == 2);
}

void subTest3(Test& test)
{
  LinkedList<int> list;
  list.insert(10);
  list.insert(2);
  list.insert(-4);

  test.assert(list.contain(2));
  test.assert(!list.contain(-100));

}


int main()
{
  Test test("LinkedListTest");

  test.addSubTest(*subTest1);
  test.addSubTest(*subTest2);
  test.addSubTest(*subTest3);

  test.run();

  return 0;
}
