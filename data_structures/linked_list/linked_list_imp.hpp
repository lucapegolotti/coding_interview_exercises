#include "linked_list.hpp"

template <class Value>
LinkedList<Value>::LinkedList() :
  M_size(0)
{

}

template <class Value>
unsigned int LinkedList<Value>::getSize() const
{
  return M_size;
}
