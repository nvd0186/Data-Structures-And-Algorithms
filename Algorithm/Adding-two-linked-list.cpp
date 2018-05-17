#include <iostream>
#include <unordered_set>

using namespace std;

class linkedListNode{
  public:
    linkedListNode(int newVal)
    {
      data = newVal;
    }
    
    int data;
    linkedListNode* next = nullptr;
};

class linkedList{
  public:
    linkedList(){}
    ~linkedList(){}
    
    void addToHead(int val)
    {
      if(head == nullptr)
      {
        head = new linkedListNode(val);
        head->next = nullptr;
        tail = head;
        return;
      }
      linkedListNode* temp = new linkedListNode(val);
      temp->next = head;
      head = temp;
    }
    
    void traverse()
    {
      if(head == nullptr)
      {
        cout << "Empty linkedlist" << endl;
      }
      else
      {
        linkedListNode* temp = head;
        while(temp != nullptr)
        {
          cout << "val : " << temp->data << endl;
          temp = temp->next;
        }
      }
    }
    
    linkedListNode* addLinkedList(linkedListNode* node1,
                                  linkedListNode* node2
                                 )
    {
      if(   node1 == nullptr
         && node2 == nullptr
        )
      {
        return nullptr;    
      }
      linkedListNode* p1 = node1;
      linkedListNode* p2 = node2;
      int carry = 0;
      linkedListNode* newNode = nullptr;
      linkedListNode* head = nullptr;
      while(   (p1 != nullptr) 
            && (p2 != nullptr)
           )
      {
        int sum = (p1->data + p2->data) + carry;
        //int sum = (p1->data * p2->data) + carry;
        carry = sum/10;
        if(!head)
        {
          head = new linkedListNode (sum % 10);
          head->next = nullptr;
        }
        else
        {
          linkedListNode* temp = new linkedListNode(sum % 10);
          temp->next = head;
          head = temp;
        }
        p1 = p1->next;
        p2 = p2->next;
      }
      if(carry)
      {
        linkedListNode* temp = new linkedListNode(carry);
        temp->next = head;
        head = temp;
      }
      
      return head;
    }
    
    linkedListNode* head = nullptr;
    linkedListNode* tail = nullptr;
};

int main() 
{
  linkedList newList;
  newList.addToHead(9);
  newList.addToHead(9);
  newList.addToHead(9);
  
  linkedList newList1;
  newList1.addToHead(9);
  newList1.addToHead(9);
  newList1.addToHead(9);
  
  //newList.traverse();
  linkedListNode* abc = newList.addLinkedList(newList.head, newList1.head);
  while(abc)
  {
    cout << abc->data <<endl;
    abc = abc->next;
  }
}