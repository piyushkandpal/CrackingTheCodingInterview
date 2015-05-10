#include<iostream>
using namespace std;
int main()
{
    int *ptr = new int[5];
    int *ptr2 = new int;
    cout << "initialising .. "<<endl;
    for (int i =0;i<5;i++)
    {
        ptr[i]=i;
    }
    cout << "printing .. "<<endl;
    for (int i =0;i<5;i++)
    {
        cout<<"ptr[i]"<<ptr[i]<<endl;
    }
    *ptr2 = 22;
    cout<<" *ptr2 = "<<*ptr2<<endl;
    delete []ptr;
    delete ptr2;
}
    

    
