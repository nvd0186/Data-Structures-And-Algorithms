#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int main() 
{
  queue<int> newQueue;
  newQueue.push(1);
  newQueue.push(2);
  newQueue.push(3);
  newQueue.push(4);
  newQueue.push(5);
  
  newQueue.pop();
  
  cout << newQueue.front() << endl;
  
  stack<int> newStack;
  newStack.push(1);
  newStack.push(2);
  newStack.push(3);
  newStack.push(4);
  newStack.push(5);
  
  newStack.pop();
  
  cout << newStack.top() << endl;
  
  deque<int> newDeque;
  newDeque.push_back(1);
  newDeque.push_back(2);
  newDeque.push_back(3);
  newDeque.push_front(11);
  newDeque.push_front(1234);
  
  newDeque.pop_front();
  
  cout << newDeque.front() << endl;
}