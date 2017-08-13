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

void subTest3(Test& test)
{
  HashTable<int,std::string> hash(101);

  hash.insert(3,"Hello");

  std::string searched = "";
  test.assert(hash.findKey(3,searched));

  test.assert(searched == "Hello");
}

void subTest4(Test& test)
{
  HashTable<std::string,std::string> hash;

  test.assert(hash.insert("123","Hello"));

  test.assert(!hash.insert("123","Jello"));

}

int main()
{
  Test test("HashTableTest");

  test.addSubTest(*subTest1);
  test.addSubTest(*subTest2);
  test.addSubTest(*subTest3);
  test.addSubTest(*subTest4);

  test.run();

  return 0;
}
