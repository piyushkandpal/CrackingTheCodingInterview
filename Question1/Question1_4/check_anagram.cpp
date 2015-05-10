#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool check_anagram_1(string& s1,string& s2)
{
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1.compare(s2)==0)    
        return true;
    return false;

}

bool check_anagram_2(const string& s1,const string& s2)
{
    size_t l1 = s1.size();
    size_t l2 = s2.size();
    if (l1!=l2)
        return false;
    int arr[256]={0};
    int i = 0,num =0;
    for (; i<l1; i++)
    {
        arr[s1[i]]++;
        num++;
    }
    for ( i=0; i<l2; i++)
    {
        if (arr[s2[i]] == 0)
            return false;
        --arr[s2[i]];
        num--;
        if (num==0)
            return true;
    }
    return false;
}

int main()
{
    string str1 = "abcdee";
    string str2 = "abeedc";
    string str3 = "qwkjwq";

    cout<<"str 1 "<<str1<<" str2"<<str2<< "are anagram : "<<check_anagram_2(str1,str2)<<endl;
    cout<<"str 1 "<<str1<<" str3 "<<str3<< "are anagram : "<<check_anagram_2(str1,str3)<<endl;
    cout<<"str 2 "<<str2<<" str3 "<<str3<< "are anagram : "<<check_anagram_2(str2,str3)<<endl;
    return 0;
}

