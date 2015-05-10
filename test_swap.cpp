#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    cout<<v[1]<<v[2]<<endl;
    swap(v[1],v[2]);
    cout<<v[1]<<v[2]<<endl;
    return 1;
}
