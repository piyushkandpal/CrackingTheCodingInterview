#include <list>
#include <algorithm>
#include <iostream>
bool comp(const int v)
{
    return 0 == (v%17);
}
int main()
{
    std::list<int> myList;
    myList.push_back(5); 
    myList.push_back(19); 
    myList.push_back(17); 
    myList.push_back(34); 
    myList.push_back(22); 
auto it = std::find_if( std::begin( myList ),
                            std::end( myList ),
                            comp);
if ( myList.end() == it )
    {
        std::cout << "item not found" << std::endl;
    }
    else
    {
        const int pos = std::distance( myList.begin(), it ) + 1;
        std::cout << "item divisible by 17 found at position " << pos << std::endl;
    }
}
