#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP


template <class Value>
class LinkedList
{
  struct Node
  {
    Value data;
    Node* next;
  };

public:
  LinkedList();

  unsigned int getSize() const;

  void add(Value newValue);

private:

  unsigned int M_size;
  Node* M_head;
  Node* M_tail;

};

#include "linked_list_imp.hpp"

#endif  // LINKED_LIST_HPP
