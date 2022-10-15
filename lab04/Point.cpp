//
// Created by Balazs on 10/12/2022.
//

#include "Point.h"

int Point::counter{0};

Point::Point(int x, int y) {
    counter++;
    if (x>=0 && x<M && y>=0 && y<M)
    {
        this->x=x;
        this->y=y;
    }
    else
    {
        this->x=0;
        this->y=0;
    }
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

double Point::distanceTo(const Point &point) const {
    return sqrt((this->getX() - point.getX()) * (this->getX() - point.getX()) +
                ((this->getY() - point.getY()) * (this->getY() - point.getY())));

}

Point::~Point() {
    counter--;
}

Point::Point(const Point &what) {
    this->x=what.x;
    this->y=what.y;
}
