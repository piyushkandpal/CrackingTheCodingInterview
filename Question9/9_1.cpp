#include<iostream>
using namespace std;
long int countSteps(int n,int map[])
{
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    if(map[n]> -1)
        return map[n];
    else
    {
         map[n] = countSteps(n-1,map)+countSteps(n-2,map)+countSteps(n-3,map);
         return map[n];
    }
}
int main()
{
    int N = 36;
    int map[36];
    memset(map,-1,sizeof(map));
    for(int i=0;i<N;i++)
    {   cout<< "No of ways to reach "<<i<<" steps is: ";
        cout<<countSteps(i,map);
        cout<<endl;
    }
}

