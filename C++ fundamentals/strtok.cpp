#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main() 
{
  std::string s = "scott>=tiger";
  char* pch;
  pch = strtok((char*)s.c_str(), ">=");
  cout << pch << endl;
  pch = strtok(NULL, ">=");
  cout << pch << endl;
}