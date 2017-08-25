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

  unsigned int getSize()
  {
    return M_size;
  }

  Value findNthToLast(const unsigned int& n) const
  {
    if (n <= 0)
    {
      printlog(RED, "ERROR in findNthToLast: n must be strictly positive");
      exit(1);
    }
    Node* curr = M_head;
    Node* aux = M_head;

    unsigned int N = n-1;

    while (N > 0)
    {
      if (aux != NULL)
      {
        aux = aux->next;
      }
      else
      {
        printlog(RED, "ERRROR in findNthToLast: n is too large");
      }
      N--;
    }

    while (aux->next != NULL)
    {
      aux = aux->next;
      curr = curr->next;
    }

    return curr->data;

  }


private:
  Node* M_head;
  unsigned int M_size;

};

void subTest1(Test& test)
{
  DoubleLinkedList<int> list;

  list.addNode(1);
  list.addNode(3);
  list.addNode(5);
  list.addNode(7);

  test.assert(list.findNthToLast(1) == 7);
  test.assert(list.findNthToLast(2) == 5);

}

int main()
{
  Test test("Ex2.2");

  test.addSubTest(*subTest1);

  test.run();

  return 0;
}
