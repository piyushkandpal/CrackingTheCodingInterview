#include<iostream>
#include<deque>
using namespace std;
template<typename T>
void iterateDeq(deque<T> &deq)
{
    for(typename deque<T>::iterator dit=deq.begin();dit!=deq.end();dit++)
    {
        cout<<*dit<<endl;
    }
}
int main()
{
    deque<int>deq;
    for (int i=0;i<10;i++)
    {
        deq.push_back(i);
    }
    cout<<"iterating over deq"<<endl;
    iterateDeq(deq);
    deq.pop_front();
    deq.pop_back();
    cout<<"iterating over deq"<<endl;
    iterateDeq(deq);
    if (find(deq.begin(),deq.end(),5)!=deq.end())
        cout<<" 5 is inside the dq"<<endl;
    else
        cout<<" 5 is inside the dq"<<endl;
    // to remove element 5 use std::remove fn
    cout<<"to be removed 5"<<endl;
    deq.erase(remove(deq.begin(),deq.end(),5),deq.end());
    cout<<"iterating over deq"<<endl;
    iterateDeq(deq);
    return 1;
}
