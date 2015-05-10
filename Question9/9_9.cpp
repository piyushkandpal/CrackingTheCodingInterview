#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

int GRID_SIZE=8;

bool checkValid(vector<int> columns,int row1,int column1)
{
    for(int row2=0;row2<row1;row2++)
    {
        int column2 = columns[row2];
        if(column1 == column2)
            return false;
        int columnDistance = abs(column1-column2);
        int rowDistance = abs(row1-row2);
        if (columnDistance == rowDistance)
            return false;
    }
    return true;
}

void placeQueen(int row,vector<int>& columns,vector<vector<int> >& results)
{
    if(row == GRID_SIZE)
    {
        results.push_back(columns);
    }
    else
    {
        for(int col=0;col< GRID_SIZE;col++)
        {
            if(checkValid(columns, row, col))
            {
                columns[row] = col;
                placeQueen(row+1,columns,results);
            }
        }
    }
}

int main()
{
    vector<int> columns(8);
    vector<vector<int> > results;
    placeQueen(0,columns,results);
    for(int i =0;i<8;i++)
    {
        for(int j =0;j<8;j++)
        {
            cout<<" "<<results[i][j];
        }
        cout<<endl;
    }
}
