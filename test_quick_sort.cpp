#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int partition(vector<int>& arr,int left,int right)
{
    int pivot = arr[left+(right-left)/2];
    cout<<" pivot = "<<pivot<<endl;
    while(left<=right)
    {
        while (arr[left]<pivot)
            left++;
        while (arr[right]>pivot)
            right--;
        if (left<right)
        {
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
    return left;
}
    
void quickSort(vector<int>& arr,int left,int right)
{
    int index = partition(arr,left,right);
    if(left<index-1)
    { // sort left half
        quickSort(arr,left,index-1);
    }
    if(right>index)
    { // sort right half
        quickSort(arr,index,right);
    }
}

int main()
{
    vector<int> v;
    v.push_back(9);
    v.push_back(7);
    v.push_back(2);
    v.push_back(8);
    v.push_back(6);
    v.push_back(5);
    v.push_back(4);
    vector<int>::iterator it;
    it = v.begin();
    while(it!=v.end())
    {
        cout<<" "<<*it;
        it++;
    }
    cout<<endl;
    quickSort(v,0,v.size()-1);
    it = v.begin();
    while(it!=v.end())
    {
        cout<<" "<<*it;
        it++;
    }
    cout<<endl;
}

