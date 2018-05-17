#include <iostream>

using namespace std;

class LinkedListNode
{
  public:
    int data;
    LinkedListNode* next = nullptr;
    LinkedListNode* prev = nullptr;
    
    LinkedListNode(int newData, 
                   LinkedListNode* newPrev = nullptr, 
                   LinkedListNode* newNext = nullptr 
                  )
    {
      data = newData;
      prev = newPrev;
      next = newNext;
    }
};

class LinkedList
{
  public:
    LinkedListNode* head = nullptr;
    void addToHead(int newData)
    {
      head = new LinkedListNode(newData, nullptr, head);
    }
    
    void traverse()
    {
      LinkedListNode* temp = head;
      while(temp)
      {
        cout << temp->data << endl;
        temp= temp->next;
      }
    }
};

int main() 
{
  LinkedList newList;
  
  newList.addToHead(1);
  newList.addToHead(100);
  newList.addToHead(-2);
  
  newList.traverse();
}




