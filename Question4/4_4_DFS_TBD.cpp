#include<iostream>
#include<vector>
#include<list>
using namespace std;

template<typename T>
struct Node
{
    T data;
    Node<T> *left,*right;
};

template<typename T>
Node<T>* newNode(T data)
{
    Node<T>* root = new Node<T>();
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

template<typename T>
void createMinBST(Node<T>*& root,T arr[],int start,int end)
{
    if(start>end)
        return;
    int mid = (start+end)/2;
    if (root == NULL)
    {
        root = newNode(arr[mid]);
        createMinBST(root->left, arr,start , mid-1);
        createMinBST(root->right, arr,mid+1 , end);
    }
}

template<typename T>
void levelLinkedLists(vector<list<Node<T>*> >& res,Node<T>* root)
{
    list<Node<T>*>li;
    li.push_back(root);
    res.push_back(li);
    int depth = 0;
    while(!res[depth].empty())
    {
        list<Node<T>*>l;
        typename list<Node<T>*>::iterator iter;
        for(iter = res[depth].begin();iter != res[depth].end(); iter++)
        {
            if((*iter)->left)
                l.push_back((*iter)->left);
            if((*iter)->right)
                l.push_back((*iter)->right);
        }
        depth++;
        res.push_back(l);
    }
}

template<typename T>
void printLevelLinkedLists(vector<list<Node<T>*> > res)
{
    typename vector<list<Node<T>*> >::iterator iter;
    for (iter = res.begin(); iter!= res.end();iter++)
    {
        list<Node<T>*>li = *iter;
        typename list<Node<T>*>::iterator it;
        for (it = li.begin(); it != li.end(); it++ )
        {
            cout << (*it)->data <<" ";
        }
        cout<<endl;
    }
}

int main()
{
     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
     Node<int>* root;
     root = NULL;
     createMinBST(root, arr, 0, 8);
     vector<list<Node<int>*> > res;
     levelLinkedLists(res, root);
     printLevelLinkedLists(res);

}
