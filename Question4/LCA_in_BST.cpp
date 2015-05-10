#include <iostream>
#ifndef __NODE_H
#define __NODE_H
#include "node.h"
#endif
#include "bst.h"
#include <vector>

using namespace std;
bool findPath(node *root,vector<int> &path,int key)
{
    if (root==NULL)
        return false;
    path.push_back(root->data);
    if(root->data == key)
        return true;
    if (findPath(root->left,path,key)||findPath(root->right,path,key))
        return true;
    path.pop_back();
    return false;
}

int findLCA(node *root,int n1,int n2)
{
    if (root==NULL)
        return -1;
    vector<int> p1,p2;
    int path_1_exists = findPath(root,p1,n1);
    int path_2_exists = findPath(root,p2,n2);
    if ((!path_1_exists) || (!path_2_exists))
        return false;
    // compare paths
    vector<int>::iterator i,j;
    for(i=p1.begin(),j=p2.begin();i!=p1.end()&& j!=p2.end();i++,j++)
    {
       if ((*i != *j) && (i!=p1.begin()))
           return *(i-1);
    }
}

int main()
{
    cout<<"yooo"<<endl;
    int arr[] = {0,1,2,3,4,5,6,7,8};
    node *root = NULL;
    createMinBST(root,arr,0,sizeof(arr)-1);
    cout<<"I am here"<<endl;
    int Lca = findLCA(root,4,5);
    cout<< "LCA is : "<<Lca<<endl;
}

