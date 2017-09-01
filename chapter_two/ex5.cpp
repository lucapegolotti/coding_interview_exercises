#include <iostream>

#include <test.hpp>
#include <printlog.hpp>
#include <map>

template <class Value>
struct Node
{
  Value data;
  Node* next;
};

template <class Value>
class DoubleLinkedList
{

public:
  DoubleLinkedList() :
    M_size(0),
    M_head(NULL)
  {

  }

  ~DoubleLinkedList()
  {
    std::map<Node<Value>*, unsigned int> map;
    while (M_size > 0)
    {
      map.insert(std::pair<Node<Value>*, unsigned int>(M_head, M_size));
      M_head=M_head->next;
      M_size--;
    }

    for (auto it = map.begin();
         it != map.end(); it++)
     {
        delete it->first;
     }
  }

  void deleteRecursively(Node<Value>* curr, unsigned int size)
  {
    if (curr == NULL && size > 0)
    {
      return;
    }

    deleteRecursively(curr->next, size--);
    delete curr;
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
    if (nodeToAdd == NULL)
    {
      printlog(RED, "ERROR in addNode: invalid node");
    }
    M_size++;

    if (nodeToAdd->next != NULL)
    {
      printlog(YELLOW, "ATTENTION: possibly creating circular list\n");
    }

    if (M_size == 1)
    {
      M_head = nodeToAdd;
      return;
    }

    Node<Value>* curr = M_head;
    while (curr->next != NULL) curr = curr->next;

    curr->next = nodeToAdd;
  }

  bool operator==(const DoubleLinkedList & other)
  {
    if (M_size != other.getSize())
      return false;

    Node<Value>* curr1 = M_head, * curr2 = other.M_head;
    unsigned int size = M_size;
    while (size > 0)
    {
      if (curr1->data != curr2->data)
        return false;
      curr1 = curr1->next;
      curr2 = curr2->next;
      size--;
    }
    return true;
  }

  bool operator!=(const DoubleLinkedList & other)
  {
    return !((*this) == other);
  }

  Node<Value>* findBeginningLoop()
  {

    Node<Value>* aux1 = M_head;
    Node<Value>* aux2 = M_head;

    aux1 = aux1->next->next;
    aux2 = aux2->next;

    while (aux1 != aux2)
    {
      aux1 = aux1->next->next;
      aux2 = aux2->next;
    }

    aux2 = M_head;

    while (aux1 != aux2)
    {
      aux1 = aux1->next;
      aux2 = aux2->next;
    }

    return aux1;
  }


private:
  Node<Value>* M_head;
  unsigned int M_size;

};

void subTest1(Test& test)
{
  DoubleLinkedList<char> list;

  Node<char>* nodeToAdd = new Node<char>;
  nodeToAdd->data = 'c';
  nodeToAdd->next = NULL;

  list.addNode('a');
  list.addNode('b');
  list.addNode(nodeToAdd);
  list.addNode('d');
  list.addNode('e');
  list.addNode(nodeToAdd);

  test.assert(nodeToAdd == list.findBeginningLoop());

}

void subTest2(Test& test)
{
  DoubleLinkedList<int> list;

  Node<int>* nodeToAdd = new Node<int>;
  nodeToAdd->data = 5;
  nodeToAdd->next = NULL;

  list.addNode(1);
  list.addNode(2);
  list.addNode(3);
  list.addNode(4);
  list.addNode(nodeToAdd);
  list.addNode(6);
  list.addNode(7);
  list.addNode(8);
  list.addNode(nodeToAdd);

  test.assert(nodeToAdd == list.findBeginningLoop());

}



int main()
{
  Test test("Ex2.5");

  test.addSubTest(*subTest1);
  test.addSubTest(*subTest2);

  test.run();

  return 0;
}
