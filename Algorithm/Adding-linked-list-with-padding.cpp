#include <iostream>

using namespace std;

class Node
{
  public:
    Node(int val)
    {
      data = val;
    }
    ~Node(){}
    
    int data;
    Node* next = nullptr;
};

class List
{
  public:
    List(){}
    ~List(){}
    
    void addToHead(int data)
    {
      if(!head)
      {
        head = new Node(data);
        return;
      }
      Node* temp = new Node(data);
      temp->next = head;
      head = temp;
      return;
    }
    
    void traverse()
    {
      if(!head)
      {
        cout << "Empty Linked List" << endl;
        return;
      }
      Node* temp = head;
      while(temp)
      {
        cout << temp->data << endl;
        temp = temp->next;
      }
      return;
    }
    
    int lengthOfList(Node* head)
    {
      int length = 0;
      if(!head)
      {
        return length;
      }
      Node* temp = head;
      while(temp)
      {
        length++;
        temp = temp->next;
      }
      return length;
    }
    
    void padding(int length)
    {
      for(int i=0; i<length; i++)
      {
        this->addToHead(0);
      }
    }
    
    Node* head = nullptr;
    Node* tail = nullptr;
};

Node* addToList(Node* node1, Node* node2)
{
  Node* head = nullptr;
  Node* tail = nullptr;
  if(node1 && node2)
  {
    Node* p1 = node1;
    Node* p2 = node2;
    int carry = 0;
    while(p1 && p2)
    {
      int sum = p1->data + p2->data + carry;
      carry = (sum >= 10) ? 1 : 0;
      if(!head)
      {
        head = new Node(sum % 10);
        tail = head; 
      }
      else
      {
        tail->next = new Node(sum % 10);
        tail = tail->next;
      }
      p1 = p1->next;
      p2 = p2->next;
    }
    if(carry)
    {
      tail->next = new Node(carry);
      tail = tail->next;
    }
  }
  return head;
}

int main() 
{
  List List1;
  List1.addToHead(5);
  List1.addToHead(11);
  List1.addToHead(10);
  int length1 = List1.lengthOfList(List1.head);
  
  List List2;
  List2.addToHead(10);
  List2.addToHead(1);
  int length2 = List2.lengthOfList(List2.head);
  
  if(length2 < length1)
    List2.padding(length1-length2);
  else if(length1 < length2)
    List1.padding(length2-length1);
  
  Node* node1 = addToList(List1.head, List2.head);
  while(node1)
  {
    cout << "data: " << node1->data << endl;
    node1 = node1->next;
  }
  
}