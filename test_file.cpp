#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    ifstream readfile;
    ofstream writefile;
    string filename = "myfile.txt";
    readfile.open( filename.c_str() );
    if( readfile )
    {
            readfile.close();
    }
    else
    {
            writefile.open( filename.c_str() );
            writefile << " write some data " << endl;
        writefile.close();
    }
    return 0;
}
