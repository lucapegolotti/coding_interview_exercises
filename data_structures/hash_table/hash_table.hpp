#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#define DEFAULT_HASH_SIZE 31

template <class Key, class Value>
class HashTable
{
public:
  HashTable();

  HashTable(unsigned int size);

  unsigned int getSize() const;

private:

  unsigned int M_size;

};

#include "hash_table_imp.hpp"

#endif  // HASH_TABLE_HPP
