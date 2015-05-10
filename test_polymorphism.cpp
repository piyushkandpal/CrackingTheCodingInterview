#include<iostream>

using namespace std;
class A
{
    int a;
    public:
    void show()
    {
        cout<<" show  of class A"<<endl;
    }
};

class B:public A
{
    public:
        void show()
        {
            cout<<" show  of class B"<<endl;
        }
};

int main()
{
    B *b=new A();
    b->show();
    A *a = new B();
    a->show();
}

   
