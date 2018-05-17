#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

int main() 
{
  int arr[] = {11, 123, 0, 4, 10, 444, 3};
  int nSize = sizeof(arr)/sizeof(arr[0]);
  insertionSort(arr, nSize);
  for(int i = 0; i<nSize; i++)
  {
    cout << arr[i] << endl;
  }
}