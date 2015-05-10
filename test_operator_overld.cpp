#include<iostream>
#include<vector>
using namespace std;
 
class Complex {
    private:
            int real, imag;
    public:
            Complex(int r = 0, int i =0)  {real = r;   imag = i;}
            // This is automatically called when '+' is used with
            // between two Complex objects
            Complex operator + (Complex const &obj) 
            {
                 Complex res;
                 res.real = real + obj.real;
                 res.imag = imag + obj.imag;
                 return res;
            }
            void print() 
            { 
                cout << real << " + i" << imag << endl; 
            }
            /* This also works*/
            bool operator<(const Complex& obj)
            {
                cout<<"overload 1 called"<<endl;
                return (this->real < obj.real && this->imag < obj.imag);
            }
            
            // we can chose either of operator overload .. but external sort 
            // requires external overloaded < operator
            friend bool operator<(Complex const& lhs,Complex const& rhs);
};

bool operator<(Complex const& lhs,Complex const& rhs)
{
    cout<<"overload 2 called"<<endl;
    return (lhs.real < rhs.real && lhs.imag < rhs.imag);
}

int main()
{
        Complex c1(10, 5), c2(2, 4);
        vector<Complex> v;
        Complex c3 = c1 + c2; // An example call to "operator+"
        c3.print();
        bool res = c2 < c1;
        cout<<res<<endl;
        v.push_back(c1);
        v.push_back(c2);
        v.front().print();
        v.back().print();
        //sorting requiresless than  operator overload which should get printed
        sort(v.begin(),v.end());
        v.front().print();
        v.back().print();
}

