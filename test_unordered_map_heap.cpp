#include<unordered_map>
#include<iostream>
using namespace std;
int main()
{
   unordered_map<string,int>* hmap = new unordered_map<string,int>();
   (*hmap)["abc"] = 1;
   cout<<"map[anc]"<<(*hmap)["abc"]<<endl;
   std::unordered_map<string,int>::const_iterator got = (*hmap).find("abc");
     if ( got == (*hmap).end() )
             std::cout << "not found";
       else
               std::cout << got->first << " is " << got->second;
         std::cout << std::endl;
   return 1;
}
