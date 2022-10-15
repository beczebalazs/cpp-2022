//
// Created by Balazs on 10/12/2022.
//

#ifndef MAIN_02_CPP_POINT_H
#define MAIN_02_CPP_POINT_H
#define M 2000

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Point{
private:
    int x, y;
    static int counter;
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    double distanceTo(const Point& point)const ;
    Point(const Point&);
    ~Point();
    static int getCounter() {return counter;};
};

#endif //MAIN_02_CPP_POINT_H
