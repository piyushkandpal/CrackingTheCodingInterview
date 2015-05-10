#include <iostream>
#include <hash_map>

using namespace stdext;
using namespace std;

class CompareStdString
{
public:
bool operator ()(const string & str1, const string & str2) const
    {
        return str1.compare(str2) < 0;
    }
};
int main()
{
    hash_map<string, int, hash_compare<string, CompareStdString> > Map;
    Map.insert(make_pair("one", 1));
    Map.insert(make_pair("two", 2));
    Map.insert(make_pair("three", 3));
    Map.insert(make_pair("four", 4));
    Map.insert(make_pair("five", 5));
    hash_map<string, int, hash_compare<string, CompareStdString> > :: iterator i;
    for (i = Map.begin(); i != Map.end(); ++i)
    {
        i -> first; // they are ordered as three, five, two, four, one
    }
    return 0;
}
