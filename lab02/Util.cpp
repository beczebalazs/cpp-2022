//
// Created by Balázs on 9/28/2022.
//
#include "util.h"

double distance(const Point &a, const Point &b) {
    sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
    return sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {

    if (isSame(a, b) || isSame(a, c) || isSame(a, d) || isSame(b, c) || isSame(b, d) || isSame(c, d))
        return false;
    unordered_set<double> distances;
    distances.insert(distance(a, b));
    distances.insert(distance(a, c));
    distances.insert(distance(a, d));
    distances.insert(distance(b, c));
    distances.insert(distance(b, d));
    distances.insert(distance(c, d));
    return distances.size() == 2;
}

void testIsSquare(const char *filename) {
    ifstream f(filename);
    int x, y;
    Point points[4];
    while (!f.eof()) {
        for (auto &point: points) {
            f >> x;
            f >> y;
            point = Point(x, y);
        }
        printf("(%d, %d), (%d, %d), (%d, %d), (%d, %d) ", points[0].getX(), points[0].getY(),
               points[1].getX(), points[1].getY(), points[2].getX(), points[2].getY(), points[3].getX(),
               points[3].getY());
        if (isSquare(points[0], points[1], points[2], points[3]))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    f.close();
}

bool isSame(const Point &a, const Point &b) {
    return (a.getY() == b.getY() && a.getX() == b.getX());
}

Point* createArray(int numPoints)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(0, 2000);
    Point * points = new Point[numPoints];
    for (int i=0;i<numPoints;i++)
    {
        int x=(int)dist(mt);
        int y=(int)dist(mt);
        points[i]=Point(x, y);
    }
    return points;
}

void printArray(Point* points, int numPoints)
{
    for (int i=0;i<numPoints;i++)
    {
        points[i].print();
    }
}

pair<Point, Point> closestPoints(Point* points, int numPoints)
{
    double d=INT_MAX;
    pair<Point, Point> res;
    for (int i=0;i<numPoints-1;i++)
    {
        for (int j=0;j<numPoints;j++)
        {
            double temp=distance(points[i], points[j]);
            if (temp < d)
            {
                d=temp;
                res.first=points[i];
                res.second=points[j];
            }
        }
    }
    return res;
}

pair<Point, Point> farthestPoints(Point* points, int numPoints)
{
    double d=0;
    pair<Point, Point> res;
    for (int i=0;i<numPoints-1;i++)
    {
        for (int j=0;j<numPoints;j++)
        {
            double temp=distance(points[i], points[j]);
            if (temp > d)
            {
                d=temp;
                res.first=points[i];
                res.second=points[j];
            }
        }
    }
    return res;
}

void sortPoints(Point* points, int numPoints)
{
    sort(points, points+numPoints, cmpFunc);
    printArray(points, numPoints);
}

Point* farthestPointsFromOrigin(Point* points, int numPoints)
{
    Point* res= new Point[10];
    priority_queue<tempStruct, vector<tempStruct>, CustomCompare> q;
    for (int i=0;i<numPoints;i++)
    {
        double d= distance(points[i], Point(0, 0));
        if (q.size()<10)
        {
            tempStruct temp;
            temp.dist=d;
            temp.point=points[i];
            q.push(temp);
        }
        if (q.size()>9)
        {
            if (d>q.top().dist)
            {
                tempStruct temp;
                temp.dist=d;
                temp.point=points[i];
                q.push(temp);
            }
        }
    }
    for (int i=0;i<10;i++)
    {
        res[i]=q.top().point;
        q.pop();
    }
    return res;
}

void deletePoints(Point* points)
{
    delete[] points;
}

int cmpFunc(const Point& a, const Point& b)
{
    return a.getX() < b.getX();
}

int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->getX() - p2->getX());
}

int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->getY()- p2->getY());
}

float dist(Point p1, Point p2)
{
    return sqrt( (p1.getX() - p2.getX())*(p1.getX() - p2.getX()) +
                 (p1.getY() - p2.getY())*(p1.getY() - p2.getY())
    );
}

float bruteForce(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

float min(float x, float y)
{
    return (x < y)? x : y;
}

float stripClosest(Point strip[], int size, float d)
{
    float min = d;

    qsort(strip, size, sizeof(Point), compareY);

    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].getY() - strip[i].getY()) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}

float closestUtil(Point P[], int n)
{
    if (n <= 3)
        return bruteForce(P, n);

    int mid = n/2;
    Point midPoint = P[mid];

    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n - mid);

    float d = min(dl, dr);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (fabs(P[i].getX() - midPoint.getX()) < d)
            strip[j] = P[i], j++;

    return min(d, stripClosest(strip, j, d) );
}

float closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);

    return closestUtil(P, n);
}