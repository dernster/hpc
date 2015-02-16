/*
 * KdNode.cpp
 *
 *  Created on: Feb 15, 2015
 *      Author: dernster
 */

#include "KdNode.h"

KdNode::KdNode() {
	// TODO Auto-generated constructor stub

}

KdNode::~KdNode() {
	// TODO Auto-generated destructor stub
}

const KdTree* KdNode::getLeftTree() const {
	return leftTree;
}

void KdNode::setLeftTree(KdTree* leftTree) {
	this->leftTree = leftTree;
}

const Point* KdNode::getPoint() const {
	return point;
}

void KdNode::setPoint(Point* point) {
	this->point = point;
}

const KdTree* KdNode::getRightTree() const {
	return rightTree;
}

void KdNode::setRightTree(KdTree* rightTree) {
	this->rightTree = rightTree;
}
