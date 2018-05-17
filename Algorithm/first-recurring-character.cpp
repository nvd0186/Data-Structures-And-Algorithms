#include <iostream>
#include <unordered_set>

using namespace std;

void firstRecurringChar(string abc)
{
  unordered_set<char> charSet;
  for(int a = 0; a < abc.size(); a++)
  {
    if(charSet.find(abc[a]) == charSet.end())
    {
      charSet.insert(abc[a]);
    }
    else
    {
      cout << "First recurring char : " << abc[a] << endl;
      return;
    }
  }
  cout << "No recurring char in string : " << abc << endl;
  return;
}

int main() 
{
  firstRecurringChar("abcaca");
}