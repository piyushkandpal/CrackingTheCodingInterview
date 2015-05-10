#include<iostream>
using namespace std;

int makeChange(int sum,int denom)
{
    int next_denom = 0;
    switch(denom)
    {
        case(100):
            next_denom = 75;
            break;
        case(75):
            next_denom = 50;
            break;
        case(50):
            next_denom = 25;
            break;
        case(25):
            next_denom = 10;
            break;
        case(10):
            next_denom = 5;
            break;
        case(5):
            next_denom = 1;
            break;
        case(1):
            return 1;
    }
    int ways=0;
    for(int i=0;i*denom <=sum; i++)
    {
        ways+=makeChange(sum-i*denom,next_denom);
    }
    return ways;
}
int main()
{
    int ways = makeChange(100,10);
    cout<<ways<<endl;
}


