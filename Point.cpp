/*
 * Point.cpp
 *
 *  Created on: Feb 1, 2015
 *      Author: dernster
 */

#include "Point.h"

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

Point& Point::Point(const Point & p){
	this->b = p.b;
	this->g = p.g;
	this->r = p.r;
	this->x = p.x;
	this->y = p.y;
	this->z = p.z;
	return (*this);
}
