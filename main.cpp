#include "KdTree.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

#define K	(32)
#define W	(8)
#define h	(0.39)

int main()
{
	PointCloud cloud("/home/dernster/cloudE.pcd");

	cloud.simulateNoise(10);
	cloud.save("/home/dernster/cloudsavedNoisy.pcd");


	KdTree tree(&cloud);

	/* points */
	for(uint p = 0; p < cloud.points.size(); p++){

		Point* point = cloud.points[p];
		cout << "processing point " << p << endl;

		color_t sum[3] = {0};
		color_t constant[3] = {0};

		vector<Point*> neighbours;
		tree.searchNeighbours(point,&neighbours,K);

		vector<Point*> littleNeighboursP;
		tree.searchNeighbours(point,&littleNeighboursP,W);

		/* neighbors */
		for(uint n = 0; n < neighbours.size(); n++){

			Point* neighbour = neighbours[n];

			color_t dist[3] = {0}; /* rgb distance */

			vector<Point*> littleNeighboursN;
			tree.searchNeighbours(neighbour,&littleNeighboursN,W);

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
	cloud.save("/home/dernster/cloudsaved.pcd");

    return 0;
}
