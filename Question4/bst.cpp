#include <iostream>
#include "bst.h"
using namespace std;

void createMinBST(node *&root,int arr[],int start, int end)
{
    if (start> end)
        return;
    int mid = (start+end)/2;
    node *ptr = newnode(arr[mid]);
    root = ptr;
    createMinBST(root->left,arr,start,mid-1);
    createMinBST(root->right,arr,mid+1,end);
}

