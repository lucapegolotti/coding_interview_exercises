#include "array_list.hpp"

template <class Value>
ArrayList<Value>::ArrayList(const unsigned int& initial_size) :
  M_maxSize(initial_size),
  M_size(0)
{
  M_array = new Value[M_maxSize]();
}

template <class Value>
ArrayList<Value>::~ArrayList()
{
  delete M_array;
}

template <class Value>
unsigned int ArrayList<Value>::getSize() const
{
  return M_size;
}

template <class Value>
unsigned int ArrayList<Value>::getMaxSize() const
{
  return M_maxSize;
}

template <class Value>
Value ArrayList<Value>::operator[](const unsigned int& index) const
{
  return M_array[index];
}

template <class Value>
void ArrayList<Value>::insert(const Value& valueToInsert)
{
  if (M_size >= M_maxSize)
  {
    Value* newArray = new Value[M_maxSize*2]();
    for (int i = 0; i < M_size; i++)
    {
      newArray[i] = M_array[i];
    }
    delete M_array;
    M_array = newArray;
    M_maxSize = M_maxSize*2;
  }
  M_array[M_size] = valueToInsert;
  M_size++;
}
