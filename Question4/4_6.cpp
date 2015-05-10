#include<iostream>
#include<stack>
using namespace std;

struct node{
        int data;
        node *right, *left;
};

void createMinimalBst(node* &root, int arr[], int start, int end){
        if(start>end)
                return;
        if(root==NULL){
                node *ptr = new node;
                int ind = start + (end-start)/2;
                ptr->data = arr[ind];
                ptr->left = NULL;
                ptr->right = NULL;
                root = ptr;
                createMinimalBst(root->left, arr, start, ind-1);
                createMinimalBst(root->right, arr, ind+1, end);
            }
}

node* inOrderSuccessor(node* root,int k)
{
    stack<node*> S;
    int foundNode = false;
    if (root ==NULL)
        return NULL;
    node* ptr = root;
    while (true)
    {
        while(ptr)
        {
            S.push(ptr);
            ptr=ptr->left;
        }
        if(S.empty())
            break;
        ptr = S.top();
        S.pop();
        if(foundNode)
            return ptr;  
        if(ptr->data == k)
        {
            foundNode = true;
        }
        ptr = ptr->right;
    }
}

int main(){
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        node* root;
        root = NULL;
        createMinimalBst(root, arr, 0, 8);
        node* searchedNode = inOrderSuccessor(root, 4);
        cout<<searchedNode->data<<'\n';
}
