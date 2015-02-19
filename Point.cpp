/*
 * Point.cpp
 *
 *  Created on: Feb 1, 2015
 *      Author: dernster
 */

#include "Point.h"

int Point::axisComparator = 0;

Point::Point() {
}

Point::Point(coord_t x, coord_t y, coord_t z, color_t r, color_t g, color_t b) {
	this->b = b;
	this->g = g;
	this->r = r;
	this->x = x;
	this->y = y;
	this->z = z;
}

Point::~Point() {
}

Point& Point::operator=(const Point & p){
	this->b = p.b;
	this->g = p.g;
	this->r = p.r;
	this->x = p.x;
	this->y = p.y;
	this->z = p.z;
	return (*this);
}

Point::Point(const Point & p){
	this->b = p.b;
	this->g = p.g;
	this->r = p.r;
	this->x = p.x;
	this->y = p.y;
	this->z = p.z;
}

bool Point::operator==(const Point& x){
	return ((this->x == x.x) && (this->y == x.y) && (this->z == x.z));
}

bool Point::operator!=(const Point& x){
	return (!(*this == x));
}

bool Point::lessThan(const Point& p, int axis) const{
	return (this->coords[axis] < p.coords[axis]);
}

void Point::setAxisComparator(int axis){
	Point::axisComparator = axis;
}

ostream& operator<< (ostream &out, Point &cPoint)
{
	out << "Point: ";
    out << "xyz(" << cPoint.x << "," << cPoint.y << "," << cPoint.z << ") | "
    	<< "rgb(" << cPoint.r << "," << cPoint.g << "," << cPoint.b << ")";
    return out;
}

double Point::squaredDistance(const Point& a ,const Point& b){
	return pow2(a.x - b.x) + pow2(a.y - b.y) + pow2(a.z - b.z);
}

double Point::getDistanceToTestPoint() const {
	return distanceToTestPoint;
}

void Point::setDistanceToTestPoint(double distanceToTestPoint) {
	this->distanceToTestPoint = distanceToTestPoint;
}
