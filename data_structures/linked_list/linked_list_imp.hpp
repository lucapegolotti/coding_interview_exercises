#include "linked_list.hpp"

template <class Value>
LinkedList<Value>::LinkedList() :
  M_size(0),
  M_head(NULL),
  M_tail(NULL)
{

}

template <class Value>
LinkedList<Value>::~LinkedList()
{
  Node* curr = M_head, *aux;
  while (curr != NULL)
  {
    aux = curr->next;
    delete curr;
    curr = aux;
  }
}

template <class Value>
unsigned int LinkedList<Value>::getSize() const
{
  return M_size;
}

template <class Value>
void LinkedList<Value>::insert(const Value& newValue)
{
  Node* newNode = new Node();
  newNode->data = newValue;
  newNode->next = NULL;

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

template <class Value>
bool LinkedList<Value>::contain(const Value& valueToFind) const
{
  Node* curr = M_head;
  while (curr != NULL)
  {
    if (curr->data == valueToFind)
    {
      return true;
    }
    curr = curr->next;
  }
  return false;
}

template <class Value>
bool LinkedList<Value>::contain(Value& valueToFind) const
{
  Node* curr = M_head;
  while (curr != NULL)
  {
    if (curr->data == valueToFind)
    {
      valueToFind = curr->data;
      return true;
    }
    curr = curr->next;
  }
  return false;
}

template <class Value>
void LinkedList<Value>::print() const
{
  Node* temp = M_head;
  std::string printedList = "";
  for (int i = 0; i < M_size; i++)
  {
    printlog(WHITE,temp->data);
    printlog(WHITE,"->");
    temp = temp->next;
  }
  printlog(WHITE,"NULL\n");

}
