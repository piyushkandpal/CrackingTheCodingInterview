#include<stdio.h>
 
// This function prints substring of str[] between low and
//  high indexes (both inclusive). 
 void mysubstr(char str[], int low, int high)
 {
     if (low<=high)
         {
                 printf("%c", str[low]);
                         mysubstr(str, low+1, high);
                             }
                             }
                              int main ()
                              {
                                  char str[] = "geeksforgeeks";
                                      mysubstr(str, 1, 3);
                                          return 0;
                                          }
