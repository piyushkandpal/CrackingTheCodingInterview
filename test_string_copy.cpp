// string::copy
#include <iostream>
#include <string>
int main ()
{
  char buffer[20];
  std::string str ("Test string...");
  std::size_t length = str.copy(buffer,6,5);
  buffer[length]='\0';// copy doesn’t Add null terminating char  
  std::cout << "buffer contains: " << buffer << '\n';
  return 0;
}

