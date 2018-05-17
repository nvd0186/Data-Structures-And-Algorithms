#include <iostream>
#include <list>
#include <limits>

using namespace std;

int HeapSize = 7;

class MinHeap
{
  public:
  MinHeap()
  {
    arr = new int[HeapSize];
  }
  
  ~MinHeap(){}
  
  void insert(int data)
  {
    if(heapIndex >= HeapSize)
    {
      cout << "Exceeded heapsize" << endl;
      return;
    }
    if(heapIndex == 0)
    {
      arr[heapIndex] = data;
      heapIndex++;
      return;
    }
    int i = heapIndex;
    arr[i] = data;
    while(   (arr[i] <= arr[getParent(i)])
          && (i != 0)
         )
    {
      swap(arr[i], arr[getParent(i)]);
      i = getParent(i);
    }
    heapIndex++;
  }
  
  int extractMin()
  {
    int root = arr[0];
    arr[0] = arr[HeapSize-1];
    HeapSize--;
    MinHeapify(0);
    return root;
  }
  
  void decreaseKey(int key, int value)
  {
    arr[key] = value;
    while(   (key != 0)
          && (arr[key] <= arr[getParent(key)])
         )
    {
      swap(arr[key], arr[getParent(key)]);
      key = getParent(key);
    }
  }
  
  void deleteKey(int key)
  {
    decreaseKey(key, numeric_limits<int>::min());
    extractMin();
  }
  
  void MinHeapify(int key)
  {
    int l = left(key);
    int r = right(key);
    
    int smallest = key;

    if(l < HeapSize && arr[l] < arr[key]) smallest = l;
    if(r < HeapSize && arr[r] < arr[key]) smallest = r;
    
    if(smallest != key)
    {
      swap(arr[key], arr[smallest]);
      MinHeapify(smallest);
    }
  }
  
  int left(int key)
  {
    return ((2*key)+1);
  }
  
  int right(int key)
  {
    return ((2*key)+2);
  }
  
  int getParent(int index)
  {
    return ((index-1)/2);
  }
  
  void Print()
  {
    for(int i=0; i<HeapSize; i++)
    {
      cout << arr[i] << endl;
    }
  }
  
  int* arr = nullptr;
  int heapIndex = 0;
};

int main()
{
  MinHeap a;
  a.insert(2);
  a.insert(1);
  a.insert(4);
  a.insert(3);
  a.insert(5);
  a.insert(7);
  a.insert(0);
  
  a.Print();
   cout << "--------" << endl;
  // cout << a.extractMin() << endl;
  // cout << "--------" << endl;
  // a.Print();
  a.decreaseKey(5, -1);
  a.Print();
  
  cout << "--------" << endl;
  a.deleteKey(5);
  a.Print();
}