#include <iostream>

#include <test.hpp>
#include <printlog.hpp>

template <class Value>
struct Node
{
  Value data;
  Node* next;
};

template <class Value>
class SingleLinkedList
{

public:
  SingleLinkedList() :
    M_size(0),
    M_head(NULL)
  {

  }

  ~SingleLinkedList()
  {
    Node<Value>* aux;
    while (M_head != NULL)
    {
      aux = M_head;
      M_head = M_head->next;
      delete aux;
    }
  }

  void addNode(const Value& newData)
  {
    Node<Value>* newNode = new Node<Value>;
    newNode->data = newData;
    newNode->next = NULL;

    addNode(newNode);
  }

  void deleteNode(Node<Value>* nodeToDelete)
  {
    if (nodeToDelete == NULL)
      return;

    nodeToDelete->data = nodeToDelete->next->data;

    Node<Value>* aux = nodeToDelete->next;
    nodeToDelete->next = nodeToDelete->next->next;

    delete aux;
  }

  unsigned int getSize() const
  {
    return M_size;
  }

  void addNode(Node<Value>* nodeToAdd)
  {
    if (nodeToAdd == NULL || nodeToAdd->next != NULL)
    {
      printlog(RED, "ERROR in addNode: invalid node");
    }
    M_size++;

    if (M_size == 1)
    {
      M_head = nodeToAdd;
      return;
    }

    Node<Value>* curr = M_head;
    while (curr->next != NULL) curr = curr->next;

    curr->next = nodeToAdd;
  }

  bool operator==(const SingleLinkedList & other)
  {
    if (M_size != other.getSize())
      return false;

    Node<Value>* curr1 = M_head, * curr2 = other.M_head;

    while (curr1 != NULL)
    {
      if (curr1->data != curr2->data)
        return false;
      curr1 = curr1->next;
      curr2 = curr2->next;
    }
    return true;
  }

  bool operator!=(const SingleLinkedList & other)
  {
    return !((*this) == other);
  }


private:
  Node<Value>* M_head;
  unsigned int M_size;

};

void subTest1(Test& test)
{
  SingleLinkedList<int> list;

  SingleLinkedList<int> expectedResult;

  for (int i = 0; i < 7; i++) expectedResult.addNode(i+1);

  list.addNode(1);
  list.addNode(2);
  list.addNode(3);

  Node<int>* nodeToDelete = new Node<int>;
  nodeToDelete->data = 3;
  nodeToDelete->next = NULL;

  list.addNode(nodeToDelete);

  list.addNode(4);
  list.addNode(5);
  list.addNode(6);

  test.assert(list != expectedResult);

  list.deleteNode(nodeToDelete);

  test.assert(list == expectedResult);

}



int main()
{
  Test test("Ex2.3");

  test.addSubTest(*subTest1);

  test.run();

  return 0;
}
