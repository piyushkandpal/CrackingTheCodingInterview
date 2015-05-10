#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> VI;

void print(VI v)
{
    cout<<"elements are:"<<endl;
    for(int i =0; i<v.size();i++)
        cout << " "<<v[i];
    cout<<endl;
}

void combineSorted(VI& A,VI& B)
{
    int lIdA= A.size()-1;
    int lId= A.size()+B.size()-1;
    int lIdB = B.size()-1;
    A.resize(A.size()+B.size()); 
    while(lIdA>=0 && lIdB>=0)
    {
        if(A[lIdA]>B[lIdB])
        {
            A[lId] = A[lIdA];
            lId--;
            lIdA--;
        }   
        else
        {
            A[lId] = B[lIdB];
            lId--;
            lIdB--;
        }
    }
    while(lIdB>=0)
    {
            A[lId] = B[lIdB];
            lId--;
            lIdB--;
    }
}
int main()
{
    VI A;
    VI B;
    for(int i =0;i<18;i++)
    {
        if(i%2==0 && i <13)
            A.push_back(i);
        else
            B.push_back(i);
    }
    cout<<"elements of A"<<endl;
    print(A);
    cout<<"elements of B"<<endl;
    print(B);
    combineSorted(A,B);
    cout<<"elements of A"<<endl;
    print(A);
}
