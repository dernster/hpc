/*
 * KdTree.h
 *
 *  Created on: Feb 15, 2015
 *      Author: dernster
 */

#ifndef KDTREE_H_
#define KDTREE_H_

#include "PointCloud.h"
class KdNode; /* to break dependency */

class KdTree {
public:
	KdTree(PointCloud*);
	virtual ~KdTree();
private:
	void KdTreeConstructor(vector<Point> points, int depth);
	KdNode* root;
};

#endif /* KDTREE_H_ */
