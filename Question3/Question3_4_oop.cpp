//Tower of Hanoi using Stacks!
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;

void print_elem(int elem)
{
    cout << elem << endl;       
}

class Stack{
public:
    void push(int d){t.push_back(d);}
    int pop()
    {
        int d=t.back();
        t.pop_back();
        return d;
    }
    void printstack()
    {
        for_each(t.rbegin(),t.rend(),print_elem);
    }
private:
    vector<int> t;

};

void MoveTowerofHanoi(int disk, Stack *source, Stack *temp, Stack *destination)
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
    Stack* source = new Stack();
    for(int i=disks; i>0; --i) 
    {
        source->push(i);
    }

    cout<<"Printing Source!"<<endl;
    source->printstack();
    Stack* temp = new Stack();
    Stack* destination = new Stack();
    MoveTowerofHanoi(disks,source,temp,destination);
    cout<<"Printing Destination!"<<endl;
    destination->printstack();
    delete source;
    delete temp;
    delete destination;
}
