#include<iostream>
using namespace std;
// n is the amount 
// m is no of coints , S is array containing amount of chnage representing each coin number
int makeChange( int S[], int m, int n )
{
    int i,j,x,y;
    // this will be a hash table in case the no of elements are huge;
    // for sum n ,no of solutions using m coins
    int table[n+1][m];
    // marking the places where 0 is the sum required hence only 1 soln in that case
    for (int i=0;i<m;i++)
        table[0][i]=1;
    for(i=1;i<n+1;i++)
    {    
        for(j =0;j<m;j++)
        {
            // Count of solns including S[j]
            x = ( i - S[j] >= 0) ? table[i-S[j]][j] : 0;
            // Count of solutions excluding S[j]
            y = ( j-1 >= 0 ) ? table[i][j-1] : 0;
            table[i][j] = x+y;
        }
    }
    return table[n][m-1];
}

int main()
{
    int i,j;
    int arr[]= {1,2,3};
    int m = sizeof(arr)/sizeof(arr[0]);
    cout<<makeChange(arr,m,10)<<endl;;
    return 0;
}
