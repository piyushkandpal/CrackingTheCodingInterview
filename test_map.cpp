#include<iostream>
#include<map>
using namespace std;
class A {
private:
    std::map<int, int> m;
public:
    int getValue(int key) ;
    // if get function is const then use at attribute of map
    int getValueconst(int key) const {return m.at(key);}
    void setValue(int key,int value){m[key]=value;}
};
int A::getValue(int key) {
    return m[key];
}

int main()
{
    A a;
    a.setValue(1,100);
    try
    {
        cout<<a.getValueconst(2)<<endl;
    }
    catch (exception &e)
    {
        cout<<e.what()<<endl;
    }
    catch(std::out_of_range)
    {
        cout<<"caught"<<endl;
    }
    catch(...)
    {
        cout<<"caught generic"<<endl;
    }
    return 1;
}
