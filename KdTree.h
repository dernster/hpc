/*
 * KdTree.h
 *
 *  Created on: Feb 15, 2015
 *      Author: dernster
 */

#ifndef KDTREE_H_
#define KDTREE_H_

#include "PointCloud.h"
#include <ios>
#include <iostream>
using namespace std;

class KdTree {
public:
	KdTree(PointCloud*);
	KdTree(vector<Point*> points,int depth = 0);
	void searchNeighbours(Point* point,double squaredDistance,vector<Point*>* neighbours);
	friend ostream& operator<< (ostream &out, KdTree &tree);
	virtual ~KdTree();
private:
	void printTree(ostream &out,int depth = 0);
	Point* point;
	KdTree *leftTree, *rightTree;
};

#endif /* KDTREE_H_ */
