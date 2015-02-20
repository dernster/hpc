/*
 * BPQ.cpp
 *
 *  Created on: Feb 19, 2015
 *      Author: dernster
 */

#include "BPQ.h"

BPQ::BPQ(int maxSize) {
	this->maxSize = maxSize;
}

BPQ::~BPQ() {
	// TODO Auto-generated destructor stub
}

void BPQ::enqueue(Point* p,double distance){
	if (isFull()){
		if (queue.top()->getDistanceToTestPoint() > distance){
			queue.pop();
			p->setDistanceToTestPoint(distance);
			queue.push(p);
		}
	}else{
		p->setDistanceToTestPoint(distance);
		queue.push(p);
	}
}

bool BPQ::isFull(){
	return (queue.size() == maxSize);
}

double BPQ::getMaxDistance(){
	return queue.top()->getDistanceToTestPoint();
}

int BPQ::size(){
	return queue.size();
}

Point* BPQ::pop(){
	Point* p = queue.top();
	queue.pop();
	return p;
}
