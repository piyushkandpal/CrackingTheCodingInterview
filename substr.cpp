#include <stdio.h>
 
// This function prints substring of str[] between low and
// // high indexes (both inclusive). 
void mysubstr(char str[], int low, int high)
 {
     printf("%.*s", high-low+1, (str+low));
     }
//      
      int main ()
      {
          char str[] = "geeksforgeeks";
              mysubstr(str, 1, 3);
                  return 0;
                 }
