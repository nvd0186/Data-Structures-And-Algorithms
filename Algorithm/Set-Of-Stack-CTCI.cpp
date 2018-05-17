#include <iostream>
#include <list>
#include <stack>

using namespace std;

class setOfStacks
{
public:
  setOfStacks(){}
  ~setOfStacks(){}
  
  void push(int data)
  {
    if(   (index < 0)
       || (index >= maxSize)
      )
    {
       stack<int> newStack;
       newList.push_back(newStack);
       index = 0;
       cout << "new stack" << endl;
    }
    newList.back().push(data);
    index++;
    cout << "index : " <<  index << endl;
  }
  
  void pop()
  {
    if(index == 0)
    {
      newList.pop_back();
      index = maxSize;
    }
    if(newList.empty())
    {
      cout << "No element in the stack" << endl;
      return;
    }
    cout << "popped data: " << newList.back().top() << endl;
    newList.back().pop();
    index--;
  }
  
  void stackSize()
  {
    cout << "List Size : " << newList.size() << endl;
    cout << "Stack Size: " << newList.back().size() << endl;
  }
  
private:
  std::list<stack<int>> newList;
  int nStacks = 0;
  int index = -1;
  int maxSize = 5;
  
};

int main() 
{
  setOfStacks newSet;
  newSet.push(10);
  newSet.push(100);
  newSet.push(220);
  newSet.push(440);
  newSet.push(20);
  newSet.push(10000);
  newSet.push(22);
  
  newSet.stackSize();

  newSet.pop();
  newSet.pop();
  newSet.pop();
  newSet.pop();
  newSet.pop();
  newSet.pop();
  newSet.pop();
  //newSet.pop();
  
  
  newSet.stackSize();
  
}