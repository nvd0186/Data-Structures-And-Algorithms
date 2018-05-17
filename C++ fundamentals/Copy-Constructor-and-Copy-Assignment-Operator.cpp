#include <iostream>

using namespace std;

class A 
{
  public: 
    A(int a){variable = a;}
    ~A(){}
    A(const A&)
    {variable = 10;}
    
    void printVar()
    { cout << variable << endl; }
    
    A& operator=(const A&)
     {
       this->variable = 12;
       return *this;
     }
    
    private:
      int variable;
};


int main() 
{
   A abc(5);
   abc.printVar();
   
   A xyz(abc);
   xyz.printVar();
   
   A ax(11);
   ax = abc;
   ax.printVar();
}