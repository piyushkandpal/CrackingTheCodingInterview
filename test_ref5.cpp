#include<iostream>
using namespace std;
 
int main()
{
       int x = 10;
       int *ptr = &x;
       int &y = x;       
       int &*ptr1 = &y;
}
