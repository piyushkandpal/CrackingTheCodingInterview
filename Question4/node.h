#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};
node *newnode(int k);
