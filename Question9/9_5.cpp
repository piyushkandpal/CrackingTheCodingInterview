#include<iostream>
#include<vector>
using namespace std;

vector<string>* getPerms(string &str)
{
    vector<string>* permutations = new vector<string>;
    //base case
    if(str.size()==0)
    {
        permutations->push_back("");
        return permutations;
    }
    //take the first character
    char first = str[0];
    string remainder = str.substr(1,string::npos);// string::npos takes it till the end of the string
    vector<string>* words = getPerms(remainder);
    vector<string>::iterator strIter;
    for(strIter=words->begin();strIter!=words->end();strIter++)
    {
        int size = strIter->size();
        for(int j=0;j<=strIter->size();j++)
        {
            string s = *strIter;
            s.insert(j,1,first);// means first will be inserted 1 time starting at position j;
            permutations->push_back(s);
        }
    }
    return permutations;
}
int main()
{
    string str= "abcd";
    vector<string>* result = getPerms(str);
    vector<string>::iterator vit;
    cout<<"Result size"<<result->size()<<endl;
    for(vit=result->begin();vit!=result->end();vit++)
    {
        cout<<*vit<<endl;
    }
}
