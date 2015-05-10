#include<iostream>
#include<vector>
#include<map>

using namespace std;
class Point
{
    private:
        int x,y;
    public:
        Point(int x,int y)
        {
            this->x = x;
            this->y = y;
        }
        friend bool operator<(const Point& lhs,const Point& rhs);
        /* OR we can also keep */
        bool operator<(Point const& other)
        {
              return (this->x < other.x && this->y < other.y);
        }
        int getX() const { return x;}
        int getY() const { return y;}
        friend ostream& operator<<(ostream& os,const Point&p);
};

ostream& operator<<(ostream& os,const Point&p)
{
    return os<<"("<<p.getX()<<","<<p.getY()<<")";
}

bool operator<(const Point& lhs,const Point& rhs)
{
      return (lhs.x < rhs.x || lhs.y < rhs.y);
}
bool isFree(int x, int y)
{
    return 1;
}

bool getPath(int x,int y,vector<Point>& path,vector<vector<Point> >& vvpath,
        map<Point,bool>& cache)
{
    Point *p= new Point(x,y);
    map<Point,bool>::iterator mIter = cache.find(*p);
    // if already visited this cell
    if(mIter!=cache.end())
    {
        return cache[*p]; // *miter is a pair
    }
    if (x==0 && y ==0)
        return true;
    bool success = false;
    vector<Point>::iterator it;
    if(x >= 1 && isFree(x-1,y))
    { //Try right
        success = getPath(x-1,y,path,cache);//Free .. go right
        if (success)
            vvpath.push_back(path)
    }
    if(!success && y>=1 && isFree(x,y-1))
    {// Try down
        success = getPath(x,y-1,path,cache);//Free .. go down
        if (success)
            cout<<*p;
    }
    if(success)
    {
        path.push_back(*p);
    }
    cache[*p] = success;
    return success;
}

int main()
{
   vector<Point> vPoints;
   vector<vector<Point> > vvPoints;
   map<Point,bool> mapPoints;
   cout<<"Path exists = "<<getPath(3,3,vPoints,vvPoints,mapPoints)<<endl;
}
