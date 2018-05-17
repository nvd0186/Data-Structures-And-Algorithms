#include <iostream>

using namespace std;

class LinkedListNode
{
  public:
    int data;
    LinkedListNode* next = nullptr;
    
    LinkedListNode(int newData, LinkedListNode* newNext = nullptr)
    {
      data = newData;
      next = newNext;
    }
};

class LinkedList
{
  public:
    LinkedListNode* head = nullptr;
    LinkedListNode* tail = nullptr;
    
    void add(int data)
    {
      if(tail)
      {
        tail->next = new LinkedListNode(data, head);
      }
      else
      {
        tail = new LinkedListNode(data);
        head = tail;
      }
    }
    
    void traverse()
    {
      LinkedListNode* temp = head;
      while(temp->data)
      {
        cout << temp->data << endl;
        temp = temp->next;
      }
    }
};

int main() 
{
  LinkedList newList;
  newList.add(5);
  newList.add(10);
  //newList.traverse();
}