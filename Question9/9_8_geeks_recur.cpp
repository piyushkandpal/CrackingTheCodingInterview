#include<iostream>
using namespace std;
// n is the amount 
// m is no of coints , S is array containing amount of chnage representing each coin number
int makeChange( int S[], int m, int n )
{
    if(n==0)
        return 1;

    if(m<=0 && n>=1)
        return 0;
    
    if (n <0)
        return 0;
    //make change excluding m (actually m-1 th) coin + including m-1 the coin (infinite supply)
    return makeChange(S,m-1,n)+makeChange(S,m,n-S[m-1]);
}

int main()
{
    int i,j;
    int arr[]= {1,2,3};
    int m = sizeof(arr)/sizeof(arr[0]);
    cout<<makeChange(arr,m,10)<<endl;;
    return 0;
}
