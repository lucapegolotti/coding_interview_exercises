#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <string>
#include <printlog.hpp>

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

  ~LinkedList();

  unsigned int getSize() const;

  void insert(const Value& newValue);

  bool contain(const Value& valueToFind) const;

  bool contain(Value& valueToFind) const;

  void print() const;

private:

  unsigned int M_size;
  Node* M_head;
  Node* M_tail;

};

#include "linked_list_imp.hpp"

#endif  // LINKED_LIST_HPP
