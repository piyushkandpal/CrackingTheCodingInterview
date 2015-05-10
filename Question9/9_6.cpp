#include<vector>
#include<iostream>
using namespace std;

void addParen(vector<string>* list,int leftRem,int RightRem,
        char*& str,int count)
{
    if (leftRem < 0 || RightRem < leftRem) return;
    if(leftRem ==0 && RightRem ==0)
    {
        list->push_back(str);
    }
    else
    {
        if(leftRem>0)
        {
            str[count]='(';
            addParen(list,leftRem-1,RightRem,str,count+1);
        }
        if(RightRem>leftRem)
        {
            str[count] = ')';
            addParen(list,leftRem,RightRem-1,str,count+1);
        }
    }
}
vector<string>* getParens(int count)
{
    char *arr=new char[2*count];
    vector<string>* list = new vector<string>;
    addParen(list, count, count,arr,0);
    return list;
}


int main()
{
    vector<string>* res = getParens(3);
    for(int i = 0;i<res->size();i++)
    {
        cout<<res->at(i)<<endl;
    }
    return 0;
}
