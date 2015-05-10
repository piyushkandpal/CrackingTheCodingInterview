#include<iostream>
using namespace std;

void allocate(int*& p)
{
  p = (int*)malloc(sizeof(int));
}
//OR
/*
 * void allocate(int **p)
 * {
 *  *p = (int*) malloc(sizeof(int));
 * }
 * int main()
 * {
 *  int *p = NULL;
 *  allocate(&p);
 *  *p = 42;
 *  free(p);
 * }
 */
int main()
{
  int* p = NULL;
  allocate(p);
  *p = 42;
  free(p);
}
