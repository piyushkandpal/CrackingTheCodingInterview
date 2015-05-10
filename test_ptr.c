#include<stdio.h>
int main()
{
    char *s = malloc(5);
    strcpy(s,"hii");
    char *p=s;
    printf("%s %s\n",p,s);
    strcpy(p,"hell");
    //p=NULL;
    printf("%s\n",s);
}

