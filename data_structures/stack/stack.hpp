#ifndef STACK_HPP
#define STACK_HPP

#include <string>
#include <printlog.hpp>

template <class Value>
class Stack
{
public:
  struct Node
  {
    Value data;
    Node* prev;
  };


  Stack();

  ~Stack();

  unsigned int getSize() const;

  void push(const Value& newValue);

  bool pop(Node& poppedValue);

  void print() const;

private:

  unsigned int M_size;
  Node* M_head;

};

#include "stack_imp.hpp"

#endif  // STACK_HPP
