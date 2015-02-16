/*
 * KdTree.cpp
 *
 *  Created on: Feb 15, 2015
 *      Author: dernster
 */

#include "KdTree.h"
#include <algorithm>
#include "KdNode.h"

KdTree::KdTree(PointCloud* cloud){
	KdTreeConstructor(cloud->points,0);
}

void KdTree::KdTreeConstructor(vector<Point> points, int depth){
	int axis = depth % 3;
	Point::setAxisComparator(axis);
	std::sort(points.begin(),points.end(),Point::lessThanFunc);
	int median = points.size()/2;

	root = new KdNode();
	root->setPoint(&points[median]);

}

KdTree::~KdTree() {
	// TODO Auto-generated destructor stub
}

