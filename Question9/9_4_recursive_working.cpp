#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

VVI*  getSubsets(VI* set, int index)
{
    VVI* allSubsets;
    if(set->size() == index) //base case
    {
        allSubsets = new VVI;
        VI* set = new VI;
        allSubsets->push_back(*set);
    }   
    else
    {
        allSubsets = getSubsets(set,index+1);
        int item = (*set)[index];
        VVI* moreSubSets = new VVI;
        VVI::iterator subSetIter;
        for (subSetIter=allSubsets->begin();subSetIter!=allSubsets->end();subSetIter++)
        {
            VI* newSubSet = new VI;
            newSubSet->insert(newSubSet->end(),subSetIter->begin(),(*subSetIter).end());
            newSubSet->push_back(item);
            moreSubSets->push_back(*newSubSet);
        }
        allSubsets->insert(allSubsets->end(),moreSubSets->begin(),moreSubSets->end());
    }
    return allSubsets;
}

int main()
{
    vector<int> *v = new vector<int>;
    v->push_back(1);
    v->push_back(2);
    v->push_back(3);
    VVI *vvi  =  getSubsets(v,0);
    VVI::iterator vviIter;
    VI::iterator viIter;
    for(vviIter=vvi->begin();vviIter!=vvi->end();vviIter++)
    {
        for(viIter=vviIter->begin();viIter!=vviIter->end();viIter++)
            cout<<" "<<(*viIter);
        cout<<endl;
    }
}
