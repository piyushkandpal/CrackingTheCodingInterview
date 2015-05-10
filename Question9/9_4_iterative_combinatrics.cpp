#include<iostream>
#include<vector>
using namespace std;
vector<int>* convertIntToSet(int x,vector<int> *set)
{
    vector<int>* subset = new vector<int>;
    int index = 0;
    for (int k=x; k>0; k>>=1)
    {
        if((k&1)==1)
            subset->push_back(set->at(index));
        index++;
    }
    return subset;
}

vector<vector<int> >* getSubsets(vector<int> *set)
{
    vector<vector<int> >* allSubsets = new vector<vector<int> >;
    int size = set->size();
    //unsigned int max = pow(2,size);
    int max = 1<<size;
    for(int count=0; count<max; count++)
    {
       vector<int>* subset=convertIntToSet(count,set);
       allSubsets->push_back(*subset);
    }
    return allSubsets;
}

int main()
{
    vector<int> set;
    set.push_back(1);
    set.push_back(2);
    set.push_back(3);
    vector<vector<int> >* subSetList = getSubsets(&set);
    vector<vector<int> >::iterator vvIter; 
    vector<int>::iterator vIter; 
    for(vvIter=subSetList->begin();vvIter!=subSetList->end();vvIter++)
    {
        for(vIter=vvIter->begin();vIter!=vvIter->end();vIter++)
            cout<<" "<<(*vIter);
        cout<<endl;
    }
}
