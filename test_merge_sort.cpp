#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &array,int low,int mid,int high)
{
    vector<int> helper(high-low+1);
    for(int i=low;i<=high;i++)
        helper[i]=array[i];
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
    while(helperLeft<mid)    
        array[current++] = helper[helperLeft++];
    // copy the remaining elements from the left only and not right because right elememts are already there in dest (array) sorted.
}

void mergeSort(vector<int>&array,int low,int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;
        mergeSort(array,low,mid);// sort left half
        mergeSort(array,mid+1,high);// sort right half
        merge(array,low,mid,high);
    }
}

void mergeSort(vector<int>& array)
{
    mergeSort(array,0,array.size()-1);
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
