#include<iostream>
#include<vector>
using namespace std;
int main()
{
    //vector<bool>v(3);
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout<<"size = "<<v.size()<<endl;
    cout<<"front  = "<<v.front()<<endl;
    cout<<"back = "<<v.back()<<endl;
    cout<<"v[0] , v[1] , v[2] = "<<v[0]<<" , "<<v[1]<<" , "<<v[2]<<endl;
    v.pop_back();
    //cout<<"pop_front"<<v.pop_front()<<endl; // This is not a member in vector
    cout<<"front after pop_back"<<v.front()<<endl;
    cout<<"back after pop_back"<<v.back()<<endl;
    //v.emplace_back(2); c++11 directive
    
    cout<<v.at(0)<<endl;
    cout<<v.at(1)<<endl;
    
    try
    {
        cout<<v.at(3)<<endl;
    }
    catch (exception &e)
    {
        cout<<e.what()<<endl;
    }
    
    return 1;
}
