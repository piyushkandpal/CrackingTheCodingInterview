#include<iostream>
int main()
{
    int mat[2][3] = {{1,2,3},{4,5,6}};
    std::cout<<"mat[1][1] = "<<mat[1][1]<<" : "<<*(*((mat+1*3)+1))<<std::endl;
}
