#include<iostream>
using namespace std;

int getMagicNumber(int arr[],int start,int end,int size)
{
    int mid;
    if( end < start || end >= size || start <0)
    {
        cout<<"start = "<<start<<"  end = "<<end<<endl;
        return -1;
    }
    mid = (start+end)/2;
    if(arr[mid] == mid)
        return mid;
    else if(arr[mid]<mid)
    {
        return getMagicNumber(arr,mid+1,end,size);
    }
        
    else if(arr[mid]>mid)
    {
        return getMagicNumber(arr,start,mid-1,size);
    }
}
int main()
{
    int arr[9] = {-40, -20, -1, 1, 2, 3,4 , 7, 9};
    int size = sizeof(arr)/sizeof(*arr);
    cout<<getMagicNumber(arr,0,size-1,size)<<endl;
}
