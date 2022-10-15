//
// Created by Balazs on 10/12/2022.
//

#include "PointSet.h"

bool stat[M][M];

PointSet::PointSet(int n){

    this->n=n;
    points.reserve(n);
    distances.reserve(n*(n-1)/2);

    srand(time(nullptr));
    init();

    while(points.size() < n)
    {
        int x = rand() % M;
        int y = rand() % M;
        if (!stat[x][y])
        {
            points.emplace_back(x, y);
            stat[x][y]= true;
        }
    }
    computeDistances();
}

void PointSet::computeDistances() {
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            distances.push_back(points[i].distanceTo(points[j]));
        }
    }
}

void PointSet::printPoints() const {
    for (auto &i:points) {
        cout << "(" << i.getX() << "," << i.getY() << ")" << endl;
    }
}

int PointSet::numDistances() const {
    return n*(n-1)/2;
}

void PointSet::printDistances() const {
    for (auto &i:distances) {
        cout << i;
    }
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(), distances.end());
}

bool cmpX(const Point &p1, const Point &p2) {
    return p1.getX() < p2.getX();
}

bool cmpY(const Point &p1, const Point &p2) {
    return p1.getY() < p2.getY();
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), cmpX);
}

void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), cmpY);
}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

int PointSet::numDistinctDistances() {
    sortDistances();
    return unique(distances.begin(), distances.end()) - distances.begin();
}

void init(){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            stat[i][j] = false;
        }
    }
}