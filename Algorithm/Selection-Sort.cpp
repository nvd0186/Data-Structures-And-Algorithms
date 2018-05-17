#include <iostream>
#include <list>

using namespace std;

int findMin(int arr[], int nSize)
{
  int minIndex = 0;
  for(int i=0; i<nSize; i++)
  {
    if(arr[i] < arr[minIndex])
    {
      minIndex = i;
    }
  }
  return minIndex;
}

void selectionSort(int arr[], int nSize, int index = 0)
{
  if(nSize == 0)
  {
    return;
  }
  int min = findMin(arr, nSize);
  swap(arr[index], arr[min]);
  selectionSort(arr+1, nSize-1, index++);
}

int main ()
{
  int arr[] = {11, 123, 0, 4, 10, 444, 3};
  int nSize = sizeof(arr)/sizeof(arr[0]);
  selectionSort(arr, nSize);
  
  for(int i=0; i<nSize; i++)
  {
    cout << arr[i] << endl;
  }
}