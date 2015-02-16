/*
 * KdNode.h
 *
 *  Created on: Feb 15, 2015
 *      Author: dernster
 */

#ifndef KDTREE_KDNODE_H_
#define KDTREE_KDNODE_H_

#include "Point.h"
#include "KdTree.h"

class KdNode {
public:
	KdNode();
	KdNode(Point*);
	virtual ~KdNode();
	const KdTree* getLeftTree() const;
	void setLeftTree(KdTree* leftTree);
	const Point* getPoint() const;
	void setPoint(Point* point);
	const KdTree* getRightTree() const;
	void setRightTree(KdTree* rightTree);

private:
	Point* point;
	KdTree *leftTree, *rightTree;


};

#endif /* KDTREE_KDNODE_H_ */
