#include <iostream>
#include <string>

#include "../hash_table/hash_table.hpp"

unsigned int n_tests;


bool test1()
{
  std::cout << "Test 1 ..." << std::endl;
  HashTable<int,std::string> hash;
  n_tests++;

  return hash.getSize() == DEFAULT_HASH_SIZE;
}

bool test2()
{
  std::cout << "Test 2 ..." << std::endl;
  HashTable<int,std::string> hash(101);
  n_tests++;

  return hash.getSize() == 101;
}

int main()
{
  unsigned int passed_tests = 0;
  std::cout << "Hash Table test:\n----------------------------" << std::endl;
  n_tests = 0;

  passed_tests += test1();
  passed_tests += test2();


  std::cout << "Successful tests = " << passed_tests << "/" << n_tests << std::endl;

  return 0;
}
