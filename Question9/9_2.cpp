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
i
bool getAllPaths(int x,int y)
{
   vector<Point> path;
   vector<vector<Point> > vpath;
   map<Point,bool> mapPoints;
   getPath(3,3,vpath,mapPoints);
   vector<vector<Point> >::iterator vit;
   <vector<Point>::iterator it;
   for (vit=vpath.begin();vit!=vpath.end();vit++)
   for (it=(*vit).begin();it!=(*vit).end();it++)
            cout<<*it;
   cout<<endl;
}

bool getPath(int x,int y,vector<vector<Point>>& vpath,
        map<Point,bool>& cache)
{
    Point *p= new Point(x,y);
    map<Point,bool>::iterator mIter = cache.find(*p);
    vector<Point>::iterator it;
    vector<vector<Point> >::iterator vit;
    // if already visited this cell
    if(mIter!=cache.end())
    {
        return mIter->second; // *miter is a pair
    }
    if (x==0 && y ==0)
    {
        vpath.push_back(path)
        return true;
    }
    bool success = false;
    if(x >= 1 && isFree(x-1,y))
    { //Try right
        success = getPath(x-1,y,path,cache);//Free .. go right
    }
    if(success)
    {
        path.push_back(*p);
    }
    if(y>=1 && isFree(x,y-1))
    {// Try down
        success = getPath(x,y-1,path,cache);//Free .. go down
        cout<<endl;
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
    getAllPaths(3,3);
}
