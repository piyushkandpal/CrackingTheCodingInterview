#include<iostream>
#include<deque>
#include<list>
using namespace std;
int main()
{
    //below doesnt complies
    //deque<int>* dq = new list<int>();
    list<int> *l = new list<int>();
    //deque<int> *dq = reinterpret_cast<deque<int>*> (l);
    (*l).push_back(1);
    (*l).push_front(2);
    cout<<(*l).front()<<endl;
    cout<<(*l).back()<<endl;
    return 256;
}

