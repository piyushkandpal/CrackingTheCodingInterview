#include<iostream>
#include<cmath>
#include<queue>

using namespace std;
template<typename T>
struct Node
{
    T data;
    Node<T> *left,*right;
};

template<typename T>
Node<T>* createNode(T data)
{
    Node<T> *n = new Node<T>();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}


template<typename T>
class BTree
{
    Node<T> *root;
    int checkHeight(Node<T>*& root) const;
    public:
        Node<T>* getRoot(){ return root;}
        BTree(T data) { root = createNode(data);};
        void postOrderTraversal(){};
        void preOrderTraversal(){};
        void inOrderTraversal(){};
        bool isBalanced();
        Node<T>*& insertNode(T data,Node<T>*&);
        void displayTree() const;
        void printLevelNodes();
};

template<typename T>
void BTree<T>::printLevelNodes()
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


template<typename T>
Node<T>*&  BTree<T>::insertNode(T data,Node<T>*& root)
{
    if (root==NULL)
    {
        cout<<"creating new node"<<endl;
        root= createNode(data);
    }
    else if (data < root->data)
    {
        cout<<"data < root->data "<<endl;
        root->left = insertNode(data,root->left);
    }
    else if (data > root->data)
    {
        cout<<"data > root->data "<<endl;
        root->right = insertNode(data,root->right);
    }
    return root;
}

template<typename T>
int BTree<T>::checkHeight(Node<T>*& root)const
{
    if (root==NULL)
        return 0;
    int lh = checkHeight(root->left);
    if (lh == -1)
        return -1;
    int rh = checkHeight(root->right);
    if(rh == -1)
        return -1;
    if(abs(lh-rh)>1)
        return -1;
    else
    {
        //cout<<"Height is "<<max(lh,rh)+1<<endl;
        return max(lh,rh)+1;
    }
}

template<typename T>
bool BTree<T>::isBalanced()
{
    int h =checkHeight(root);
    return (h>0?true:false);
}



int main()
{
    BTree<int>* bt=new BTree<int>(4);    
    Node<int> *root=bt->getRoot();
    //root = bt->insertNode(rand()%100,root);
    root = bt->insertNode(3,root);
    root = bt->insertNode(5,root);
    root = bt->insertNode(2,root);
    root = bt->insertNode(7,root);
    root = bt->insertNode(1,root);
    //for (int i=0;i<10;i++)
    //    bt->insertNode(rand()%100,root);
    bt->printLevelNodes();
    cout<<endl;
    cout<<"Is Balanced : "<<bt->isBalanced()<<endl;
}

        


