#include "KdTree.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define h	(0.39)
#define radiusK	pow2(0.05)
#define radiusW	pow2(0.005)


void nlm(vector<Point*>& points){

	KdTree tree(points);

	/* points */
	for(uint p = 0; p < points.size(); p++){

		Point* point = points[p];
		cout << "processing point " << p << endl;

		color_t sum[3] = {0};
		color_t constant[3] = {0};

		vector<Point*> neighbours;
		tree.searchNeighboursRadius(point,&neighbours,radiusK);

		vector<Point*> littleNeighboursP;
		tree.searchNeighboursRadius(point,&littleNeighboursP,radiusW);

		/* neighbors */
		for(uint n = 0; n < neighbours.size(); n++){

			Point* neighbour = neighbours[n];

			color_t dist[3] = {0}; /* rgb distance */

			vector<Point*> littleNeighboursN;
			tree.searchNeighboursRadius(neighbour,&littleNeighboursN,radiusW);

			/* little neighbors */
			for(uint d = 0; d < MIN(littleNeighboursP.size(),littleNeighboursN.size()); d++){

				color_t val[3];
				for3ig(val,(littleNeighboursP[d]->colors[i] - littleNeighboursN[d]->colors[i]));
				for3masig(dist,val[i]*val[i]);
			}
			color_t weight[3];
			for3ig(weight,exp(-dist[i]/(h*h)));

			for3masig(sum,((neighbour->colors[i])*weight[i]));
			for3masig(constant,weight[i]);
		}
		for3ig(point->colors,((sum[i])/(constant[i])));
	}
}
void nlmSecuencial(){

	PointCloud cloud("/home/dernster/cloudE.pcd");

	cloud.simulateNoise(10);
	cloud.save("/home/dernster/cloudsavedNoisy.pcd");

	nlm(cloud.points);

	cloud.save("/home/dernster/cloudsaved.pcd");
}
void nlmParallel(int nodesQty){

	PointCloud cloud("/home/dernster/cloudE.pcd");
	cloud.simulateNoise(10);
	cloud.save("/home/dernster/cloudsavedNoisy.pcd");

	/* domain partition */
	vector<Point*>& points = cloud.points;

	/* sort points by axis=Y */
	int axis = 1;
	Point::setAxisComparator(axis);
	sort(points.begin(),points.end(),Point::lessThanFunc);

	int pointsQty = points.size();
	int partitionQty = (nodesQty);
	int partitionPointQty = pointsQty/partitionQty;
	coord_t minAxis = points[0]->coords[axis];
	coord_t maxAxis = points[pointsQty-1]->coords[axis];
	coord_t deltaPartition = (maxAxis - minAxis)/partitionQty;

	/* points assigned to partitions */
	vector<Point*>* partitionPoints = new vector<Point*>[partitionQty];
	vector<Point*>* partitionExtraPoints = new vector<Point*>[partitionQty];

	int partitionIndex = 0;
	coord_t currentStartAxisValue = minAxis;
	for(uint p = 0; p < points.size(); p++){

		Point* point = cloud.points[p];
		coord_t axisValue = point->coords[axis];

		//if (axisValue - currentStartAxisValue) <

		partitionPoints[partitionIndex].push_back(point);

		if (((p % partitionPointQty) == 0) && (partitionIndex != (partitionQty-1))){
			partitionIndex++;
		}
	}


	cloud.save("/home/dernster/cloudsaved.pcd");
}
int main()
{
	PointCloud cloud("/home/dernster/PCD/Site_56_college_division.pts",false);

	cloud.save("/home/dernster/Site_56_college_division.pcd");
    return 0;
}



