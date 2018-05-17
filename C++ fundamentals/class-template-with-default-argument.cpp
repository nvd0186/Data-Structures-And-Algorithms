#include <iostream>

using namespace std;

template<class T, int abc = 10>
class A
{
  public:
    A(T arg1)//, int abc = 10)
    {
      //var = abc;
      var1 = arg1;
    }
    ~A(){}
    
    void printA()
    {
      cout << abc << endl;
      cout << var1 << endl;
    }
    
  private:
    T var;
    T var1;
};

int main() 
{
  A<char> myObj('a');
  myObj.printA();
}