#include "KdTree.h"
#include <iostream>
#include <math.h>
using namespace std;

bool vectorEquals(const vector<Point*>& a, const vector<Point*>& b){
	if (a.size() != b.size())
		return false;

	for(unsigned int i = 0; i < a.size(); i++){
		if (*a[i] != *b[i])
			return false;
	}

	return true;
}

void printVector(const vector<Point*>& a){
	for(unsigned int i = 0; i < a.size(); i++){
		cout << *a[i] << endl;
	}
}

#define K	(4)
#define W	(2)
#define h	(0.2)

int main()
{
	PointCloud cloud("/home/dernster/cloudE.pcd");

	cloud.save("/home/dernster/cloudsaved.pcd");

	return 0;

	KdTree tree(&cloud);

	for(uint p = 0; p < cloud.points.size(); p++){

		cout << "processing point " << p << endl;

		Point* point = cloud.points[p];
		double sum[3] = {0};
		double constant[3] = {0};

		vector<Point*> neighbours;
		tree.searchNeighbours(point,&neighbours,K);

		for(uint n = 0; n < neighbours.size(); n++){

			Point* neighbour = neighbours[n];

			double dist[3] = {0}; /* rgb distance */

			vector<Point*> littleNeighboursP, littleNeighboursN;
			tree.searchNeighbours(point,&littleNeighboursP,W);
			tree.searchNeighbours(neighbour,&littleNeighboursN,W);

			for(uint d = 0; d < MIN(littleNeighboursP.size(),littleNeighboursN.size()); d++){
				double val[3];

				for3ig(val,(littleNeighboursP[d]->colors[i] - littleNeighboursN[d]->colors[i]));

				for3masig(dist,val[i]*val[i]);
			}

			double weight[3];
			for3ig(weight,exp(-dist[i]/(h*h)));


			for3masig(sum,(neighbour->colors[i]*weight[i]));
			for3masig(constant,weight[i]);


		}

		cout << "s " << sum[1] << endl;
		for3ig(point->colors,((sum[i])/(constant[i])))

	}

	cloud.save("/home/dernster/cloudsaved.pcd");

    return 0;
}
