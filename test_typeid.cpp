#include<iostream>
#include<typeinfo>
using namespace std;
class A
{
    public:
        int A;
        virtual int getA(){return A;}
};
class B:public A
{
    public:
        int getA()
        { return 2;
        }
};
int main()
{
    A a;
    B b;
    cout<<typeid(a).name()<<endl;
    cout<<typeid(b).name()<<endl;
}
