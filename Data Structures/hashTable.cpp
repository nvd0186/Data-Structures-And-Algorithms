#include <iostream>
#include <string>

using namespace std;

class hashTable
{
  public:
    hashTable(){}
    ~hashTable(){}

    void Insert(string name, string lastName)
    {
      int hash = Hash(name);
      cout << hash << endl;
      table[hash] = lastName; 
    }
    
    int Hash(string key)
    {
      int hash = (key.size()%tableSize);
      
      return (key.size()%tableSize);
    }
    
    string find(string key)
    {
      string result = "";
      result = table[key.size()%tableSize];
      return result;
    }
    
  private:
    int tableSize = 100;
    string table[100] ;  
};

int main()
{
  hashTable newTable;
  newTable.Insert("FirstName", "LastName");
  newTable.Insert("Jay", "Nagesh");
  newTable.Insert("123", "Vijay");

  return 0;
}