#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

template <class Value>
class LinkedList
{
public:
  LinkedList();

  unsigned int getSize() const;

private:

  unsigned int M_size;

};

#include "linked_list_imp.hpp"

#endif  // LINKED_LIST_HPP
