#include <vector> // the general-purpose vector container
#include <iostream>
#include <algorithm> // remove and remove_if
 
bool is_odd(int i)
{
  return (i % 2) != 0;  
}
 
void print(const std::vector<int> &vec)
{
  for (const auto& i: vec) 
    std::cout << i << ' '; 
  std::cout << std::endl;
}
 
int main()
{
  std::vector<int> v;
  for (int i = 0;i<10;i++)
      v.push_back(i);
  print(v);
 
  // removes all elements with the value 5
  v.erase( std::remove( std::begin(v), std::end(v), 5 ), std::end(v) ); 
  print(v); 
 
  // removes all odd numbers
  v.erase( std::remove_if(std::begin(v), std::end(v), is_odd), std::end(v) );
  print(v);
  return 0;  
}

