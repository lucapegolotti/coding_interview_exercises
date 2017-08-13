#ifndef HASH_TABLE_IMP_HPP
#define HASH_TABLE_IMP_HPP

#include "hash_table.hpp"

template <class Key, class Value>
HashTable<Key,Value>::HashTable() :
  M_size(DEFAULT_HASH_SIZE)
{
  M_lists.resize(M_size);
}

template <class Key, class Value>
HashTable<Key,Value>::~HashTable()
{
}

template <class Key, class Value>
HashTable<Key,Value>::HashTable(unsigned int size) :
  M_size(size)
{
  M_lists.resize(M_size);
}

template <class Key, class Value>
unsigned int HashTable<Key,Value>::getSize() const
{
  return M_size;
}

template <class Key, class Value>
void HashTable<Key,Value>::insert(const Key& keyToInsert,
                                  const Value& valueToInsert)
{
  KeyValuePair keyvalue(keyToInsert, valueToInsert);

  M_lists[hashFunction(keyToInsert)].insert(keyvalue);
}

template <class Key, class Value>
bool HashTable<Key,Value>::findKey(const Key& keyToFind, Value& correspondingValue) const
{
  KeyValuePair keyvalue(keyToFind, correspondingValue);

  bool ret = M_lists[hashFunction(keyToFind)].contain(keyvalue);
  correspondingValue = keyvalue.getValue();

  return ret;
}


template <class Key, class Value>
unsigned int HashTable<Key,Value>::hashFunction(const int& key) const
{
  return std::abs(key) % M_size;
}

template <class Key, class Value>
unsigned int HashTable<Key,Value>::hashFunction(const std::string& key) const
{
  unsigned int length = key.size();
  unsigned int hash = 0;

  for (int i = 0; i < length; i++)
  {
    hash += key[i] * 31;
  }

  return hash % M_size;
}


#endif  // HASH_TABLE_IMP_HPP
