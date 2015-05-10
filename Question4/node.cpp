#include "node.h"
#include <iostream>

using namespace std;
// Utility function creates a new binary tree node with given key
node *newnode(int k)
{
    node *temp = new node;
    temp->data = k;
    temp->left = temp->right = NULL;
    return temp;
}
