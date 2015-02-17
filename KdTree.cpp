/*
 * KdTree.cpp
 *
 *  Created on: Feb 15, 2015
 *      Author: dernster
 */

#include "KdTree.h"
#include <algorithm>
#include "KdNode.h"

KdTree::KdTree(PointCloud* cloud) : KdTree(cloud->points,0){
}

KdTree::KdTree(vector<Point*> points,int depth){

	int axis = depth % 3;
	Point::setAxisComparator(axis);
	std::sort(points.begin(),points.end(),Point::lessThanFunc);
	int median = (points.size()-1)/2;

	point = points[median];
	leftTree = rightTree = NULL;

	vector<Point*> toLeft(points.begin(),points.begin()+median);
	vector<Point*> toRight(points.begin()+median+1,points.end());

	if (toLeft.size() > 0)
		leftTree = new KdTree(toLeft,depth+1);

	if (toRight.size() > 0)
		rightTree = new KdTree(toRight,depth+1);
}

void KdTree::searchNeighbours(Point* srcPoint,double maxSquaredDistance,vector<Point*>* neighbours){

	if (Point::squaredDistance(*srcPoint,*point) < maxSquaredDistance){
		neighbours->push_back(point);
	}else{

	}
}

KdTree::~KdTree() {
	// TODO Auto-generated destructor stub
}

void KdTree::printTree(ostream &out,int depth){

	for(int i = 0; i < depth; i++)
		out << "  ";

	out << *this->point << endl;

	for(int i = 0; i < depth; i++)
		out << "  ";

	if (this->leftTree){
		out << "Left :" << endl;
		this->leftTree->printTree(out,depth+1);
	}
	else
		out << "Left : -\n";

	for(int i = 0; i < depth; i++)
		out << "  ";

	if (this->rightTree){
		out << "Right:" << endl;
		this->rightTree->printTree(out,depth+1);
	}else
		out << "Right: -\n";
}

ostream& operator<< (ostream &out, KdTree &tree)
{
	out << "<< KdTree >>\n";
	tree.printTree(out);
    return out;
}

