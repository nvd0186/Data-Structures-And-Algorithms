#include <iostream>
#include <array>
#include <algorithm>
#include <string.h>

using namespace std;

void removeOdd(int* arr, int size)
{
  for(int i=0; i<size; i++)
  {
    if((*(arr+i) % 2) != 0)
    {
      *(arr+i) = 0;
    }
  }
}

int addArr(int* arr, int size)
{
  int result = 0;
  for(int i=0; i<size; i++)
    result += *(arr+i);
  return result;
}

int main() 
{
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  
  cout << addArr(a, 10) << "\n";
  
  removeOdd(a, 10);
  for(int i=0; i<10; i++)
    cout << a[i];
}