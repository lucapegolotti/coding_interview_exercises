#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#define DEFAULT_ARRAY_LIST_SIZE 100

template <class Value>
class ArrayList
{
public:
  ArrayList(const unsigned int& initial_size = DEFAULT_ARRAY_LIST_SIZE);

  ~ArrayList();

  unsigned int getSize() const;

  unsigned int getMaxSize() const;

  Value operator[](const unsigned int& index) const;

  void insert(const Value& valueToInsert);

private:

  unsigned int M_maxSize;
  unsigned int M_size;
  Value* M_array;
};

#include "array_list_imp.hpp"

#endif  // ARRAY_LIST_HPP
