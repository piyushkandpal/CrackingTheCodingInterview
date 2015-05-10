#include <iostream>
using namespace std;
 
class A {
        int i;
    public:
        A(int );
};
 
A::A(int arg) {
        i = arg;
        cout << "A's Constructor called: Value of a: " << i << endl;
}
 
// Class B is derived from A
 class B: A {
 int y;
 public:
     B(int,int );
 };
//  
 B::B(int x,int y):y(y),A(x) { //Initializer list must be used
     cout << "B's Constructor called: value of b"<<y<<endl;
 }
//  
 int main() {
     B obj(10,20);
     return 0;
//
 }
