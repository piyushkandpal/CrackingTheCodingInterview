#include<iostream>
using namespace std;
class A
{
    public:
        enum Type{D,B,C};
        static Type t;
};
A::Type A::t = A::C;

enum E{red=101,black=107,blue};
int main()
{
    E type;
    type = blue;
    cout<<type<<endl;
    cout<<A::t<<endl;
}
