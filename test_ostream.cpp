#include<iostream>
//In C++ you can overload operator<< for ostream and your custom class:
class A {
public:
  int i;
};

std::ostream& operator<<(std::ostream &strm, const A &a) 
{
  return strm << "A(" << a.i << ")";
}
//This way you can output instances of your class on streams:
/*
int main()
{
    A x;
    x.i = 1;
    std::cout << x << std::endl;
}*/
//In case your operator<< wants to print out internals of class A and really needs access to its private and protected members you could also declare it as a friend function:

class B {
private:
  //friend std::ostream& operator<<(std::ostream&, const B&);
  friend std::ostream& operator<<(std::ostream&,const B&);
  int j=2;
};

std::ostream& operator<<(std::ostream &strm,const B&b) 
{
  return strm << "B(" << b.j << ")";
}

int main()
{
    A a;a.i=1;
    B b;
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
}


