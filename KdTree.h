/*
 * KdTree.h
 *
 *  Created on: Feb 15, 2015
 *      Author: dernster
 */

#ifndef KDTREE_H_
#define KDTREE_H_

#include "PointCloud.h"
#include "BPQ.h"
#include <ios>
#include <iostream>
using namespace std;

class KdTree {
public:
	KdTree(PointCloud*);
	KdTree(vector<Point*> points,int depth = 0);
	void searchNeighbours(Point* testPoint, vector<Point*>* neighbours, int maxNeighbours,double maxRadius = 0);
	Point* searchClosestNeighbour(Point* testPoint, int depth = 0);
	friend ostream& operator<< (ostream &out, KdTree &tree);
	virtual ~KdTree();

	/* for test */
	void searchNeighboursTest(Point* testPoint, vector<Point*>* neighbours, int maxNeighbours,double maxRadius = 0);
private:
	void printTree(ostream &out,int depth = 0);
	void searchNeighboursProcedure(Point* testPoint,int maxNeighbours, BPQ* distanceQueue, int depth = 0);
	Point* point;
	KdTree *leftTree, *rightTree;

	/* for test */
	void searchNeighboursProcedureTest(Point* testPoint,int maxNeighbours, BPQ* distanceQueue, int depth = 0);
};

#endif /* KDTREE_H_ */
