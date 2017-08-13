#include "linked_list.hpp"

template <class Value>
LinkedList<Value>::LinkedList() :
  M_size(0),
  M_head(nullptr),
  M_tail(nullptr)
{

}

template <class Value>
unsigned int LinkedList<Value>::getSize() const
{
  return M_size;
}

template <class Value>
void LinkedList<Value>::add(Value newValue)
{
  Node* newNode = new Node();
  newNode->data = newValue;
  newNode->next = nullptr;

  if (M_size == 0)
  {
    M_head = newNode;
    M_tail = newNode;
  }
  else
  {
    M_tail->next = newNode;
    M_tail = newNode;
  }

  M_size++;
}
