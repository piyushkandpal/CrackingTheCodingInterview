#include<iostream>
#include<list>
using namespace std;

template<typename T>
struct Node
{
    T data;
    Node<T> *left,*right;
};

template<typename T>
void f()
{
    list<Node<T>*>::iterator i;
}

int main()
{
    f<int>();
}

