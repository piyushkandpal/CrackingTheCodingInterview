#include<iostream>
#include<typeinfo>
using namespace std;

class Base { public: virtual ~Base(){};};
class Derived1 : public Base { };
class Derived2 : public Base { };
void foo1(Base* b)
{
    if (typeid(*b) == typeid(Derived1))
    {
        Derived1* d = static_cast<Derived1*>(b);
        cout<<"static cast DID work"<<endl;
        // Use d ...
    }
    else
    {
        cout<<"static cast didnt work"<<endl;
    }
}
void foo2(Base* b)
{
    Derived1* d = dynamic_cast<Derived1*>(b);
    if (d != 0)
    {
        // Use d ...
        cout<<"dynamic cast DID work"<<endl;
    }
    else
        cout<<"dynamic cast DID work"<<endl;
        //...
}

int main()
{
    Derived1 d1;
    Derived2 d2;
    foo1(&d1);
    foo2(&d2);
}


