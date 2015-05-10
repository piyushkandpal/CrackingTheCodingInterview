#include<iostream>
#include<unordered_map>
using namespace std;

Line findBestLine(GraphPoint[] points) 
{
 Line bestLine = null;
 int bestCount = 0;
 unordered_map<Double, vector<Line>> linesBySlope = new unordered_map<Double, vector<Line>>();

 for (int i = 0; i < points.length; i++)
 {
     for (int j = i + 1; j < points.length; j++) 
    {
    Line line = new Line(points[i], points[j]);
    insertLine(linesBySlope, line);
    int count = countEquivalentLines(linesBySlope, line);
         if (count > bestCount) 
        {
                     bestLine = line;
                     bestCount = count;
        }
    }
    
    } 
    return bestLine;
 }

 int countEquivalentLines(vector<Line> lines, Line line) 
{
    if (lines == null) 
        return 0;
    int count = 0;
    for (vector<Line>::iterator parallelLine=lines.begin();parallelLine!=lines.end();parallelLine++) 
    {
     if (parallelLine.isEquivalent(line)) 
        count++;
    }
    return count;
}

 int countEquivLines(unordered_map<double,vector<Line>> linesBySlope, Line line)
 {
     double key = Line.floorToNearestEpsilon(line.slope);
     double eps = Line.epsilon;
     int count = countEquivalentLines((linesBySlope.find(key))->second, line) +
     countEquivalentLines((linesBySlope.find(key - eps))-> second, line) +
     countEquivalentLines((linesBySlope.find(key + eps))->second, line);
     return count;
 }

 void insertLine(unordered_map<double,vector<Line>> linesBySlope,Line line)
 {
    vector<Line> lines = null;
    double key = Line.floorToNearestEpsilon(line.slope);
    if (linesBySlope.find(key)==linesBySlope.end())
     {
        lines = new ArrayList<Line>();
         linesBySlope[key] =lines;
     }
     else 
    {
         lines = linesBySlope.find(key);
     }
     lines.add(line);
 }

 class Line
 {
    static double epsilon = .8001;
      double slope, intercept;
      Line(GraphPoint p, GraphPoint q)
     {
         if (Math.abs(p.x - q.x) > epsilon)
         { // if x's are different
             slope = (p.y - q.y) / (p.x - q.x); // compute slope
             intercept = p.y - slope * p.x; // y intercept from y=mx+b
         } 
        else 
        {
             infinite_slope = true;
             intercept = p.x; // x-intercept, since slope is infinite
         }
     }

    private :
            boolean infinite_slope = false;
    public :
     static double floorToNearestEpsilon(double d) 
     {
        int r = (int) (d / epsilon);
        return ((double) r) * epsilon;
     }
     public boolean isEquivalent(double a, double b) 
     {
         return (Math.abs(a - b) < epsilon);
     }
     public boolean isEquivalent(Object o) 
     {
         Line 1 = (Line) o;
         if (isEquivalent(l.slope, slope) && isEquivalent(l.intercept, intercept) &&
         (infinite_slope == l.infinite_slope))
         {
        return true;
        }
         return false;
     }
};

static double Line::epsilon = .8001;
static double Line::floorToNearestEpsilon(double d);

int main()
{
        
    Line line;
    return 1;
}
