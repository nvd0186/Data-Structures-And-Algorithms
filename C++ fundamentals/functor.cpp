#include <iostream>

using namespace std;

void printArr(void (*f)(int a), int* arr, int s)
{
  for(int i=0; i<s; i++)
  {
    f(arr[i]);
  }
}

void f(int abc)
{
  cout << abc << endl;
}

int main() 
{
   int a[5] = {4, 1, 2, 3, 10};
   printArr(f, a, 5);
}