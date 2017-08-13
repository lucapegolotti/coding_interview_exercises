#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include "../linked_list/linked_list.hpp"

#define DEFAULT_HASH_SIZE 31

template <class Key, class Value>
class HashTable
{
  class KeyValuePair
  {
  public:
    KeyValuePair()
    {

    }

    KeyValuePair(Key key, Value value)
    {
      M_key = key;
      M_value = value;
    }

    bool operator==(const KeyValuePair& other) const
    {
      return M_key == other.getKey();
    }

    void operator=(const KeyValuePair& other)
    {
      M_key = other.getKey();
      M_value = other.getValue();
    }

    Key getKey() const
    {
      return M_key;
    }

    Value getValue() const
    {
      return M_value;
    }
  private:

    Key M_key;
    Value M_value;
  };

public:
  HashTable();

  ~HashTable();

  HashTable(unsigned int size);

  unsigned int getSize() const;

  bool insert(const Key& keyToInsert, const Value& valueToInsert);

  bool findKey(const Key& keyToFind, Value& correspondingValue) const;

  unsigned int hashFunction(const int& key) const;

  unsigned int hashFunction(const std::string& key) const;

private:

  unsigned int M_size;
  std::vector<LinkedList<KeyValuePair> > M_lists;


};

#include "hash_table_imp.hpp"

#endif  // HASH_TABLE_HPP
