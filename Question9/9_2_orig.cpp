#include<iostream>
#include<vector>
#include<map>

using namespace std;
class Point
{
    private:
        int x,y;
        bool isFree;
    public:
        bool setFree()
        {
            return isFree;    
        }
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
bool isFree(Point &p,map<Point,bool>& cache)
{
    map<Point,bool>::iterator mIter = cache.find(*p);
    vector<Point>::iterator it;
    // if already visited this cell
    if(mIter!=cache.end())
    {
        if (p.getX()>0 && p.getY()>0 &&
    }
    
}

bool getPath(int x,int y,vector<Point>& path,
        map<Point,bool>& cache)
{
    Point *p= new Point(x,y);
    map<Point,bool>::iterator mIter = cache.find(*p);
    vector<Point>::iterator it;
    // if already visited this cell
    if(mIter!=cache.end())
    {
        return mIter->second; // *miter is a pair
    }
    if (x==0 && y ==0)
        return true;
    bool success = false;
    if(x >= 1 && isFree(x-1,y))
    { //Try right
        success = getPath(x-1,y,path,cache);//Free .. go right
    }
    if(y>=1 && isFree(x,y-1))
    {// Try down
        success = getPath(x,y-1,path,cache);//Free .. go down
    }
    if(success)
    {
        path.push_back(*p);
        for (it=path.begin();it!=path.end();it++)
            cout<<*it;
        cout<<endl;
    }
    cache[*p] = success;
    return success;
}

int main()
{
   vector<Point> vecPoints;
   map<Point,bool> mapPoints;
   cout<<"Path exists = "<<getPath(3,3,vecPoints,mapPoints)<<endl;
}
