//
// Created by Balázs on 9/28/2022.
//

#ifndef LABOR2_UTIL_H
#define LABOR2_UTIL_H

#include "Point.h"

double distance(const Point &a, const Point &b);

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d);

void testIsSquare(const char *filename);

bool isSame(const Point &, const Point &);

Point *createArray(int numPoints);

void printArray(Point *, int);

pair<Point, Point> closestPoints(Point *, int);

pair<Point, Point> farthestPoints(Point *, int);

void sortPoints(Point *, int);

Point *farthestPointsFromOrigin(Point *, int);

void deletePoints(Point *);

int cmpFunc(const Point &, const Point &);

float closest(Point P[], int n);

float closestUtil(Point[], Point[], int);

float stripClosest(Point, int, float);

float min(float, float);

float dist(Point, Point);

int compareY(const void *, const void *);

int compareX(const void *, const void *);

#endif //LABOR2_UTIL_H
