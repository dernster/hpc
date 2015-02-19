/*
 * BPQ.h
 *
 *  Created on: Feb 19, 2015
 *      Author: dernster
 */

#ifndef BPQ_H_
#define BPQ_H_

#include "Point.h"
#include <queue>
using namespace std;

class BPQ {
public:
	BPQ(int maxSize);
	virtual ~BPQ();

	void enqueue(Point*);
	bool isFull();
	double getMaxDistance();

	struct distanceComparator{
		inline bool operator()(const Point* a,const Point* b) const{
			return (a->getDistanceToTestPoint() < b->getDistanceToTestPoint());
		};
	};
private:
	priority_queue<Point*, vector<Point*>,BPQ::distanceComparator> queue;
	unsigned int maxSize;

};
#endif /* BPQ_H_ */
