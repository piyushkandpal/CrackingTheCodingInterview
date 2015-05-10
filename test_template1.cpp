#include<iostream>

using namespace std;

template <typename T>
T mymax(T x,T y)
{
    return x>y?x:y;
}
class Person
{
    int x;
    public:
    Person(int x)
    {
        this->x = x;
    }
    
    friend ostream & operator << (ostream &out, const Person &p);

    Person &operator >(const Person &p)
    {
        if (p.x > this->x)
            return p;
        else
            return this;
    }
}

ostream & operator << (ostream &out, const Person &p)
{
        out << p.x<<endl;
        return out;
}
int main()
{
    cout<<"int : "<<mymax<int>(3,2)<<endl;
    cout<<"float : "<<mymax<float>(7.2,7.5)<<endl;
    cout<<"int : "<<mymax<char>('e','g')<<endl;
    p1 = Person(5);
    p2 = Person(7);
    cout<<"Person"<<mymax<Person>(p1,p2)<<endl;
    return 0;
}
