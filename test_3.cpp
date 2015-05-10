#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& array,vector<int>& helper,int low,int mid,int high)
{
    int size = array.size();
    for(int i =0;i<size;i++)
        helper.push_back(array[i]);
    //helper = array; // copy vector elements i .. copying references doesnt work hence
    int current = low;
    int helperLeft = low;
    int helperRight = mid+1;
    while(helperLeft<=mid && helperRight <=high)
    {
        if(helper[helperLeft]<helper[helperRight])
        {   array[current] = helper[helperLeft];
            helperLeft++;
        }
        else
        {
            array[current] = helper[helperRight];
            helperRight++;
        }
        current++;
    }
    int remaining = mid - helperLeft;
    for (int i = 0; i <= remaining; i++) 
        array[current + i] = helper[helperLeft + i];
    // copy the remaining elements from the left only and not right because right elememts are already there in dest (array) sorted.
}

void mergeSort(vector<int>&array,vector<int>& helper,int low,int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;
        mergeSort(array,helper,low,mid);// sort left half
        mergeSort(array,helper,mid+1,high);// sort right half
        merge(array,helper,low,mid,high);
    }
}

void mergeSort(vector<int>& array)
{
    vector<int> helper;
    mergeSort(array,helper,0,array.size());
}

int main()
{
    vector<int> v;
    int i =1;
    v.push_back(i);
    v.push_back(i+6);
    v.push_back(i+2);
    v.push_back(i+8);
    v.push_back(i+3);
    v.push_back(i+4);
    v.push_back(i+1);
    v.push_back(i+5);
    v.push_back(i+7);
    vector<int>::iterator it=v.begin();
    while(it!=v.end())
    {
        cout<<" "<<*it;
        it++;
    }
    cout<<endl;
    mergeSort(v);
    it = v.begin();
    while(it!=v.end())
    {
        cout<<" "<<*it;
        it++;
    }
    cout<<endl;
}
