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

void BPQ::enqueue(Point* p){
	if (isFull())
		queue.pop();
	queue.push(p);
}

bool BPQ::isFull(){
	return (queue.size() == maxSize);
}

double BPQ::getMaxDistance(){
	return queue.top()->getDistanceToTestPoint();
}
