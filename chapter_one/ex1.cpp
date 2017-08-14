#include <iostream>

#include <test.hpp>
#include <hash_table/hash_table.hpp>
#include <map>

bool hasUniqueCharactersWithCustomHashTable(const std::string& input)
{
  unsigned int length = input.size();
  HashTable<char,int> hash;

  for (int i = 0; i < length; i++)
  {
    if (!hash.insert(input[i],i))
      return false;
  }
  return true;
}

bool hasUniqueCharactersWithStandardMap(const std::string& input)
{
  unsigned int length = input.size();

  std::pair<std::map<char,int>::iterator,bool> ret;
  std::map<char,int> map;

  for (int i = 0; i < length; i++)
  {
    ret = map.insert(std::pair<char,int>(input[i],i));
    if (!ret.second)
      return false;
  }
  return true;
}

bool hasUniqueCharactersNoDataStructures(const std::string& input)
{
  unsigned int length = input.size();

  for (int i = 0; i < length; i++)
  {
    for (int j = i+1; j < length; j++)
    {
      if (input[i] == input[j])
        return false;
    }
  }
  return true;
}

bool hasUniqueCharactersArray(const std::string& input)
{
  unsigned int length = input.size();

  bool check[256];

  for (int i = 0; i < 256; i++)
  {
    check[i] = false;
  }

  for (int i = 0; i < length; i++)
  {
    if (check[input[i]])
      return false;
    check[input[i]] = true;
  }
  return true;
}

bool hasUniqueCharactersBitwise(const std::string& input)
{
  unsigned int length = input.size();

  int check = 0;

  for (int i = 0; i < length; i++)
  {
    unsigned int shift = input[i]-'a';
    if ((check & (1 << shift)) > 0)
      return false;
    check |= (1 << shift);
  }

  return true;
}

void subTest1(Test& test)
{
  test.assert(hasUniqueCharactersWithCustomHashTable("Helo"));
  test.assert(!hasUniqueCharactersWithCustomHashTable("Bubble"));
}

void subTest2(Test& test)
{
  test.assert(hasUniqueCharactersWithStandardMap("Helo"));
  test.assert(!hasUniqueCharactersWithStandardMap("Bubble"));
}

void subTest3(Test& test)
{
  test.assert(hasUniqueCharactersNoDataStructures("Helo"));
  test.assert(!hasUniqueCharactersNoDataStructures("Bubble"));
}

void subTest4(Test& test)
{
  test.assert(hasUniqueCharactersArray("Helo"));
  test.assert(!hasUniqueCharactersArray("Bubble"));
}

void subTest5(Test& test)
{
  test.assert(hasUniqueCharactersBitwise("Helo"));
  test.assert(!hasUniqueCharactersBitwise("Bubble"));
}

int main()
{
  Test test("Ex1");

  test.addSubTest(*subTest1);
  test.addSubTest(*subTest2);
  test.addSubTest(*subTest3);
  test.addSubTest(*subTest4);
  test.addSubTest(*subTest5);

  test.run();

  return 0;
}
