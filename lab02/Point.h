//
// Created by Balázs on 9/28/2022.
//

// Point.h - interfész
#ifndef LABOR2_POINT_H
#define LABOR2_POINT_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <bits/stdc++.h>
#include <random>

using namespace std;


class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0);

    int getX() const;

    int getY() const;

    void print() const;
};
struct tempStruct{
    Point point;
    double dist;
};

struct CustomCompare
{
    bool operator()(const tempStruct& lhs, const tempStruct& rhs)
    {
        return lhs.dist < rhs.dist;
    }
};

#endif //LABOR2_POINT_H
