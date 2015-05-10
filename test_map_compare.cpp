#include<iostream>
#include<map>
using namespace std;
class A
{
    int *a;
    public:
    A(int x)
    { 
        a=new int(x);
    }
    ~A()
    {
        cout<<"deleting a"<<endl;
        delete a;
    }
    int& get()const
    {
        return *a;
    }
};

int main()
{
    A *a=new A(1);
    cout<<a->get()<<endl;
    delete a;
    map<int,A> m;
    A a=
    m[1]=A(1);
    m[2]=A(2);
    m[5]=A(5);
    m[4]=A(4);
    m[3]=A(3);
    map<int,A>::iterator it=m.begin();
    while(it!=m.end())
    {
        cout<<it->first<<"="<<it->second<<end;
    }
    return 0;
}

