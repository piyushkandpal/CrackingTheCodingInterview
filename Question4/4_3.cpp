#include<iostream>
#include<queue>
using namespace std;

template<typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
};

template<typename T>
Node<T>* newNode(T data)
{
    Node<T>*n = new Node<T>();
    n->data= data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
template<typename T>
void createMinBST(Node<T>*& root,T arr[],int start,int end)
{
    if (start>end)
    {
        return;
    }
    if (root == NULL)
    {
        int mid = (start+end)/2;
        //Node<T>* node = newNode(arr[mid]);
        cout<<"arr["<<mid<<"]"<<" = "<<arr[mid]<<endl;
        root = newNode(arr[mid]);
        createMinBST(root->left,arr,start,mid-1);
        createMinBST(root->right,arr,mid+1,end);
    }
}

template<typename T>
void printBST(Node<T>* root)
{
    cout<<"Inside printLevelNodes"<<endl;
    if(root!=NULL)
    {
        queue<Node<T>*> q;
        q.push(root);
        while(!q.empty())
        {
            Node<T> *n=q.front();
            q.pop();
            cout<<n->data<<" ";
            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
        }
    }
}

int main()
{
    Node<int>* root = NULL;
    int arr[5] = {1,2,3,4,5};
    createMinBST(root,arr,0,4);
    cout<<root->data<<endl;
    printBST(root);
}

