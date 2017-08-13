#include <iostream>
#include <string>

#include "../linked_list/linked_list.hpp"

unsigned int n_tests;


bool test1()
{
  std::cout << "Test 1 ..." << std::endl;
  LinkedList<int> list;
  n_tests++;

  return list.getSize() == 0;
}

int main()
{
  unsigned int passed_tests = 0;
  std::cout << "Linked List test:\n----------------------------" << std::endl;
  n_tests = 0;

  passed_tests += test1();


  std::cout << "Successful tests = " << passed_tests << "/" << n_tests << std::endl;

  return 0;
}
