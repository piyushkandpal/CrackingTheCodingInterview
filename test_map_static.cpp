#include<iostream>
#include <map>
using namespace std;

struct A{
    static map<int,int> create_map()
        {
          map<int,int> m;
          m[1] = 2;
          m[3] = 4;
          m[5] = 6;
          return m;
        }
    static const map<int,int> myMap;

};

const map<int,int> A:: myMap =  A::create_map();

int main() {
cout<<A::myMap.at(1)<<endl;
}
