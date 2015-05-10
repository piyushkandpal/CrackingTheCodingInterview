#include<iostream>
using namespace std;
template<typename T>
class X
{
    T x;
    public:
        void printY(){ cout<< "testing if a class fn can access another calss fn without this pointer";}
        T get(){ return x;}
        void set(T& val){x = val; printY();}
};
int main()
{
    X<int> obj;
    int y = 2;
    obj.set(y);
    cout<<obj.get()<<endl;
    return 1;
}


