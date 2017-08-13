#include <iostream>
#include <string>

#include <test.hpp>
#include "../hash_table/hash_table.hpp"

void subTest1(Test& test)
{
  HashTable<int,std::string> hash;

  test.assert(hash.getSize() == DEFAULT_HASH_SIZE);
}

void subTest2(Test& test)
{
  HashTable<int,std::string> hash(101);

  test.assert(hash.getSize() == 101);
}

int main()
{
  Test test("HashTableTest");

  test.addSubTest(*subTest1);
  test.addSubTest(*subTest2);

  test.run();

  return 0;
}
