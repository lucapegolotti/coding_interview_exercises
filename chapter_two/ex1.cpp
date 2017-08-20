#include <iostream>

#include <test.hpp>
#include <printlog.hpp>

template <class Value>
class DoubleLinkedList
{
  struct Node
  {
    Value data;
    Node* next;
    Node* prev;
  };
public:
  DoubleLinkedList() :
    M_size(0),
    M_head(NULL)
  {

  }

  ~DoubleLinkedList()
  {
    Node* aux;
    while (M_head != NULL)
    {
      aux = M_head;
      M_head = M_head->next;
      delete aux;
    }
  }

  void addNode(const Value& newData)
  {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = NULL;
    newNode->prev = NULL;

    M_size++;

    if (M_size == 1)
    {
      M_head = newNode;
      return;
    }

    Node* curr = M_head;
    while (curr->next != NULL) curr = curr->next;

    curr->next = newNode;
    newNode->prev = curr;
  }

  void deleteDuplicates()
  {
    Node* curr = M_head;
    Node* aux;

    while (curr != NULL)
    {
      aux = curr->prev;
      while (aux != NULL)
      {
        // delete node and break loop
        if (aux->data == curr->data)
        {
          if (aux->prev != NULL)
            aux->prev->next = aux->next;
          else
            M_head = aux->next;
          aux->next->prev = aux->prev;
          delete aux;
          break;
        }
        aux = aux->prev;
      }
      curr = curr->next;
    }
  }

  unsigned int getSize()
  {
    return M_size;
  }

  bool hasDuplicates()
  {
    Node* curr, *aux;

    curr = M_head;
    while (curr != NULL)
    {
      aux = curr->next;
      while (aux != NULL)
      {
        if (curr->data == aux->data)
        {
          return true;
        }
        aux = aux->next;
      }
      curr = curr->next;
    }
    return false;
  }


private:
  Node* M_head;
  unsigned int M_size;

};

void subTest1(Test& test)
{
  DoubleLinkedList<int> list;

  list.addNode(3);
  list.addNode(6);

  test.assert(!list.hasDuplicates());

  list.addNode(3);
  test.assert(list.hasDuplicates());

  list.addNode(10);
  list.addNode(5);
  list.addNode(3);
  list.addNode(-3);
  list.addNode(1);
  list.addNode(6);
  list.addNode(10);

  list.deleteDuplicates();

  test.assert(!list.hasDuplicates());
}

void subTest2(Test& test)
{
  DoubleLinkedList<char> list;

  list.addNode('b');
  list.addNode('b');
  list.addNode('b');
  list.addNode('b');

  list.deleteDuplicates();

  test.assert(!list.hasDuplicates());
}

int main()
{
  Test test("Ex2.1");

  test.addSubTest(*subTest1);
  test.addSubTest(*subTest2);

  test.run();

  return 0;
}
