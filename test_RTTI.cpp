#include<iostream>
 
using namespace std;
 
class B { virtual void fun(){};};
class D: public B {};
 
int main()
{
      B *b = new D;
      D *d = dynamic_cast<D*>(b);
      if(d != NULL)
            cout<<"works";
      else
            cout<<"cannot cast B* to D*";
      return 0;
}

