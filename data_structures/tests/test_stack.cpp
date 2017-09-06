#include <iostream>
#include <string>

#include <test.hpp>
#include "../stack/stack.hpp"

void subTest1(Test& test)
{
  Stack<int> stack;
  test.assert(stack.getSize() == 0);
}

void subTest2(Test& test)
{
  Stack<int> stack;
  stack.push(1);
  test.assert(stack.getSize() == 1);
  stack.push(2);
  test.assert(stack.getSize() == 2);
}

void subTest3(Test& test)
{
  Stack<int> stack;
  stack.push(10);
  stack.push(2);
  stack.push(-4);

  Stack<int>::Node poppedNode;

  test.assert(stack.pop(poppedNode));
  test.assert(poppedNode.data == -4);
}

void subTest4(Test& test)
{
  Stack<int> stack;
  stack.push(10);
  stack.push(2);
  stack.push(-4);

  Stack<int>::Node poppedNode;

  test.assert(stack.pop(poppedNode));
  test.assert(stack.pop(poppedNode));
  test.assert(stack.pop(poppedNode));
  test.assert(!stack.pop(poppedNode));

}


int main()
{
  Test test("StackTest");

  test.addSubTest(*subTest1);
  test.addSubTest(*subTest2);
  test.addSubTest(*subTest3);
  test.addSubTest(*subTest4);

  test.run();

  return 0;
}
