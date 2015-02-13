/*
 * Point.h
 *
 *  Created on: Feb 1, 2015
 *      Author: dernster
 */

#ifndef POINT_H_
#define POINT_H_

#include "types.h"

class Point{
public:
	Point();
	Point::Point(coord_t x, coord_t y, coord_t z, color_t r, color_t g, color_t b);
	Point& operator=(const Point &);
	Point& Point(const Point &);
	virtual ~Point();
	coord_t x,y,z;
	color_t r,g,b;
};

#endif /* POINT_H_ */
