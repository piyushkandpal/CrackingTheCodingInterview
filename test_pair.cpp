//#include<utilities>
#include<iostream>
using namespace std;
int main()
{
    pair<string,int>p;
    p= make_pair("1",1);
    
    cout<<p.first<<endl;
    cout<<p.second<<endl;
    p.first = "One";
    cout<<p.first<<endl;
    cout<<p.second<<endl;
    return 1;
}

