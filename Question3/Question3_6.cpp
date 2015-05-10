#include<stack>
#include<iostream>

using namespace std;

template<typename T>
stack<T>& sortStack(stack<T>& s)
{
    stack<T>* r= new stack<T>();
    while (!s.empty())
    {
        T tmp = s.top();
        cout<<"tmp = "<<tmp<<endl;
        s.pop();
        while (!r->empty() && tmp<r->top())
        {
            s.push(r->top());
            r->pop();
        }
        r->push(tmp);
    }
    cout<<"finished"<<endl;
    return (*r);
}

int main()
{
    stack<int> s;
    s.push(7);
    s.push(6);
    s.push(5);
    s.push(3);
    s.push(4);
    s.push(1);
    s.push(2);
    stack<int> r = sortStack<int>(s);
    while (!r.empty())
    {
        cout<<r.top()<<endl;
        r.pop();
    }
}
    
