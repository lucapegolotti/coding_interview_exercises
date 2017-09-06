#include "stack.hpp"

template <class Value>
Stack<Value>::Stack() :
  M_size(0),
  M_head(NULL)
{

}

template <class Value>
Stack<Value>::~Stack()
{
  Node* aux;

  while (M_head != NULL)
  {
    aux = M_head->prev;
    delete M_head;
    M_head = aux;
  }

}

template <class Value>
unsigned int Stack<Value>::getSize() const
{
  return M_size;
}

template <class Value>
void Stack<Value>::push(const Value& newValue)
{
  Node* newNode = new Node;

  newNode->data = newValue;

  newNode->prev = M_head;

  M_head = newNode;
  M_size++;
}

template <class Value>
bool Stack<Value>::pop(Node& poppedValue)
{
  if (M_size == 0)
  {
    return false;
  }
  poppedValue = *M_head;
  M_head = M_head->prev;
  M_size--;

  return true;
}

template <class Value>
void Stack<Value>::print() const
{
  Node* curr = M_head;

  while (curr != NULL)
  {
    printlog(WHITE, curr->data);
    curr = curr->prev;
    if (curr != NULL)
      printlog(WHITE, "->");
  }
  printlog(WHITE, "\n");

}
