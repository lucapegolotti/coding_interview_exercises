#ifndef HASH_TABLE_IMP_HPP
#define HASH_TABLE_IMP_HPP

#include "hash_table.hpp"

template <class Key, class Value>
HashTable<Key,Value>::HashTable() :
  M_size(DEFAULT_HASH_SIZE)
{

}

template <class Key, class Value>
HashTable<Key,Value>::HashTable(unsigned int size)
{
  M_size = size;
}

template <class Key, class Value>
unsigned int HashTable<Key,Value>::getSize() const
{
  return M_size;
}

#endif  // HASH_TABLE_IMP_HPP
