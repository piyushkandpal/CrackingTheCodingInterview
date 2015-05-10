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
    int leftIndex = min(mid-1,arr[mid]);
    int left = getMagicNumber(arr,start,left);
    if (left >0 )
        return left;
    int rightIndex = max(mid+1,arr[mid]);
    int right = getMagicNumber(arr,right,end);
    if (right >0 )
        return right;
}
int main()
{
    int arr[9] = {-40, -20, -1, -1, 2, 2, 4, 7, 9};
    int size = sizeof(arr)/sizeof(*arr);
    cout<<getMagicNumber(arr,0,size-1,size)<<endl;
}
