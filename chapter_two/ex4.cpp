#include <iostream>

#include <test.hpp>
#include <printlog.hpp>

struct Node
{
  int data;
  Node* next;
};

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
    Node* aux;
    while (M_head != NULL)
    {
      aux = M_head;
      M_head = M_head->next;
      delete aux;
    }
  }

  void addNode(const int& newData)
  {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = NULL;

    addNode(newNode);
  }

  void deleteNode(Node* nodeToDelete)
  {
    if (nodeToDelete == NULL)
      return;

    nodeToDelete->data = nodeToDelete->next->data;

    Node* aux = nodeToDelete->next;
    nodeToDelete->next = nodeToDelete->next->next;

    delete aux;
  }

  unsigned int getSize() const
  {
    return M_size;
  }

  void addNode(Node* nodeToAdd)
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

    Node* curr = M_head;
    while (curr->next != NULL) curr = curr->next;

    curr->next = nodeToAdd;
  }

  bool operator==(const SingleLinkedList & other)
  {
    if (M_head == NULL && other.M_head == NULL)
      return true;

    if (M_size != other.getSize())
      return false;

    Node* curr1 = M_head, * curr2 = other.M_head;

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

  SingleLinkedList operator+(const SingleLinkedList& other)
  {
    SingleLinkedList result;

    if (M_size != other.M_size)
    {
      printlog(RED, "ERROR in operator+: cannot operate sum on lists with different lenghts\n");
      return result;
    }

    Node* curr1 = M_head;
    Node* curr2 = other.M_head;

    int rem = 0;

    while (curr1 != NULL)
    {
      int sum = curr1->data + curr2->data + rem;
      result.addNode(sum % 10);
      rem = sum / 10;

      curr1 = curr1->next;
      curr2 = curr2->next;
    }

    if (rem != 0)
      result.addNode(rem);

    return result;
  }


private:
  Node* M_head;
  unsigned int M_size;

};

void subTest1(Test& test)
{
  SingleLinkedList list, other;
  SingleLinkedList expectedResult;

  list.addNode(3);
  list.addNode(1);
  list.addNode(5);

  other.addNode(5);
  other.addNode(9);
  other.addNode(2);

  expectedResult.addNode(8);
  expectedResult.addNode(0);
  expectedResult.addNode(8);

  test.assert(list + other == expectedResult);

}

// test if result is expanded
void subTest2(Test& test)
{
  SingleLinkedList list, other;
  SingleLinkedList expectedResult;

  list.addNode(9);
  list.addNode(9);
  list.addNode(9);

  other.addNode(1);
  other.addNode(0);
  other.addNode(0);

  expectedResult.addNode(0);
  expectedResult.addNode(0);
  expectedResult.addNode(0);
  expectedResult.addNode(1);

  test.assert(list + other == expectedResult);
}

// test if size is different
void subTest3(Test& test)
{
  SingleLinkedList list, other;
  SingleLinkedList expectedResult;

  list.addNode(9);
  list.addNode(9);
  list.addNode(9);

  other.addNode(1);
  other.addNode(0);

  test.assert(list + other == expectedResult);
}

int main()
{
  Test test("Ex2.4");

  test.addSubTest(*subTest1);
  test.addSubTest(*subTest2);
  test.addSubTest(*subTest3);

  test.run();

  return 0;
}
