#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
struct
{
    int sum;
    void operator()(int element) { sum+=element; }
} functor;
struct add_x {
  add_x(int x) : x(x) {} // this is a structure constructor 
  int operator()(int y) { return x + y; }
private:
  int x;
};

int main()
{
    /*
    functor.sum=0;
    vector<int> your_first_container;
    for (int i = 0;i<5;i++)
        your_first_container.push_back(i);
    vector<int> your_second_container;
    for (int i = 0;i<5;i++)
        your_second_container.push_back(i);

    functor = for_each(your_first_container.begin(), your_first_container.endl(), functor);
    functor = for_each(your_second_container.begin(), your_second_container.endl(), functor);
    std::cout<<"The sum of all the elements is: "<<functor.sum<<std::endll;
    */
    // Now you can use it like this:
    cout<<"1"<<endl;
    add_x add42(42); // create an instance of the functor class
    cout<<"2"<<endl;
    int i = add42(8); // and "call" it
    cout<<"3"<<endl;
    assert(i == 50); // and it added 42 to its argument
    cout<<"4"<<endl;
    std::vector<int> in; // assume this contains a bunch of values)
    cout<<"5"<<endl;
    std::vector<int> out;
    for (int i = 0;i<5;i++)
        in.push_back(i);
    // Pass a functor to std::transform, which calls the functor on every element 
    // in the input sequence, and stores the result to the output sequence
    cout<<"6"<<endl;
    transform(in.begin(), in.end(), out.begin(), add_x(1)); 
    cout<<"7"<<endl;
    assert(out[i] == in[i] + 1); // for all i
    cout<<"8"<<endl;
}
