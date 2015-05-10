#include <iostream>
#include <string>
//#include "Misc/SimpleHashTable.h"
using namespace std;
bool checkStrIsNullOrEmptyOrChar(string& s)
{

    if (s.empty())
    {
        cout<<"string is empty or null"<<endl;
        return true;
    }
    int len = s.length();
    if (len < 2)
    {
        cout<<"string length less than 2"<<endl;
        return true;
    }
    return false;
}
string removeDupChars(string& str)
{
    bool err = checkStrIsNullOrEmptyOrChar(str);
    if (err)
        return str;
    cout<<"Original string is "<<str<<endl;
    int tail = 1;
    int len = str.length();
    for (int i=1; i<len; i++)
    {
        int j;
        for (j = 0; j<tail;j++)
        {
            if(str[i] == str[j])
                break;
        }
        if (j == tail)
        {
            str[tail]=str[i];
            tail++;
        }

    }
    str[tail]=0;
    cout<<"returned string is str "<<str<<endl;
    return str;
}

string removeDupChars_constArr(string& str)
{
    bool err = checkStrIsNullOrEmptyOrChar(str);
    if (err)
        return str;
    cout<<"Original string is "<<str<<endl;
    int len = str.length();
    bool arr[256] ={false};
    arr[str[0]]=true;
    int tail = 1;
    for (int i=1;i<len;i++)
    {
        if (!arr[str[i]])
        {
            str[tail] = str[i];
            tail++;
            arr[str[i]] = true;
            
        }
        else
            cout<<str[i]<<" is duplicate"<<endl; 
    }
    str[tail] = '\0';
    return str;
}





int main()
{
    string str = "abcda";
    string str2 = "abcde";
    string str3 = "ppppp";
    string str4 = "";
    string str5;
    string str6 = "pqpqpq";
    string str7 = "abcdpqpqpqefghpqpq";

    cout<<removeDupChars_constArr(str)<<endl;
    cout<<removeDupChars_constArr(str2)<<endl;
    cout<<removeDupChars_constArr(str3)<<endl;
    cout<<removeDupChars_constArr(str4)<<endl;
    cout<<removeDupChars_constArr(str5)<<endl;
    cout<<removeDupChars_constArr(str6)<<endl;
    cout<<removeDupChars_constArr(str7)<<endl;
}

