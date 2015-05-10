#include <iostream>
#include <vector>
using namespace std;

int split_array(vector<int>& array, int pivot, int start_index, int end_index)
{
    int left_boundary = start_index;
    int right_boundary = end_index;
    while (left_boundary < right_boundary) {
        while (pivot < array[right_boundary] && right_boundary > left_boundary) {
            right_boundary--;
        }
        swap(array[left_boundary], array[right_boundary]);
        while (pivot >= array[left_boundary] && left_boundary < right_boundary) {
            left_boundary++;
        }
        swap(array[right_boundary], array[left_boundary]);
    }
    return left_boundary;
}
void quicksort(vector<int>& array, int start_index, int end_index)
{
    int pivot = array[start_index];
    int split_point;
    if (end_index > start_index) {
        split_point = split_array(array, pivot, start_index, end_index);
        array[split_point] = pivot;
        quicksort(array, start_index, split_point-1);
        quicksort(array, split_point+1, end_index);
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
    quicksort(v,0,v.size()-1);
    it = v.begin();
    while(it!=v.end())
    {
        cout<<" "<<*it;
        it++;
    }
    cout<<endl;
}

