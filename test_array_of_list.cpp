#include<iostream>
#include<list>
#include<algorithm>
// <algorithm< for std::find
using namespace std;

int main()
{
    list<int> *items;
    items = new list<int>[10];
    cout<<sizeof(*items)<<"----"<<endl;
    /* test */
    if(items[2].size()==0)
        cout << "uninitialised values are NULL inside list"<<endl;
    for (int i =0;i<10;i++)
    {
        items[i].push_back(i);
        items[i].push_back(2);
        items[i].push_back(i+3);
    }
    for (int i =0;i<10;i++)
    {
        cout<<items[i].front()<<" ";
        cout<<items[i].back()<<endl;
    }
    delete []items;
    return 1;

}
