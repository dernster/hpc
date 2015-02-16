/*
 * PointCloud.h
 *
 *  Created on: Feb 1, 2015
 *      Author: dernster
 */

#ifndef POINTCLOUD_H_
#define POINTCLOUD_H_

#include <list>
#include <vector>
#include "Point.h"
using namespace std;

class PointCloud {
public:
	PointCloud();
	PointCloud(vector<Point>);
	virtual ~PointCloud();
	vector<Point> points;
};

#endif /* POINTCLOUD_H_ */
