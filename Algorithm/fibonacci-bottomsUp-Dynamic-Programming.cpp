#include <iostream>
#include <cstring>

int fib(int n)
{
  if(   (n == 1)  
     || (n == 2)
    )
  {
    return 1;
  }
  else
  {
    int arr[n+1] = {'\0'};
    memset(arr, '\0', n+1);
    arr[1] = 1;
    arr[2] = 1;
    for(int i=3; i<n+1; i++)
    {
      arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
  }
}

int main() {
  int result = fib(35);
  std::cout << result;
}