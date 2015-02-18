/*
 * Point.h
 *
 *  Created on: Feb 1, 2015
 *      Author: dernster
 */

#ifndef POINT_H_
#define POINT_H_

#include "types.h"
#include <ios>
#include <iostream>
using namespace std;

class Point{
public:
	Point();
	Point(coord_t x, coord_t y, coord_t z, color_t r = 0, color_t g = 0, color_t b = 0);
	Point& operator=(const Point &);
	Point(const Point &);
	bool lessThan(const Point&, int axis) const;
	bool operator==(const Point&);
	bool operator!=(const Point&);
	friend ostream& operator<< (ostream &out, Point &cPoint);
	virtual ~Point();

	static double squaredDistance(const Point&,const Point&);
	static void setAxisComparator(int axis);
	static struct{
		inline bool operator()(const Point* a,const Point* b){
			return a->lessThan(*b,Point::axisComparator);
		}
	} lessThanFunc;

	union{
		struct{
			coord_t x;
			coord_t y;
			coord_t z;
		};
		coord_t coords[3];
	};

	union{
		struct{
			color_t r;
			color_t g;
			color_t b;
		};
		color_t colors[3];
	};

private:
	static int axisComparator;
};

#endif /* POINT_H_ */
