#include <iostream>
#include <string>
#include <climits>

using namespace std;

int main()
{
  string inputStr = "";
  int charFound = 0;
  cout << "Enter a string" << endl;
  cin >> inputStr;
  
  for(int i=0; i<inputStr.size(); i++)
  {
    int val = inputStr[i] - 'a';
    if((charFound & (1<<val)) > 0)
    {
      cout << "Not Unique";
      return 0;
    }
    charFound |= (1<<val);
  }
  cout << "Unique" << endl;
  return 0;
}