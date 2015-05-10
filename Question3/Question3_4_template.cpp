//Tower of Hanoi using Stacks!
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
template <typename T>
void print_elem(T elem)
{
    cout << elem << endl;       
}

template<typename T>
class Stack{
public:
    void push(T d){t.push_back(d);}
    T pop()
    {
        T d=t.back();
        t.pop_back();
        return d;
    }
    void printstack()
    {
        for_each(t.rbegin(),t.rend(),print_elem<T>);
    }
private:
    vector<T> t;

};

template <typename T>
void MoveTowerofHanoi(T disk, Stack<T> *source, Stack<T> *temp, Stack<T> *destination)
{
    if (disk==1)
    {
        destination->push(source->pop());
    }
    else
    {
        MoveTowerofHanoi(disk-1,source,destination,temp);
        destination->push(source->pop());
        MoveTowerofHanoi(disk-1,temp,source,destination);
    }
}

int main()
{
    int disks;
    cout<<"Enter the number of disks!"<<endl;
    cin>>disks;
    Stack<int>* source = new Stack<int>();
    for(int i=disks; i>0; --i) {
        source->push(i);
    }

    cout<<"Printing Source!"<<endl;
    source->printstack();
    Stack<int>* temp = new Stack<int>();
    Stack<int>* destination = new Stack<int>();
    MoveTowerofHanoi(disks,source,temp,destination);
    cout<<"Printing Destination!"<<endl;
    destination->printstack();
    delete source;
    delete temp;
    delete destination;
}
