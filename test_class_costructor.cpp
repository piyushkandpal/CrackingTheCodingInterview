#include<iostream>
#include<map>
using namespace std;

class A
{
    int a;
    public:
        A(int x)
        {
            this->a = x;
        }
        int get() const
        {
            return a;
        }
        A(const A &obj)
        {
            //obj.a is allowed as it is inside class A
            this->a=obj.a;
        }
};

int main()
{
   map<int,A> m;
   //this works
   m.insert(make_pair(1,A(1)));
   //What happens when you call
   //   myMap[i] = myObj;
   //is that, if there is no element with key i, one is inserted with a value initialized 
   //(which for a user defined type means default constructed) mapped type. 
   //You then assign to it the value on the RHS of the assignment. The first part requires that the type be default constructable.
   //Hence below will result in a compiler error.Better use an insert method.
   //m[1] = a;
   A c= b;
   cout<<a.get()<<endl;
   cout<<b.get()<<endl;
   cout<<c.get()<<endl;
   return 0;
}
