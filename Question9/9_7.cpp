#include<iostream>
#include<vector>
using namespace std;
enum Color{red=1,blue,green};

bool paintFill(vector<vector<Color> >& screen, int x, int y,Color ocolor, Color ncolor)
{
    if( x<0 || x>= screen.size() || y<0 || y>= screen[0].size())
        return false;
    if(screen[x][y] == ocolor)
    {
        screen[x][y]=ncolor;
        paintFill(screen,x-1,y,ocolor,ncolor);
        paintFill(screen,x,y-1,ocolor,ncolor);
        paintFill(screen,x+1,y,ocolor,ncolor);
        paintFill(screen,x,y+1,ocolor,ncolor);
    }
    return true;
}

bool paintFill(vector<vector<Color> >& screen, int x, int y, Color ncolor)
{
    if(screen[x][y] == ncolor)
        return false;
    return paintFill(screen,x,y,screen[x][y],ncolor);
}

int main()
{
    vector<vector<Color> >screen;
    int row=0,col=0;
    vector<Color> vc;
    vc.push_back(red);
    vc.push_back(blue);
    vc.push_back(red);
    screen.push_back(vc);
    vc.clear();
    vc.push_back(green);
    vc.push_back(blue);
    vc.push_back(green);
    screen.push_back(vc);
    vc.clear();
    vc.push_back(red);
    vc.push_back(red);
    vc.push_back(red);
    screen.push_back(vc);
    for (int i =0;i<3;i++)
    {
        for(int j =0;j<3;j++)
            cout<<" "<<screen[i][j];
        cout<<endl;
    }
    paintFill(screen,1,1,red);
    for (int i =0;i<3;i++)
    {
        for(int j =0;j<3;j++)
            cout<<" "<<screen[i][j];
        cout<<endl;
    }
}

