#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};

void createMinBST(node *&root,int arr[],int start,int end)
{
    if(start>end)
        return;
    int i = (start+end)/2;
    node *ptr= new node();
    root = ptr;
    root->data = arr[i];
    root->left = NULL;
    root->right = NULL;
    createMinBST(root->left,arr,start,i-1);
    createMinBST(root->right,arr,i+1,end);
}

bool isDescendant(node *parent,node *child)
{
    if (parent == NULL)
        return false;
    if (parent==child)
        return true;
    else 
        return (isDescendant(parent->left,child)||isDescendant(parent->right,child));
}

node* commonAncestor(node *root,node *root1,node *root2)
{
    if (root ==NULL)
        return NULL;
    if ((root==root1)||(root==root2))
        return root;
    bool root1_on_left = isDescendant(root->left,root1);   
    bool root2_on_left = isDescendant(root->left,root2);   
    if (root1_on_left && root2_on_left)
        return commonAncestor(root->left, root1, root2);
    else if (root1_on_left || root2_on_left)
        return root;
    else 
        return commonAncestor(root->right, root1, root2);
}

int main()
{
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        node* root;
        root = NULL;
        createMinBST(root, arr, 0, 8);
        node *ancestor = commonAncestor(root, root->left->left, root->left->right->right);
        cout<<ancestor->data;
}
